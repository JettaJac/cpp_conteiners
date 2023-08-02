// #ifndef SRC_S21_CONTAINERS_OOP_H_
// #define SRC_S21_CONTAINERS_OOP_H_

#include <iostream>
// #include <string>
using namespace std;
// #define size_type size_t


namespace s21{

    

template<typename T> // возможно здесь вместо typename - class
class List {
    // class Node;
    //     template <typename T>
    // List<T>::List(size_type n) 
// сделать private 
    using value_type = T;  // defines the type of an element (T is template parameter)   

    // template<typename value_type> //  возможно private  // при возможности оставить только у листа   
    class Node 
    {
        public:
            Node *pNext_;
            Node *pPrev_;
            T value_;
            Node(T value = T(), Node *pPrev_ = nullptr, Node *pNext_ = nullptr) { // возможно добавить pPrev  и переписать pushопираясь на это
                this->value_ = value;
                this->pNext_ = pNext_;
                this->pPrev_ = pPrev_;
                // cout << "в классе node" << endl;
            }
    };      



    public:
    // class ListIterator;


    // template<typename  value_type>
    class ListIterator{

        using value_type = T;
        using alue_type = T;
        // using Node = typename List<T>::template Node/*<value_type>*/;
        // using Node = typename List<T>::template Node/*<value_type>*/;
        using reference = T&; // defines the type of the reference to an element
        using const_reference = const T&;

        public:
            ListIterator() {iterNode_ = nullptr;} // было nullptr
            // ListIterator(int i);  // перемешение на i элемент
            // ListIterator(ListIterator const &iterNode_) {this = iterNode_;};   // Конструктор копирования
            // ListIterator(ListIterator &&iterNode_);
            // ListIterator(Node* node);
            ListIterator(Node *current) : iterNode_(current) {};
            // ~ListIterator(); // Деструктор
            // ~ListIterator(int);
            // ListIterator begin(); // Переходим на первый элемент не надо


            ListIterator &operator++() { // сделать ссылкой
                
                // return iterNode_->pNext_;
                // ListIterator it;
                
                    ListIterator it = iterNode_->pNext_;
                    iterNode_ = iterNode_->pNext_;
                // if (iterNode_ = zero_){
                //    it = iterNode_->pPrev_;
                // }
                //  cout << "OPERATOR++ "<< *it << endl;
                return *this;
                
                
                
                }; // префексная форма


            ListIterator operator++(int){ // кинуть исключения
                //  cout << "OPERATOR++ " << endl;
                ListIterator it = iterNode_;
                // ListIterator tmp = iterNode_->pPrev_;
                //  if (iterNode_->pNext_){ // равен заглушки
                // ListIterator tmp  = it;
                    // cout << "OPERATOR++ " << endl;
                //    cout << "TMP " << *it << endl;
                //    cout << "IT " << *it << endl;
                iterNode_ = iterNode_->pNext_;
                // if (*it == 3) {
                // //    iterNode_ = iterNode_->pPrev_;
                //     cout << "IFF " << *it << endl;
                //     it = tmp;
                //     cout << "IFF " << *it << endl;
                // }

                
                // cout << "OPERATOR_++ "<< *it << endl;

                // cout << endl;
                //  }
                return it;



// return *(IterPointer_ + index);




            } // постфиксная форма
            ListIterator operator--() { 
                // cout << iterNode_->pPrev_ << " > "  << endl;
                ListIterator it = iterNode_->pPrev_;
                // ListIterator it = iterNode_->pNext_;
                    iterNode_ = iterNode_->pPrev_;
                    // iterNode_ = iterNode_->pPrev_;
                    // iterNode_ = iterNode_->pPrev_;
                // if (iterNode_ = zero_){
                //    it = iterNode_->pPrev_;
                // }
                //  cout << "OPERATOR++ "<< *it << endl;
                return it;
                
                
               /* return iterNode_->pPrev_;*/ }; // префексная форма

