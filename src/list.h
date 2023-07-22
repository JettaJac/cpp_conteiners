#include <iostream>
// #include <string>
using namespace std;
// #define size_type size_t


namespace s21{

template<typename T>
class List {

    public:
     // member type
    using value_type = T;  // defines the type of an element (T is template parameter)
    using reference = T&; // defines the type of the reference to an element
    using const_reference = const T&; // defines the type of the constant reference
    using size_type = std::size_t; // size_t defines the type of the container size (standard type is size_t)

    public:
        List();              // default constructor, creates empty list 
        List(size_type n);   // parameterized constructor, creates the list of size n
        List(std::initializer_list<value_type> const &items);
        List(const List &l); // copy constructor
        List(List &&l);      // move constructor
        ~List();             // destructor
        List<T> operator=(List const &l);  // assignment operator overload for moving object
        List<T> operator=(List &&l); 
        
        void clear();  // clears the contents

        void push_back(const_reference value); // adds an element to the end
        void pop_back(); // removes the last element 
        void push_front(const_reference value); // adds an element to the head
        void pop_front(); // removes the first element
        void swap(List& other);
        void reverse();

        void unique(); // removes consecutive duplicate elements


        // void push_back(T value);
        size_type size() {return size_l;}; // returns the number of elements
        // size_type max_size(allocator.max_size());
        T& operator[](const int index);

        const_reference front() const noexcept {return head->value;}; //access the first element
        const_reference back() const noexcept {return tail->value;};  // access the last element

        // iterator begin();
        
        
        void insert(T value, int index);
        void removeAt(int index);
        
        bool empty();  // checks whether the container is empty

        void  show();            

    // using value_type = T;
   
