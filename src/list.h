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
        // operator=(List &&l);  // assignment operator overload for moving object

        
        void clear();  // clears the contents

        void push_back(const_reference value); // adds an element to the end
        void pop_back(); // removes the last element 
        void push_front(const_reference value); // adds an element to the head
        void pop_front(); // removes the first element

        // void push_front(T data);


        // void push_back(T data);
        size_type size() {return size_l;}; // returns the number of elements
        // size_type max_size();
        T& operator[](const int index);

        const_reference front() const noexcept {return head->data;}; //access the first element
        const_reference back() const noexcept {return tail->data;};  // access the last element

        
        void insert(T data, int index);
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
                T data;
                Node(T data = T(), Node *pNext = nullptr){
                    this->data = data;
                    this->pNext = pNext;
                    this->pPrev = pPrev;
                    // cout << "в классе node" << endl;
                }
        };
        int size_l;
        Node<value_type> *head;
        Node<value_type> *tail;
     private:
};

template<typename T>
List<T>::List()
{
    // cout << "Create list" << endl;
    size_l = 0;

    // Node<value_type> *zero; // Заглужка,  0 элемент
    // head = zero;
    // tail= zero;

    head = nullptr;
    tail= nullptr; 
}

template <typename T>
List<T>::List(size_type n)
{
    head = nullptr;
    tail= nullptr; 
    size_l = 0;
    // cout << "List_n" << endl;
    for(int i = 0; i < n; i++){
        push_back(0);
    }
    // cout << "Create list _N_" << endl;
    
}

template <typename value_type>
List<value_type>::List(std::initializer_list<value_type> const &items):List()
{
        for (auto element : items)
        {
            push_back(element);
        }
}

template <typename T>
inline List<T>::List(const List &l)
{
    // List<value_type>::List(std::initializer_list<value_type> const &List):List()
    List<T> s21_List(size_l);
    for (auto element : l && l.tail->pPrev != nullptr )
        {
            push_back(element);
        }

}

template <typename T>
inline List<T>::List(List &&l)
{
    clear();
    head = l.head;
    tail = l.tail;


    // return *this;
}

template<typename T>
List<T>::~List()
{
    // cout << "Delete list" << endl;
    clear();
    
}

// template <typename T>
// inline List<T>::operator=(List &&l)
// {
//     clear();
//     head = l.head;
//     tail = l.tail;
//     return *this;
// }

template <typename T>
void List<T>::clear()
{
    while (size_l)
    {
        pop_front();
    }
    // cout << "Clear list" << endl;
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
void List<T>::push_back(const_reference value)
{
    // cout << "Create NODE" << endl;
    Node<value_type> *current = new Node<value_type>(value);
    current->pNext = nullptr;
    current->data = value;

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
    //     head = new Node<T>(data);
    // } else {
    //     Node<T> *current = this-> head;
    //     while (current->pNext != nullptr)
    //     {
    //         current = current->pNext;
    //     }
    //     current = new Node<T>(data);
    // }
    size_l++;
}

template <typename T>
void List<T>::push_front(const_reference value)
{
    Node<value_type> *current = new Node<value_type>(value);
    current->pNext = nullptr;
    current->data = value;

    if(head == nullptr){
        current->pNext = current->pPrev = nullptr;
        head = tail = current;
    } else {
        current->pNext = head;
        head->pPrev = current;
        head = current;
    }

}

template <typename T>
void List<T>::insert(T data, int index)
{
    // if(index == 0){
    //     push_front(T data);
    // } else {
    //     Node<T> *tmp = head;
    //     for (int i = 0; i < size_l && i < index - 1; i++)
    //     {
    //         tmp = tmp->pNext;
    //     }
    //     Node<T> *newNode = new Node<T>(data, tmp);
    //     tmp->pNext = newNode;
    //     //  tmp->pNext = new Node<T>(data, tmp);  Альтернативы предыдушим 2м строякам
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
    cout << " | " << endl;
    Node <value_type> *tmp = head;
    cout << " || " << endl;
    while(tmp != nullptr){
        cout << tmp->data << " x ";

        tmp = tmp->pNext;
    }
    cout << "end " << endl;
    cout  << endl;
}

template <typename T>
T &List<T>::operator[](const int index)
// обработать обращение за пределы, на несуществующий элемент
{
    // cout << "operator[]" << endl;
    int counter = 0;
    Node<value_type> *current = this->head;
    T data_{0};
    while (current != nullptr)
    {
        // cout << "operator[]_1" << endl;
        if (counter == index)
        {
            return current->data;
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