            ListIterator operator--(int)
            {
                ListIterator it = iterNode_;
                iterNode_ = iterNode_->pPrev_;
                return it;

                // ListIterator temp = *this;
                // --(*this);
                // return temp;

            }; // постфиксная форма

            // ListIterator operator--(int i); //тестовая
            /*ListIterator**/reference operator*() {return iterNode_->value_;}
            // bool operator==(const Node &other) const {return iterNode_->value_ == other.value_;} // проверяем указатели а не ноды
            // bool operator!=(Node &other) const {return iterNode_->value_ != other.value_};
            // ListIterator operator->() {return iterNode_;}

            // iterator1 == iterator2
            // iterator1.operator==(const iterator2) const
            // template <class T> ListIterator<T> &ListIterator<T>::operator+=(size_t num) 
            // ListIterator<T> &ListIterator<T>::operator=(const ListIterator &other)
        //         bool ListIterator<T>::operator==(
        // const typename ListIterator<T>::const_iterator &other)
        // template <class T> ListNode<T> *ListIterator<T>::getPtr()

  
            // template <typename value_type>
            // typename ListIterator::ListIterator()
            // {
            //     cout << "CREATE_ITERATOR "<< endl;
            // }


            
            // template<typename T>
            // template <typename T>
            // ListIterator List::ListIterator::ListIterator()  // Iterator(Node* node) : current(node) {}  нужен ли конструктор копирование и перемещение
            // {
            //     cout << "CREATE_ITERATOR "<< endl;
            //     iterNode_ = nullptr;
            // }

            // template<typename T>
            // inline ListIterator List<T>::ListIterator::operator++()
            // {
            //      return ListIterator();
            // }

                // template <typename T>
                // inline ListIterator()
                // {
                //          cout << "CREATE_ITERATOR "<< endl;
                // }

            // template <typename T>
            // inline List<T>::ListIterator::ListIterator(iterator const &iterNode_)
            // {

            // }

            // template <typename value_type>
            // inline ListIterator(int i)
            // {   
            //     ListIterator  tmp(this);
            //     for(int z = 0; z != i; z++){
            //         tmp = tmp->pNext_;
            //     }
            //     //  return *tmp;
                
            // }

            // template <typename T>
            // inline List<T>::ListIterator(ListIterator const &iterNode_)
            // {
            //     ListIterator *tmp;
            //     tmp = iterNode_;                

            // }

            // template <typename value_type>
            // inline ListIterator(ListIterator const &iterNode_)
            // {
                

            //     // ~this;
            //     this = iterNode_;
            // }

            //             ListIterator<int>::iterNode_ tmp_o (5);
            // ListIterator<int>::iterNode_ tmp (tmp_o );


                // inline ~ListIterator()
                // {
                //     int g = 7;
                // }

        
            // template <typename value_type>
            // /*inline*/~ListIterator()
            // {   
            //     int y = 0;
            //     // delete iterNode_;
            //     // iterNode_ = nullptr; //  проверть
            // }
            // ~ListIterator(){};
            // template <typename value_type>
            // ListIterator begin()
            // {
            //     ListIterator  tmp(this); // не будет работать
            //     while(tmp->pPrev_){
            //         tmp = tmp->pPrev_;
            //     }
            //      return tmp;
            // }

            // template <typename value_type>
            // inline ListIterator operator++(int)
            // {   
            //     // ListIterator  tmp (*this);
            //     // iterNode_ = iterNode_.pNext_;  //почему не через .
            //     // return tmp;
            //     // return iterNode_->pNext_;


                
            // }

            // List<T>::List()
            // template <typename T>
            // inline List<T> List<T>::operator=(List const &l)

            // template <typename value_type>
            // inline ListIterator  List<T>::ListIterator::operator++()
            // {
            //     // return ListIterator(iterNode_->pNext_);
            //     return iterNode_->pPrev_;
            // }



//    template <typename T>
//     inline typename List<T>::iterator List<T>::end()
//     {
//         return typename List<T>::iterator(tail_);
//     }