        template<typename value_type>
        class Node 
        {
            public:
                Node *pNext;
                Node *pPrev;
                T value;
                Node(T value = T(), Node *pNext = nullptr){
                    this->value = value;
                    this->pNext = pNext;
                    this->pPrev = pPrev;
                    // cout << "в классе node" << endl;
                }
        };
        size_t size_l;
        Node<value_type> *head;
        Node<value_type> *tail;
     private:
};

template<typename T>
List<T>::List()
{
    cout << "Create list " << this << endl;
    size_l = 0;

    // Node<value_type> *zero; // Заглужка,  0 элемент
    // head = zero;
    // tail = zero;

    head = nullptr;
    tail= nullptr; 
}

template <typename T>
List<T>::List(size_type n) 
{   cout << "List_n" << endl;
    head = nullptr;
    tail= nullptr; 
    size_l = 0;
    
    for(size_type i = 0; i < n; i++){
        push_back(1);
    }
    // cout << "Create list _N_" << endl;
    
}

template <typename value_type>
List<value_type>::List(std::initializer_list<value_type> const &items)              : List()
{       
        cout << "Initiaz" << endl;
        for (auto element : items)
        {
            push_back(element);
        }
        
}

template <typename T>
List<T>::List(const List &l) : List()
{
    cout << "Copy function " << this << endl;
    // List<value_type>::List(std::initializer_list<value_type> const &List):List()
    // int s;
    // s = size;
    clear();
    // List<T> tmp();
    Node<value_type> *current = l.head;
    // new Node<value_type>(*head);
    // current->pNext = nullptr;
    for(int i = 0; i < l.size_l; i++)
    {
        push_back(current->value);
        current = current->pNext;
        // tmp->size_l = 7;
    }
    

    // for (auto element : l && l != nullptr_t);
    //     {
    //         push_back(element);
    //     }
// return tmp;

// template <typename value_type>
// List<value_type>& List<value_type>::operator=(const List& l) {
//   clear();
//   iterator currentPtr = l.begin();
//   while (currentPtr != l.end()) {
//     this->push_back(currentPtr.getIterPointer()->data);
//     currentPtr++;
//   }
//   return *this;
// }


}

template <typename T>
List<T>::List(List &&l) : List()
{   
    cout << "Move function" << endl; 
 
    operator=(l);

    // swap(this, l);

    //   clear();
    head = l.head;
    tail = l.tail;
    size_l = l.size_l;
    l.head = NULL;
    l.tail = NULL;
    l.size_l = 0;
}

template<typename T>
List<T>::~List()
{
    // cout << "Delete list " << this << endl;
    clear();
    // cout << "Delete list_finish " << this << endl;
}

template <typename T>
inline List<T> List<T>::operator=(List const &l)
{
    cout << "Operator Copy " << this << endl;
    // cout <<  " h "<< endl;
    clear();
    cout <<  " h "<< endl;
    // List<T> tmp();
    Node<value_type> *current = l.head;
    // new Node<value_type>(*head);
    // current->pNext = nullptr;
    // head = l.head;
    for(int i = 0; i < l.size_l; i++)
    {
        push_back(current->value);
        current = current->pNext;
        // tmp->size_l = 7;        
    }
    // cout <<  " y " << endl;

    // for (const auto& element : l) { //  возможно с интералами будет работать)
        
    //     cout << element << " x ";
    //     push_back(current->value);
    // }
    

    // head = l.head;
    return *this;
}

template <typename T>
List<T> List<T>::operator=(List &&l)
{
    cout << "Operator Move " << this << endl;
    clear();
    head = l.head;
    tail = l.tail;
    size_l = l.size_l;
    l.head = NULL;
    l.tail = NULL;
    l.size_l = 0;
    // move(l);
    // cout << "SIZE_2: " << size_l << endl;
    return *this;
}

template <typename T>
void List<T>::clear()
{
    // cout << "Clear list" << endl;
    // cout << "SIZE: " << size_l << endl;
    while (size_l)
    {
        // cout << "1" << endl;
        pop_front();
    }
    cout << "Clear list finish " << this << endl; 
}

template <typename T>
void List<T>::pop_front()
{
    // cout << "Delete Node" << endl;
    Node<value_type> *tmp = head;
    head = head->pNext;    
    delete tmp;
    size_l--;
}

template <typename T>
void List<T>::swap(List &other)
{
    // std::swap(head, l.head);
    // std::swap(tail, l.tail);
    // std::swap(size_l, l.size_l);

    cout << "SWAP " << endl;
    Node<value_type> *cur_head = new Node<value_type>(1);
    Node<value_type> *cur_tail = new Node<value_type>(1);
    cur_head = head;
    cur_tail = tail;
    size_t t = size_l;

    head = other.head;
    tail = other.tail;
    size_l = other.size_l;

    other.head = cur_head;
    other.tail = cur_tail;
    other.size_l = t;
}

template <typename T>
inline void List<T>::reverse()
{


Node<T> *tmp = tail;
for {
// head = tmp.head./p   
pNext = tmp.pPrev;
pPrev = tmp.pNext;
    
    
}
// head = tmp.tail




       // if(index == 0){
    //     push_front(T value);
    // } else {
    //     Node<T> *tmp = head;
    //     for (int i = 0; i < size_l && i < index - 1; i++)
    //     {
    //         tmp = tmp->pNext;
    //     }
    //     Node<T> *newNode = new Node<T>(value, tmp);
    //     tmp->pNext = newNode;
    //     //  tmp->pNext = new Node<T>(value, tmp);  Альтернативы предыдушим 2м строякам
    // }
    // size_l++;
}

template <typename T>
inline void List<T>::unique()
{

}

template <typename T>
void List<T>::push_back(const_reference value)
{
    // cout << "Create NODE" << endl;
    Node<value_type> *current = new Node<value_type>(value);
    // current->pNext = nullptr;
    // current->value = value;

    if(head == nullptr){
        current->pNext = current->pPrev = nullptr;
        head = tail = current;
        // cout << "Create NODE_1" << endl;

    } else {
        // cout << "Create NODE_2+" << endl;
        current->pPrev = tail;
        //  cout << "Create NODE_2+_4" << endl;
        tail->pNext = current;
        tail = current;
    }
    
    // if(head == nullptr){
    //     head = new Node<T>(value);
    // } else {
    //     Node<T> *current = this-> head;
    //     while (current->pNext != nullptr)
    //     {
    //         current = current->pNext;
    //     }
    //     current = new Node<T>(value);
    // }
    size_l++;
}

template <typename T>
void List<T>::push_front(const_reference value)
{
    Node<value_type> *current = new Node<value_type>(value);
    // current->pNext = nullptr;
    // current->value = value;

    if(head == nullptr){
        current->pNext = current->pPrev = nullptr;
        head = tail = current;
    } else {
        current->pNext = head;
        head->pPrev = current;
        head = current;
    }

}

// template <typename T>
// inline iterator List<T>::begin()
// {



//     // constexpr const_iterator
//     //   begin() const noexcept { return _M_array; }



//     return iterator();
// }

template <typename T>
void List<T>::insert(T value, int index)
{
    // if(index == 0){
    //     push_front(T value);
    // } else {
    //     Node<T> *tmp = head;
    //     for (int i = 0; i < size_l && i < index - 1; i++)
    //     {
    //         tmp = tmp->pNext;
    //     }
    //     Node<T> *newNode = new Node<T>(value, tmp);
    //     tmp->pNext = newNode;
    //     //  tmp->pNext = new Node<T>(value, tmp);  Альтернативы предыдушим 2м строякам
    // }
    // size_l++;
}

template <typename T>
void List<T>::removeAt(int index)
{
    if(index == 0){
        pop_front();
    } else {
        Node<value_type> *tmp = head;
        for (int i = 0; i < size_l && i < index; i++)
        {
            tmp = tmp->pNext;
            
        }   
  
    Node<value_type> *tmpDel = tmp;
    tmp->pNext = tmpDel->pPrev;    
    tmp->pPrev = tmpDel->pNext; 
    delete tmpDel;
    size_l--;
  }  
}

template <typename T>
void List<T>::pop_back()
{
    removeAt(size_l - 1);
    tail = tail->pPrev;

}

template <typename T>
bool List<T>::empty()
{   
    return head == nullptr;
}

// template <typename T>
// inline void List<T>::Show()
// {
// }

template <typename T>
void List<T>::show()
{
    // cout << " | " << endl;
    Node <value_type> *tmp = head;
    cout << " || " << endl;
    while(tmp != nullptr){
        cout << tmp->value << " x ";

        tmp = tmp->pNext;
    }
    // cout << "end " << endl;
    cout  << endl;
}

// template <typename T>
// inline size_type List<T>::max_size()
// {
//     return size_type();
// }

template <typename T>
T &List<T>::operator[](const int index)
// обработать обращение за пределы, на несуществующий элемент
{
    // cout << "operator[]" << endl;
    int counter = 0;
    Node<value_type> *current = this->head;
    T value_{0};
    while (current != nullptr)
    {
        // cout << "operator[]_1" << endl;
        if (counter == index)
        {
            return current->value;
        }
        current = current->pNext;
        counter++;
    }
    throw std::out_of_range("Index out of bounds");
}







}


// int main(){
//     // g++ list.cc && ./a.out 
// // gcc -lstdc++ -std=c++17 list.cc && ./a.out
//     setlocale(LC_ALL, "ru");
//     s21::List<int> lst;
//     lst.push_back(5);
//     lst.push_back(10);
//     lst.push_back(22);

//     cout << lst.GetSize_l() << endl;

//     cout << lst[2] << endl;

//     for (size_t i = 0; i < lst.GetSize(); i++)
//     {
//         cout << lst[i] << endl;
//     }

//     lst.insert (99, 1);
//     lst.removeAt(1);
//     lst.pop_back();

//     cout<< "Элементов в списке" << lst.GetSize() << endl << "Забрали первый элемент" << endl << endl;
    
    
//                                                                                                                                                                                  for (size_t i = 0; i < lst.GetSize(); i++)
//     {
//         cout << lst[i] << endl;
//     }
//     cout<< "Элементов в списке" << lst.GetSize() << endl;
//     return 0;
// }



// void print(std::list<std::string> const &list)
// {
//     for (auto const &i: list) {
//         std::cout << i << std::endl;
//     }
// }