            // template<typename alue_type>
            // inline ListIterator List<T>::ListIterator::operator++()
            // {
            //     iterNode_ = iterNode_->pNext_;
            //     return *this;
            // }
            // template <typename T>
            // inline ListIterator List<T>::ListIterator::operator--(int i)
            // {
            //     return ListIterator();
            // }
            // template<typename value_type>
            // inline typename List<value_type>::ListIterator List<value_type>::ListIterator::operator++()
            // {
            //     iterNode_ = iterNode_->pNext_;
            //     return *this;
            // }

            // template <typename value_type>
            // inline ListIterator operator--(int)
            // {
            //     ListIterator  tmp (*this);
            //     iterNode_ = iterNode_->pPrev_;  //почему не через .
            //     return tmp;
            // }

            // template <typename T>
            // inline ListIterator<T>::ListIterator(ListIterator const &iterNode_)
            // {
            //     iterNode_ = iterNode_->pPrev_; 
            // }

            private:
            Node  *iterNode_;
            friend class List<T>;

    };



     // member type
    // using value_type = T;  // defines the type of an element (T is template parameter)
    using reference = T&; // defines the type of the reference to an element
    using const_reference = const T&; // defines the type of the constant reference
    using iterator = ListIterator;// internal class ListIterator<T> defines the type for iterating through the container
    using size_type = std::size_t; // size_t defines the type of the container size (standard type is size_t)
    // using const_iterator = ListConstIterator<T>;

    public:
        List();     // List() : head(nullptr), tail_(nullptr) {}          // default constructor, creates empty list 
        List(size_type n);   // parameterized constructor, creates the list of size n
        List(std::initializer_list<value_type> const &items);
        List(const List &l); // copy constructor
        List(List &&l);      // move constructor
        ~List();             // destructor
        List<T> operator=(List const &l);  // assignment operator overload for moving object
        List<T> operator=(List &&l); 
        
        void clear();  // clears the contents

        void push_back(const_reference value_); // adds an element to the end
        void pop_back(); // removes the last element 

        
        

        void push_front(const_reference value_); // adds an element to the head
        void pop_front(); // removes the first element
        void swap(List& other);
        void reverse();

        void unique(); // removes consecutive duplicate elements


        // void push_back(T value);
        size_type size() {return size_;}; // returns the number of elements
        // size_type max_size(allocator.max_size());
        T& operator[](const int index);

        const_reference front() const noexcept {return head_->value_;}; //access the first element
        const_reference back() const noexcept {return tail_->value_;};  // access the last element

        iterator begin();
        iterator end();
        
        
        void insert(T value, int index); // inserts element into concrete pos and returns the iterator that points to the new element
        void removeAt(int index);
        
        bool empty();  // checks whether the container is empty

        void  show();            

    // using value_type = T;
   
        

     private:
        size_t size_;
        Node/*<value_type> */*head_;
        Node/*<value_type>*/ *tail_;
        Node/*<value_type>*/ *zero_;
    };

    template<typename T>
    List<T>::List()
    {
        // cout << "Create list " << this << endl;
       

        // Node/*<value_type>*/ *zero = new Node/*<value_type>*/(0);// Заглужка,  0 элемент

        zero_ = new Node(value_type (), nullptr, nullptr);
        // zero_ = new Node(value_type (), zero_, zero_);
        //  zero_->pNext_ = zero_->pPrev_ = nullptr;
        head_= tail_ = zero_;
        size_ = 0;
        // tail_ = zero_;

        // head_= nullptr;
        // tail_= nullptr; 

        zero_->pNext_ = head_;
        zero_->pPrev_ = tail_;

    // tail_ = new Node(value_type ());
    // head_= tail_;

    }

    template <typename T>
    List<T>::List(size_type n) 
    {   cout << "List_n" << endl;
        // cout << " gggg " << &zero_ << endl;
        zero_ = new Node(value_type (), zero_, zero_); // возможно не zero_, а nullptr
        // cout << "ZERO_" << zero_->value_ << endl;
        head_= tail_ = zero_;
        // tail_ = zero_; 
        size_ = 0;

        // Может сделать на базе основного конструктора

        for(size_type i = 0; i < n; i++){
             cout << "List_" << i << endl;
            push_back(value_type ());
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
        Node/*<value_type>*/ *current = l.head_;
        // new Node/*<value_type>*/(*head_);
        // current->pNext_ = nullptr;
        for(int i = 0; i < l.size_; i++)
        {
            push_back(current->value_);
            current = current->pNext_;
            // tmp->size_ = 7;
        }
    }

    template <typename T>
    List<T>::List(List &&l) /*: List()*/ : head_(l.head_), tail_(l.tail_), size_(l.size_)// : fake_node_(l.fake_node_), size_(l.size_) {
    {   
        cout << "Move function" << endl; 
    
        // operator=(l);

        // swap(this, l);

        //   clear();
        // head_= l.head_;
        // tail_ = l.tail_;
        size_ = l.size_;

        // l.clear();
        l.head_= l.zero_; // А не будет ли утчки?
        l.tail_ = l.zero_;
        l.size_ = 0;
        // cout << tail_ << " =!!= "<< zero_ << endl;
        
    }

    template<typename T>
    List<T>::~List()
    {
        // cout << "Delete list " << this << endl;
        // cout << "Delete list " << zero_ << endl;
        // cout << "Delete list " << zero_->pPrev_ << endl;
        clear();
        // !!!!!!!!!!!! удалить ZERO
        // delete zero_;
        // cout << "Delete list_finish " << this << endl;
    }

    template <typename T>
    inline List<T> List<T>::operator=(List const &l)
    {
        // cout << "Operator Copy " << this << endl;
        // cout <<  " h "<< endl;
        clear();
        // cout <<  " h "<< endl;
        // List<T> tmp();
        Node/*<value_type> */*current = l.head_;
        // new Node/*<value_type>*/(*head_);
        // current->pNext_ = nullptr;
        // head_= l.head_;
        for(int i = 0; i < l.size_; i++)
        {
            push_back(current->value_);
            current = current->pNext_;
            // tmp->size_ = 7;        
        }
        // cout <<  " y " << endl;

        // for (const auto& element : l) { //  возможно с интералами будет работать)
            
        //     cout << element << " x ";
        //     push_back(current->value_);
        // }
        

        // head_= l.head_;
        return *this;
    }

    template <typename T>
    List<T> List<T>::operator=(List &&l)
    {
        cout << "Operator Move " << this << endl;
        clear();
        head_= l.head_;
        tail_ = l.tail_;
        size_ = l.size_;
        l.head_= NULL;
        l.tail_ = NULL;
        l.size_ = 0;
        // move(l);
        // cout << "SIZE_2: " << size_ << endl;
        return *this;
    }

    template <typename T>
    void List<T>::clear()
    {
        // cout << "Clear list" << endl;
        // cout << "SIZE: " << size_ << endl;
        while (size_)
        {
            // cout << "SIZE: " << size_ << endl;
            // cout << "1" << endl;
            pop_front();
        }
        // cout << "Clear list finish " << this << endl; 
    }

    template <typename T>
    void List<T>::pop_front()
    {
        // cout << "Delete Node" << endl;
        Node/*<value_type>*/ *tmp = head_;
        head_= head_->pNext_;    
        // cout << "Delete Node _" << size_ << endl;
        // cout << head_ << " == "<< zero_ << endl;
        // cout << tail_ << " == "<< zero_ << endl;
        delete tmp;
        // cout << tail_ << " =!= "<< zero_ << endl;
        size_--;
    }

    template <typename T>
    void List<T>::swap(List &other)
    {
        // std::swap(head, l.head_);
        // std::swap(tail_, l.tail_);
        // std::swap(size_, l.size_);

        cout << "SWAP " << endl;
        Node/*<value_type> */*cur_head_= new Node/*<value_type>*/(1);
        Node/*<value_type>*/ *cur_tail_ = new Node/*<value_type>*/(1);
        cur_head_= head_;
        cur_tail_ = tail_;
        size_t t = size_;

        head_= other.head_;
        tail_ = other.tail_;
        size_ = other.size_;

        other.head_= cur_head_;
        other.tail_ = cur_tail_;
        other.size_ = t;
    }

    // template <typename T>
    // inline void List<T>::reverse()
    // {


    // }

    template <typename T>
    inline void List<T>::reverse()
    {

        // Попробовать сделать через итераторы, без доп листа
        // if (first_ != nullptr) {
    // show();        
    List <T> tmp_l (*this);
    // tmp.show();  
    // clear();
    // show(); 
    Node /*<value_type> */*tmp = tmp_l.head_;
    clear();
    for (int i = 0; i < 7; i++){
        // head_= tmp.head_;
        // this.pNext_ = tmp.pPrev_;
        // pPrev_ = tmp.pNext_;
    // tmp->pNext_ = new Node<T>(this-> , tmp);  
        // cout << "Value_ "  << endl;
        push_front(tmp->value_);
        tmp = tmp->pNext_;
    // tmp.

    }
    // head_= tmp.tail_;




        //    if(index == 0){
        //     push_front(T value);
        // } else {
        //     Node<T> *tmp = head_;
        //     for (int i = 0; i < size_ && i < index - 1; i++)
        //     {
        //         tmp = tmp->pNext_;
        //     }
        //     Node<T> *newNode = new Node<T>(value, tmp);
        //     tmp->pNext_ = newNode;
        //     //  tmp->pNext_ = new Node<T>(value, tmp);  Альтернативы предыдушим 2м строякам
        // }
        // size_++;
    }

    // template <typename T>
    // inline void List<T>::unique()
    // {
    //     List<T> tmp (this);
    //     clear;
    //      Node<T> *node_cur = head_;
    //      Node<T> *node_prev = pPrev_;
    //     for(int i = 0; i < size_ && i < size_; i++){
    //         if( value == node_prev){

    //         }

    //     }

    // }

    template <typename T>
    void List<T>::push_back(const_reference value)
    {
        // cout << "Create NODE" << endl;
        Node/*<value_type>*/ *current = new Node/*<value_type>*/(value, zero_, zero_);
        // Node/*<value_type>*/ *current = new Node/*<value_type>*/(value, zero_, zero_); // добавить аргументы
        // current->pNext_ = zero_; // надо
        // current->value_ = value;
        // cout << "Value_ " << current->value_   << endl;

        if(head_ == zero_){ // сюда теоретически не должен заходить / заходит
        // cout << "Value_ " << current->value_   << endl;
        // cout << "Create NODE_1" << endl;
        zero_->pNext_ = zero_->pPrev_ = current; // добавила
        // cout << "Value_ " << current->value_   << endl;
        current->pNext_ = current->pPrev_ = zero_;
        // cout << "Value_ " << current->value_   << endl;
            
           
            // cout << "oo "  /* << zero_->pNext_<<  zero_->pPrev_ */ << zero_<< endl;
        
           
            
            head_= tail_ = current;
            
        // cout << "Create NODE_4" << endl;
        } else {
            // cout << "Create NODE_2+" << endl;
            current->pPrev_ = tail_;
            //  cout << "Create NODE_2+_4" << endl;
            tail_->pNext_ = current;
            tail_ = current;

            // current->pNext_ = zero_;
            zero_->pPrev_ = tail_;

            // zero_->value_ = 

            //  current->pPrev_ = tail_;
            // //  cout << "Create NODE_2+_4" << endl;
            // tail_->pNext_ = current;
            // // tail_ = current;
            // zero_->value_ = current->value_;
            // iterator  it = begin();
            // cout << "IT _ " << *it << endl;
            zero_->value_ = size_ + 1;


        }
        // cout << "Create NODE_3" << endl;
        // if(head_== nullptr){
        //     head_= new Node<T>(value);
        // } else {
        //     Node<T> *current = this-> head_;
        //     while (current->pNext_ != nullptr)
        //     {
        //         current = current->pNext_;
        //     }
        //     current = new Node<T>(value);
        // }
        size_++;
    }

    template <typename T>
    void List<T>::push_front(const_reference value)
    {
        Node/*<value_type>*/ *current = new Node/*<value_type>*/(value, zero_, zero_);
        // current->pPrev_ = zero_; // надо
        // current->value_ = value;
        // zero_->value_ = value; // так то не надо

        if(head_ == zero_){
            zero_->pNext_ = zero_->pPrev_ = current; // добавила
            current->pNext_ = current->pPrev_ = zero_;
            head_ = tail_ = current;
        } else {
            current->pNext_ = head_;
            head_->pPrev_ = current;
            head_ = current;
            zero_->pNext_ = head_;
            zero_->value_ = size_ + 1;
        }
        size_++;

    }

    // template <typename T>
    // inline iterator List<T>::begin()
    // {



    //     // constexpr const_iterator
    //     //   begin() const noexcept { return _M_array; }



    //     return iterator();
    // }

    template <typename T>
    inline typename List<T>::iterator List<T>::begin()
    {
        // ListIterator it (head_);
        return typename List<T>::iterator(head_);
        // return ListIterator<T>::this->begin();

            // iterator begin() const noexcept { return iterator(fake_node_->pNext__); }
        // return  it;
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::end()
    {
        // return typename List<T>::iterator(tail_);
        return typename List<T>::iterator(zero_);
    }

    // template <typename T>
    // inline iterator List<T>::begin()
    // {
    //     return iterator();
    // }

    template <typename T>
    void List<T>::insert(T value, int index)
    {
        // if(index == 0){
        //     push_front(T value);
        // } else {
        //     Node<T> *tmp = head_;
        //     for (int i = 0; i < size_ && i < index - 1; i++)
        //     {
        //         tmp = tmp->pNext_;
        //     }
        //     Node<T> *newNode = new Node<T>(value, tmp);
        //     tmp->pNext_ = newNode;
        //     //  tmp->pNext_ = new Node<T>(value, tmp);  Альтернативы предыдушим 2м строякам
        // }
        // size_++;
    }

    template <typename T>
    void List<T>::removeAt(int index)
    {
        if(index == 0){
            pop_front();
        } else {
            Node/*<value_type>*/ *tmp = head_;
            for (int i = 0; i < size_ && i < index; i++)
            {
                tmp = tmp->pNext_;
                
            }   
    
        Node/*<value_type>*/ *tmpDel = tmp;
        tmp->pNext_ = tmpDel->pPrev_;    
        tmp->pPrev_ = tmpDel->pNext_; 
        delete tmpDel;
        size_--;
    }  
    }

    template <typename T>
    void List<T>::pop_back()
    {
        removeAt(size_ - 1);
        tail_ = tail_->pPrev_;

    }



    // template <typename T>
    // inline List<T>::iterator List<T>::end()
    // {
    //     return this->tail_;
    // }

    template <typename T>
    bool List<T>::empty()
    {   
        return head_ == zero_;
    }

    // template <typename T>
    // inline void List<T>::Show()
    // {
    // }

    template <typename T>
    void List<T>::show()
    {
        // cout << " | " << endl;
        Node /*<value_type> */*tmp = head_;
        cout << " || " << endl;
        for(int i = 0; i < size_; i++){ // for
            cout << tmp->value_ << " x ";
            // i++;
            tmp = tmp->pNext_;
        }
        
        cout << " end" << endl;
        cout  << endl;
        cout << "SIZE " << size()  << endl;
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
        Node/*<value_type>*/ *current = this->head_;
        T value_{0};
        while (current != zero_)
        {
            // cout << "operator[]_1" << endl;
            if (counter == index)
            {
                return current->value_;
            }
            current = current->pNext_;
            counter++;
        }
        throw std::out_of_range("Index out of bounds");
    }

// };

   


    // template<class T>template<typename T>
    // class ListConstIterator<T>{

    // template <typename T>
    // inline List<T>::ListIterator::ListIterator()
    // {
    //     cout << "uu" << endl;
    // }

};
