#ifndef SRC_S21_CONTAINERS_OOP_H_
#define SRC_S21_CONTAINERS_OOP_H_

#include <iostream>
#include <memory>
using namespace std;

namespace s21{  
template<typename T> // возможно здесь вместо typename - class
class List {

    class Node;
    class ListIterator;
    class ListConstIterator;

    public:
    // member type
    using value_type = T;  // defines the type of an element (T is template parameter)
    using reference = T&; // defines the type of the reference to an element
    using const_reference = const T&; // defines the type of the constant reference
    using iterator = ListIterator;// internal class ListIterator<T> defines the type for iterating through the container
    using const_iterator = ListConstIterator; // internal class ListConstIterator<T> defines the constant type for iterating through the containe
     using size_type = std::size_t; // size_t defines the type of the container size (standard type is size_t)
    using allocator = class std::allocator<T>;
    using allocator_node = typename std::allocator_traits<allocator>::rebind_alloc<s21::List<T>::Node>;

    public:
        List();     // List() : head(nullptr), tail_(nullptr) {}          // default constructor, creates empty list 
        List(size_type n);   // parameterized constructor, creates the list of size n
        List(std::initializer_list<value_type> const &items);
        List(const List &l); // copy constructor
        List(List &&l);      // move constructor
        ~List();             // destructor
        List<T> operator=(List const &l);  // assignment operator overload for moving object
        List<T> operator=(List &&l); 

        const_reference front() const noexcept {return head_->value_;}; //access the first element
        const_reference back() const noexcept {return tail_->value_;};  // access the last element

        iterator begin(); // returns an iterator to the beginning
        iterator end(); // returns an iterator to the end
        const_iterator cbegin(); // returns an const_iterator to the beginning
        const_iterator cend(); // returns an iterator to the end
        
        bool empty();  // checks whether the container is empty
        size_type size() const noexcept {return size_;}; // returns the number of elements
        size_type max_size() const noexcept {return alloc_n.max_size();};

        void clear();  // clears the contents
        iterator insert(iterator pos, const_reference value); // inserts element into concrete pos and returns the iterator that points to the new element
        void erase(iterator pos); // erases element at pos

        void push_back(const_reference value_); // adds an element to the end
        void pop_back(); // removes the last element 
        void push_front(const_reference value_); // adds an element to the head
        void pop_front(); // removes the first element
        void swap(List& other);
        void merge(List& other);
        void splice(const_iterator pos, List& other); // возможно надо сделать перегрузку
        void reverse(); // reverses the order of the elements
        void unique(); // removes consecutive duplicate elements
        void sort();  // sorts the elements

        T& operator[](const int index);
        void removeAt(int index);
        void  show();     
        
 private:
    class Node 
    {
        public:
            Node *pNext_;
            Node *pPrev_;
            T value_;
            Node(T value = T(), Node *pPrev_ = nullptr, Node *pNext_ = nullptr) { 
                this->value_ = value;
                this->pNext_ = pNext_;
                this->pPrev_ = pPrev_;
            }
    };  

    class ListIterator{

    using value_type = T;
    using size_type = size_t;
    using Node = typename List<T>:: Node;
    using reference = T&; // defines the type of the reference to an element
    using const_reference = const T&;

    public:
        ListIterator() {iterNode_ = nullptr;} // было nullptrможет сделать  zero_
        ListIterator(ListIterator const &other) : iterNode_(other.iterNode_){};   // Конструктор копирования
        ListIterator(ListIterator &&other){ 
            if (*this != other) {
                iterNode_ = other.iterNode_;
                other.iterNode_ = nullptr;
            }
        };

        ListIterator(Node *current) : iterNode_(current) {};
        // ~ListIterator(); // Деструктор
        // ~ListIterator(int);

  

        // ListIterator operator=(ListIterator const &other) : iterNode_(other.iterNode_){};/*{
        //     iterator it = other
        //     return *it;
        // };*/

        ListIterator &operator++() { 
            ListIterator it = iterNode_->pNext_;
            iterNode_ = iterNode_->pNext_;    
            return *this;
        }; // префексная форма

        ListIterator operator++(int){ 
            ListIterator it = iterNode_;
            iterNode_ = iterNode_->pNext_;
            return it;
        }; // постфиксная форма

        ListIterator &operator--() { 
            ListIterator it = iterNode_->pPrev_;
            iterNode_ = iterNode_->pPrev_;
            return *this;
        }; // префексная форма

        ListIterator operator--(int)
        {
            ListIterator it = iterNode_;
            iterNode_ = iterNode_->pPrev_;
            return it;
        }; // постфиксная форма

        reference operator*() {return iterNode_->value_;}
        bool operator==(const ListIterator &other) const {return iterNode_ == other.iterNode_;}; // проверяем указатели а не ноды
        bool operator!=(ListIterator &other) const {return iterNode_ != other.iterNode_;};
        bool operator!=(const ListIterator &other) const {return iterNode_ != other.iterNode_;};
        // ListIterator operator->() {return iterNode_;}
        // reference operator[](int index) {
        //     // auto it (head_);

        //     // size_t t = size_;
        // //    if (index >= size_){
            
        //     cout << "UUU error" << endl;
        // //    }

        //     for (int i = 0; i < index; i++){
        //         iterNode_ = iterNode_-> pNext_;
        //     }
        //     return iterNode_->value_;
        //     // return *it;
           
        //     // return *(iterNode_ + index);
        // }

        // reference  operator[](const value_type index) {
        //     iterator it = begin();
        //     int i = 0;
        //     while(it != end()){
        //             it++;
        //     }
        //     return *it;
        // }

        private:
        Node  *iterNode_;
        friend class List<T>;
    };
    
    class ListConstIterator{

        using value_type = T;
        using size_type = size_t;
        using Node = typename List<T>::Node;
        using reference = T&; // defines the type of the reference to an element
        using const_reference = const T&;

        public:
            ListConstIterator() {iterNode_ = nullptr;} // было nullptrможет сделать  zero_
            ListConstIterator(ListConstIterator const &other) : iterNode_(other.iterNode_){};  // Конструктор копирования
            ListConstIterator(ListConstIterator &&other){ 
                if (*this != other) {
                    iterNode_ = other.iterNode_;
                    other.iterNode_ = nullptr;
                }};

            ListConstIterator(Node *current) : iterNode_(current) {};
            // ~ListConstIterator(); // Деструктор
            // ~ListConstIterator(int);
            // ListConstIterator operator[](const value_type index) {
            // }

            ListConstIterator &operator++() {
                ListConstIterator it = iterNode_->pNext_;
                iterNode_ = iterNode_->pNext_;
                return *this;
                }; // префексная форма

            ListConstIterator operator++(int){ // кинуть исключения
                ListConstIterator it = iterNode_;
                iterNode_ = iterNode_->pNext_;
                return it;
            } // постфиксная форма

            ListConstIterator &operator--() { 
                ListConstIterator it = iterNode_->pPrev_;
                    iterNode_ = iterNode_->pPrev_;
                return *this;
            }; // префексная форма

            ListConstIterator operator--(int)
            {
                ListConstIterator it = iterNode_;
                iterNode_ = iterNode_->pPrev_;
                return it;
            }; // постфиксная форма

            reference operator*() {return iterNode_->value_;}
            bool operator==(const ListConstIterator &other) const {return iterNode_ == other.iterNode_;}; // проверяем указатели а не ноды
            bool operator!=(const ListConstIterator &other) const {return iterNode_ != other.iterNode_;};
            // ListConstIterator operator->() {return iterNode_;}

            private:
            Node  *iterNode_;
            friend class List<T>;
    };

        size_t size_;
        Node *head_;
        Node *tail_;
        Node *zero_;
        allocator_node alloc_n;
    };

    template<typename T>
    List<T>::List()
    {   
        // cout << "List_00" << endl;
        // zero_ = new Node(value_type (), nullptr, nullptr);
        zero_ = new Node(value_type(), zero_, zero_);
        head_= tail_ = zero_;
        size_ = 0;
        
        zero_->pNext_ = head_;
        zero_->pPrev_ = tail_;
        // cout << "Value_1_  " << zero_->value_   << endl;
    }

    template <typename T>
    List<T>::List(size_type n) : List() 
    {   
        // cout << "List_n" << endl;
        // // cout << " gggg " << &zero_ << endl;
        // zero_ = new Node(value_type (), zero_, zero_); // возможно не zero_, а nullptr
        // // // cout << "ZERO_" << zero_->value_ << endl;
        // head_= tail_ = zero_;
        // size_ = 0;

        // Может сделать на базе основного конструктора
        // List();
        // cout << "Value_ " << zero_->value_   << endl;
        // cout << "SIZE s21: " << size() << endl;
        for(size_type i = 0; i < n; i++){
            //  cout << "List_" << i << endl;
            push_back(value_type ());
        }
        // cout << "Create list _N_" << endl;
        
    }

    template <typename value_type>
    List<value_type>::List(std::initializer_list<value_type> const &items) : List()
    {       
        for (auto element : items)
        {
            push_back(element);
        }            
    }

    template <typename T>
    List<T>::List(const List &l) : List()
    {   clear();

        // Node *zero_= new Node (value_type(), nullptr, nullptr);
        // zero_->value_ = zero_->value_;

        // cout << "Copy function " << this << endl;
       // List<value_type>::List(std::initializer_list<value_type> const &List):List()
       // int s;
       // s = size;
        
        // List<T>();
        // zero_ = l.zero_;
        // Node *z = l.head_;
        Node *current = l.head_;
        // Node *current = new Node (*head_, zero_, zero_);
        zero_->pNext_ =  current;
        zero_->pPrev_ =  current;
        current->pPrev_ = zero_;
        // current->pNext_ = zero_;
        // head_ = current;
        // new Node/*<value_type>*/(*head_);
        
        for(int i = 0; i < l.size_; i++)
        {
            push_back(current->value_);
            current = current->pNext_;
        }
        // tail_ = current;
        current->pNext_ = zero_;
        

        // std::swap(*this, l);
        // l.clear();


    }

    template <typename T>
    List<T>::List(List &&l) /*: List()*/ : head_(l.head_), tail_(l.tail_), size_(l.size_), zero_(l.zero_)// : fake_node_(l.fake_node_), size_(l.size_) {
    {   
        // cout << "Move function" << endl; 
    
        // operator=(l);

        // swap(this, l);

        //   clear();
        // head_= l.head_;
        // tail_ = l.tail_;
        size_ = l.size_;

        // l.clear();
        l.head_= l.tail_ = l.zero_; // А не будет ли утчки?
        l.zero_->value_ = value_type();
        // l.tail_ = l.zero_;
        // zero_->pNext_ = head_;
        // zero_->pPrev_ = tail_;
        l.size_ = 0;
        // delete l.zero_;
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
        Node *current = l.head_;
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
        // cout << "Operator Move " << this << endl;
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
        if (zero_ != nullptr) {
        // cout << "Clear list" << endl;
        // cout << "SIZE: " << size_ << endl;
        while (size_)
        {
            // cout << "SIZE: " << size_ << endl;
            // cout << "1" << endl;
            pop_front();
        }

        // скорее всего надот все занулиь
        // other.zero_->value_ = value_type ();
        head_ = tail_ = zero_;
        // this->fake_->next_ = this->first_;
        // this->fake_->back_ = this->last_;
        // zero_->pNext_ = zero_;
        // zero_->pPrev_ = zero_;
        // cout << "Clear list finish " << this << endl; 
        size_ = 0;
        zero_->value_ = value_type ();
        }
    }

    template <typename T>
    inline typename List<T>::iterator List<T>::insert(iterator pos, const_reference value)
    {
    //     return iterator();
    // }

    // template <typename T>
    // inline iterator List<T>::insert(iterator pos, const_reference value)
    // {
        






        //     if(pos == begin()){
        //     push_front(value);
        // } else {
        // //     Node<T> *tmp = head_;
        // //     for (int i = 0; i < size_ && i < index - 1; i++)
        // //     {
        // //         tmp = tmp->pNext_;
        // //     }
        // //     Node<T> *newNode = new Node<T>(value, tmp);
        // //     tmp->pNext_ = newNode;
        // //     //  tmp->pNext_ = new Node<T>(value, tmp);  Альтернативы предыдушим 2м строякам
        // }
        // size_++;

        // cout << "yyyyy" << endl;

        // auto it = begin();

        // while(pos != it){
        //     it++;
        //     cout << "yyyyy" << endl;
        // }
        
    Node *tmp = pos.iterNode_;
    Node *current = new Node (value, tmp->pPrev_, tmp);
    pos.iterNode_->pPrev_->pNext_ = current;
    // pos.iterNode_->pNext_ = current;
    // pos.iterNode_ = current;
    tmp->pPrev_ = current;
    
    // pos.iterNode_->pNext_ = tmp;
    // pos.iterNode_->pPrev_ = tmp->pPrev_;
/*
        Node *current = new Node (value, pos.iterNode_->pPrev_, pos.iterNode_);
        pos.iterNode_->pPrev_= current;
*/



        // pos.iterNode_ = current->pPrev_;
        // pos.iterNode_->pPrev_->pNext_ = current;

        // Node *current = new Node (value);
        // cout << current->value_ << endl;

        // cout << it.iterNode_->pPrev_->value_ << endl;
        // cout << it.iterNode_->pPrev_->pNext_->value_ << endl;
        // cout << endl;
        if(head_ == zero_){ // сюда теоретически не должен заходить / заходит
        // cout << "Value_ " << current->value_   << endl;
        // cout << "Create NODE_1" << endl;
        zero_->pNext_ = zero_->pPrev_ = current; // добавила
        // cout << "Value_ " << current->value_   << endl;
        current->pNext_ = current->pPrev_ = zero_;
        head_= tail_ = current;
        }
        else if (pos == begin()) {
            // Node *tmp = head_;
            // head_ = current;
            cout << "BEGIN" << endl;
            // Node *tmp = head_;
            current->pNext_ = head_;
            head_->pPrev_ = current;
            head_ = current;
            zero_->pNext_ = current;

        } else if (pos == end()) {
            current->pPrev_ = tail_;
            tail_->pNext_ = current;
            tail_ = current;
            zero_->pPrev_ = current;
            // cout << "END" << endl;
        }


        // cout << "BASE" << endl;
        // pos.iterNode_->pPrev_->pNext_ = current;
        // pos.iterNode_->pNext_->pPrev_ = current;

        // cout << current->value_ << endl;
        // cout << pos.iterNode_->pPrev_->value_ << endl;
        // cout << current->pNext_->pNext_->pNext_->value_ << endl;
        // cout << current->pPrev_->pNext_->value_ << endl;

        size_++;
        // push_front(value);

        // return iterator();
        zero_->value_ = size_;

        return pos;
    }

    template <typename T>
    inline void List<T>::erase(iterator pos)
    {   
        // cout << "Erase" << endl;
        if (pos == end()) {

            return;
        } else if ( pos == begin()){
            // cout << "FOR" << endl;
            pop_front();
            // head_->pPrev_ = zero_;
            // cout << head_->pPrev_->value_ << endl;
            // cout << "FOR_99" << endl;
            // return;
        // } else if (pos == --end()){
        //      cout << "FOR_1" << endl;
        //     pos.iterNode_->pPrev_->pNext_ = pos.iterNode_->pNext_;
        //     pos.iterNode_->pNext_->pPrev_ = pos.iterNode_->pPrev_;
        //     tail_->pPrev_->pNext_ = zero_; // убрать, когда erase , будет удалять последний элемент, правильно)
        //     tail_ = tail_->pPrev_; 

        } else /*if (pos != iterator(zero_)) */{
            
            cout << "FOR_0" << endl;
        // iterator it = begin();
        // Node * tmp = pos.iterNode_->pPrev_;
        // it.iterNode_->pNext_ = pos.iterNode_->pNext_;
    //     pos.iterNode_->pPrev_->pNext_ = pos.iterNode_->pNext_;
    //   pos.iterNode_->pNext_->pPrev_ = pos.iterNode_->pPrev_;
        // for(iterator it = begin(); it != end(); it++){
        // // for(auto current = head_; current != tail_; current = current->pNext_){
        // // cout << "FOR" << endl;
        // if(it == pos) {   
        // Node *tmp = std::move(pos.iterNode_);
        // Node *tmp = pos.iterNode_;
         //  it.iterNode_->pNext_ = pos.iterNode_->pNext_;

        // Обновление указателей для предыдущего и следующего узла
         pos.iterNode_->pPrev_->pNext_ = pos.iterNode_->pNext_;
         pos.iterNode_->pNext_->pPrev_ = pos.iterNode_->pPrev_;
    //          pos.iterNode_->pPrev_->pNext_ = pos.iterNode_->pNext_;
    //   pos.iterNode_->pNext_->pPrev_ = pos.iterNode_->pPrev_;
        // if( it == pos) {          
            // cout << "Erase_ " << it.iterNode_->value_ << endl;  
            // cout << "Erase_ " << *it << endl; 
            // cout << "Erase_ " << it.iterNode_->pPrev_ << endl;  
            // cout << "Erase_ " << it.iterNode_->pPrev_->pPrev_ << endl; 
            // cout << "Erase_ " << it.iterNode_->pNext_ << endl;  
            // cout << "Erase_ " << it.iterNode_->pNext_->pNext_ << endl; 
            // delete pos.iterNode_;
            // delete tmp;
            // cout << "FOR" << endl;
            // if (pos == --end()){
            //     cout << "FOR" << endl;
                
            //     tail_->pPrev_->pNext_ = zero_; // убрать, когда erase , будет удалять последний элемент, правильно)
            //     tail_ = tail_->pPrev_; 
            // }

            size_--;
            // cout << "FOR" << endl;
    //     }
    //  }

    //  Node/*<value_type>*/ *tmp = head_;
    //         for (iterator it = 0; it != end() && it != pos; it++)
    //         {
    //             tmp = tmp->pNext_;                
    //         }   
    //         tmp = tmp->pNext_;
    //         Node/*<value_type>*/ *tmpDel = tmp;

    //         // pos.iterNode_->pPrev_->pNext_ = pos.iterNode_->pNext_;
    //         // pos.iterNode_->pNext_->pPrev_ = pos.iterNode_->pPrev_;


    //         tmp->pNext_ = tmpDel->pPrev_;    
    //         tmp->pPrev_ = tmpDel->pNext_; 
            
    //         delete tmpDel;
    //         size_--;
        



    //  cout << "Size_ " << size() << endl;
    }
        //  cout << "POS_i" << endl;

//   if (pos == this->begin()) {
//     pop_front();
//   } else if (pos == this->end()) {
//     pop_back();
//   } else {
//     auto node = pos.iterNode_;
//     node->pPrev_->pNext_ = node->pNext_;
//     node->pNext_->pPrev_ = node->pPrev_;
//     ++pos;
//     delete node;
//     --size_;
//   }


        // cout << "Erase_0 " << endl;





    // if (pos == end()) {
    //     cout << "Erase_ " << endl;
    //     return; // Не удаляемый нулевой элемент
    // }

    // // Обновление указателей для предыдущего и следующего узла
    // pos.iterNode_->pPrev_->pNext_ = pos.iterNode_->pNext_;
    // pos.iterNode_->pNext_->pPrev_ = pos.iterNode_->pPrev_;

    // // Удаляем узел и уменьшаем размер списка
    // // delete pos.iterNode_;
    // size_--;

    // // cout << "Delete POS" << endl;












    }

    template <typename T>
    void List<T>::pop_front()
    {
        // cout << "Delete Node" << endl;
        Node/*<value_type>*/ *tmp = head_;
        // Node *tmp = head_;
        head_= head_->pNext_; 
        head_->pPrev_ = zero_;
        zero_->pNext_ = head_;


        // zero_->pNext_ = head_;   
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
        // std::swap(head_, other.head_);
        // std::swap(tail_, other.tail_);
        // std::swap(size_, other.size_);
        // std::swap(zero_, other.zero_);

        // cout << "SWAP " << endl;
        Node*cur_zero_= new Node (value_type(), tail_, head_);
        cur_zero_->value_ = zero_->value_;

        head_= other.head_;
        tail_ = other.tail_;
        size_ = other.size_;
        zero_ = other.zero_;
        zero_->value_ = other.zero_->value_; // добавила 

        other.head_= cur_zero_->pNext_;
        other.tail_ = cur_zero_->pPrev_;
        other.size_ = cur_zero_->value_;
        other.zero_ = cur_zero_;
        other.zero_->value_ = cur_zero_->value_;


        // Node *cur_head_= new Node (value_type());
        // Node *cur_tail_ = new Node (value_type());
        // Node *cur_zero_ = new Node (value_type());
        // cur_head_= head_;
        // cur_tail_ = tail_;
        // cur_zero_ = zero_;
        // size_t t = size_;

        // head_= other.head_;
        // tail_ = other.tail_;
        // size_ = other.size_;
        // zero_ = other.zero_;
        // zero_->value_ = other.zero_->value_; // добавила 

        // other.head_= cur_head_;
        // other.tail_ = cur_tail_;
        // other.size_ = t;
        // other.zero_ = cur_zero_;
        // other.zero_->value_ = value_type ();
    }


    template <typename T>
    inline void List<T>::merge(List &other)
    {
//         При вызове merge, итераторы обоих списков сравниваются. Если текущий элемент первого списка меньше или равен элементу во втором списке, итератор первого списка перемещается к следующему элементу. В противном случае элемент из второго списка перемещается перед элементом первого списка.

// Процесс продолжается до тех пор, пока все элементы второго списка не будут перемещены и включены в первый список. В результате, первый список становится отсортированным списком, содержащим все элементы исходных списков, а второй список становится пустым.
    auto it = begin();
    Node * tmp = zero_;
    for (iterator it2 = other.begin(); it2 != other.end(); ){
        
        if (*it <= *it2){
            // cout << "IT1 < IT2__  " << *it  << " and " << *it2 << endl;
            // it->pPrev_ = 
            it.iterNode_->pPrev_ = tmp; // надо попробовать  сделать возврат на старый элемент
            it++;
        } else {
            // cout << "IT1 > IT2__  " << *it  << " and " << *it2 << endl;
            insert(it, *it2);
            other.erase(it2);
            it2++;
            zero_->value_ = size_;
            // cout << "IT1 > IT2_2_ " << *it  << " and " << *it2 << endl;
        }
        tmp = it.iterNode_;

        // it2++;
        other.zero_->value_ = value_type ();
        other.head_ = other.tail_ = other.zero_;
        other.zero_->pNext_ = other.head_;
        other.zero_->pPrev_ = other.tail_;


    
    }

    }

    template <typename T>
    inline void List<T>::splice(const_iterator pos, List &other)
    {
    //     // const_iterator it1 = --cend();
    //     // // не обрабатывает, если передаешь begin
    //     // for(const_iterator it2 = pos; it2 != other.cend(); it1++, it2++){
    //     //    Node *current = new Node (it2.iterNode_->value_, it1.iterNode_->pPrev_, it1.iterNode_);
    //     // }
    //     // const_iterator it1 = cbegin();


    //     // for(const_iterator it1 = cbegin(); it1 != cend(); it1++){
    //     //     cout << "1111111 " << endl; 
    //     //     if(pos == it1){
    //     //         cout << "222222 " << endl;
    //     //         Node *tmp = it1.iterNode_;
    //     //         cout << tmp->value_ << endl;
    //     //         for(const_iterator it2 = other.cbegin(); it2 != other.cend(); it2++){
    //     //             // cout << "33333 " << endl;
    //     //             // it1.iterNode_->value_  = it2.iterNode_->value_;
    //     //             // it1.iterNode_ = it2.iterNode_;
    //     //             it1.iterNode_->pPrev_ = new Node(*it2, it1.iterNode_->pPrev_, tmp->pPrev_);
    //     //             size_++;
    //     //             // const_iterator  it(it2);
    //     //             // it2.iterNode_ = nullptr;
    //     //             cout << *it1 << endl;
    //     //             it1++;
    //     //             // cout <<  endl;
    //     //         }
                
    //     //         it1.iterNode_->pNext_ = tmp;
    //     //         // it1++;
    //     //         cout <<  endl;

    //     //     }

    //     // }

    // Node *tmp = pos.iterNode_;
    // iterator ith (other.head_);
    // iterator itt (other.tail_);
    // // iterator it_t2 (pos.iterNode_->pPrev_);
    // // it_t2.iterNode_->pNext_ = ith.iterNode_;

    // // cout << "pos.iterNode_->pPrev_->pNext_ " << pos.iterNode_->pPrev_->pNext_->value_ << endl;
    // // cout << "pos.iterNode_->pPrev_->pNext_ " << pos.iterNode_->pPrev_->pNext_->value_ << endl;
    // pos.iterNode_->pPrev_->pNext_ = ith.iterNode_;
    
    // // cout << "pos.iterNode_->pPrev_->pNext_ " << pos.iterNode_->pPrev_->pNext_->value_ << endl;
    // // pos.iterNode_->pPrev_ = itt.iterNode_;

    // // cout << "ith.iterNode_->pPrev_ " << ith.iterNode_->pPrev_->value_ << endl;
    // ith.iterNode_->pPrev_ = pos.iterNode_->pPrev_;
    // // zero_ = tail_;
    
    // // cout << "pos.iterNode_->pPrev_ " << pos.iterNode_->pPrev_->value_ << endl;
    //   // head_ = pos.iterNode_->pPrev_->pNext_;
    // // tail_ = pos.iterNode_->pPrev_->pNext_;
    // if(pos == cbegin()){
    //     cout << "CBEGIN == POS "  << endl;
    //     head_ = itt.iterNode_;
    //     // zero_->pNext_  = 
    // }
    // if(pos == cend()){
    //     cout << "CEND == POS "  << endl;
    //     cout << zero_->pPrev_->value_ << " zero_->pPrev_ == --itt.iterNode_ " << itt.iterNode_->pPrev_->value_  << endl;
    //     zero_ /*= tail_ */= itt.iterNode_->pNext_ ;
    // }
    // tmp->pPrev_ = ith.iterNode_;
    // itt.iterNode_->pNext_ = tmp;
    
    // size_ += other.size_;
    // zero_->value_ = size_;
     
    // other.size_ = 0;
    // // other.head_ = *other.tail_ = 0;
    // // other.zero_ = nullptr;
    // // other.erase(zero_);
    // // other.clear();


    // // cout << "ith_ " << *ith << endl;
    // // cout << "itt_ " << *itt << endl;
    // // cout << "it_t2_ " << *it_t2 << endl;
    // // cout << "pos.iterNode_->pPrev_ " << pos.iterNode_->pPrev_->value_ << endl;
    // // cout << "ith.iterNode_         " << ith.iterNode_->value_ << endl;
    // // tmp->pPrev_ = itt.iterNode_;
    // // cout << "tmp->pPrev_ " << tmp->pPrev_->value_ << endl;
    // // cout << "tmp->pNext_ " << tmp->pNext_->value_ << endl;

    // // itt.iterNode_->pNext_ = tmp;

    // // pos.iterNode_->pPrev_->pNext_ = ith.iterNode_;



    // cout << "tail_ " << tail_->value_ << endl;
    iterator it2 (pos.iterNode_);
    for(iterator it = other.begin(); it != other.end(); it++){
        
        // cout << "IT2_ " << *it2 << endl;
        insert(it2, *it);
        other.erase(it);
        // other.head_ = other.tail_ = other.zero_;
        // other.head_ = other.tail_ = nullptr;
        // it2++;
        // size_ += other.size_;
        // other.zero_ = nullptr;
        zero_->value_ = size_;        
    }
        // other.size_ = 0;
        // other.head_ = nullptr;
        // other.tail_ = nullptr;
        // other.clear();

        other.zero_->value_ = value_type ();
        other.head_ = other.tail_ = other.zero_;
        other.zero_->pNext_ = other.head_;
        other.zero_->pPrev_ = other.tail_;

    // template <typename T>
    // inline void List<T>::reverse()
    // {


    }

    template <typename T>
    inline void List<T>::reverse()
    { 
        Node *tmp = head_;
        for (auto it = begin(); it != end(); it--){
            // cout << "IT " << *it /* " Next " << it.iterNode_->pNext_ << " Prev " << it.iterNode_->pPrev_ */<< endl;
            std::swap(it.iterNode_->pNext_ , it.iterNode_->pPrev_);
            // it.ptr_->pNext_
            // it.iterNode_->pNext_ = 5;
        }

        std::swap(zero_->pNext_ , zero_->pPrev_);
        head_ = tail_;
        tail_ = tmp;
        

        // Попробовать сделать через итераторы, без доп листа




    //     if (first_ != nullptr) {
    // show();        



// ______________
    // List <T> tmp_l (*this);
    // // tmp.show();  
    // // clear();
    // // show(); 
    // Node *tmp = tmp_l.head_;
    // clear();
    // for (int i = 0; i < tmp_l.size_; i++){
    //     // head_= tmp.head_;
    //     // this.pNext_ = tmp.pPrev_;
    //     // pPrev_ = tmp.pNext_;
    // // tmp->pNext_ = new Node<T>(this-> , tmp);  
    //     // cout << "Value_ "  << endl;
    //     push_front(tmp->value_);
    //     tmp = tmp->pNext_;
    // // tmp.

    // }

// __________

    // head_= tmp->tail_;




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



    template <typename T>
    inline void List<T>::unique()
    {
        // cout << "Unique" << endl;

        iterator it = begin();
        Node *prev = it.iterNode_->pPrev_;
        // cout<< "Test " << prev->value_ << endl;
        for (; it != end(); it++){
            // cout<< "Test " << prev->value_ << " and " << *it << endl;
            // cout << "  !!!    " << endl;
            // cout << *s21_it_12<< " / " ;      
            if (prev->value_ == *it){
                // cout << "Unique==" << endl;
                erase (it);
                // it++;
            }

            // prev = *it;
            prev->value_ = *it;
            // it++;
        }
    }


    template <typename T>
    inline void List<T>::sort()
    {   
        if (!this->empty()) {

        // iterator it = begin();
        // Node * tmp = it.iterNode_;
        for (const_iterator it1 = cbegin(); it1 != cend(); it1++){
            for (const_iterator it2 = cbegin(); it2 != --cend(); it2++){  
                // cout << " and " <<  endl;
                // cout << it2.iterNode_->value_ << " and " << it2.iterNode_->pNext_->value_ << endl;
                if(it2.iterNode_->value_ > it2.iterNode_-> pNext_->value_){
                    std::swap(it2.iterNode_->value_, it2.iterNode_->pNext_->value_);
                    // it2.iterNode_->pPrev->pNext_
                    // cout << it2.iterNode_->value_ << " and " << it2.iterNode_->pNext_->value_ << endl;
                }
            // it2++;
            
            }
        }


        // for (const_iterator it1 = cbegin(); it1 != cend(); it1++){
        //     cout << it1.iterNode_->value_ << " and " << it1.iterNode_->pNext_->value_ << endl;
        // }

        // reverse();
        }
    }

    // template <typename T>
    // void List<T>::push_node(iterator pos, const_reference value_)
    // {
    //     auto it = begin();
    //     while(pos != it){
    //         it++;
    //     }
        
    //     Node *current = new Node (value, it.iterNode_->pPrev_, it.iterNode_);
    //     // Node *current = new Node (value);
    //     // cout << current->value_ << endl;

    //     // cout << it.iterNode_->pPrev_->value_ << endl;
    //     // cout << it.iterNode_->pPrev_->pNext_->value_ << endl;
    //     // cout << endl;

    //     it.iterNode_->pPrev_->pNext_ = current;
    //     it.iterNode_->pNext_->pPrev_ = current;

    //     // cout << current->value_ << endl;
    //     // cout << it.iterNode_->pPrev_->value_ << endl;
    //     // cout << current->pNext_->pNext_->pNext_->value_ << endl;
    //     // cout << current->pPrev_->pNext_->value_ << endl;

    //     size_++;


    // }


    template <typename T>
    void List<T>::push_back(const_reference value)
    {
        insert(++iterator(tail_), value);

        // cout << "Create NODE" << endl;
        // Node/*<value_type>*/ *current = new Node/*<value_type>*/(value, zero_, zero_);
        // // Node/*<value_type>*/ *current = new Node/*<value_type>*/(value, nullptr, nullptr); // добавить аргументы
        // // current->pNext_ = zero_; // надо
        // // current->value_ = value;
        // // cout << "Value_ " << current->value_   << endl;
        // // cout << "00000" << endl;

        // if(head_ == zero_){ // сюда теоретически не должен заходить / заходит
        
        // // cout << "Value_ " << zero_->value_   << endl;
        // // cout << "Value_ " << current->value_   << endl;
        // // cout << "Create NODE_1" << endl;
        // zero_->pNext_ = zero_->pPrev_ = current; // добавила
        // // cout << "Value_1 " << current->value_   << endl;
        // current->pNext_ = current->pPrev_ = zero_;
        // // cout << "Value_2 " << current->value_   << endl;
            
           
        //     // cout << "oo "  /* << zero_->pNext_<<  zero_->pPrev_ */ << zero_<< endl;
        
           
            
        //     head_= tail_ = current;
            
        // // cout << "Create NODE_4" << endl;
        // } else {
        //     // cout << "Create NODE_2+" << endl;
        //     current->pPrev_ = tail_;
        //     //  cout << "Create NODE_2+_1" << endl;
        //     tail_->pNext_ = current;
        //     // cout << "Create NODE_2+_2" << endl;
        //     tail_ = current;
        //     // cout << "Create NODE_2+_3" << endl;

        //     // current->pNext_ = zero_;
        //     zero_->pPrev_ = tail_;
        //     // cout << "Create NODE_2+_4" << endl;

        //     // zero_->value_ = 

        //     //  current->pPrev_ = tail_;
        //     // //  cout << "Create NODE_2+_4" << endl;
        //     // tail_->pNext_ = current;
        //     // // tail_ = current;
        //     // zero_->value_ = current->value_;
        //     // iterator  it = begin();
        //     // cout << "IT _ " << *it << endl;
        //     zero_->value_ = size_ + 1;
        //     // cout << "Create NODE_2+_5" << endl;


        // }
        // // cout << "Create NODE_6" << endl;
        // // if(head_== nullptr){
        // //     head_= new Node<T>(value);
        // // } else {
        // //     Node<T> *current = this-> head_;
        // //     while (current->pNext_ != nullptr)
        // //     {
        // //         current = current->pNext_;
        // //     }
        // //     current = new Node<T>(value);
        // // }
        // size_++;
    }


    template <typename T>
    void List<T>::push_front(const_reference value)
    {
        insert(iterator(head_), value);
        
        // Node/*<value_type>*/ *current = new Node/*<value_type>*/(value, zero_, zero_);
        // // current->pPrev_ = zero_; // надо
        // // current->value_ = value;
        // // zero_->value_ = value; // так то не надо

        // if(head_ == zero_){
        //     zero_->pNext_ = zero_->pPrev_ = current; // добавила
        //     current->pNext_ = current->pPrev_ = zero_;
        //     head_ = tail_ = current;
        // } else {
        //     current->pNext_ = head_;
        //     head_->pPrev_ = current;
        //     head_ = current;
        //     zero_->pNext_ = head_;
        //     zero_->value_ = size_ + 1;
        // }
        // size_++;

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
        // return typename List<T>::iterator(zero_->pNext_); // почему то выдает утечку
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
    // inline typename List<T>::iterator List<T>::cend()
    // {
    //     // return typename List<T>::iterator(tail_);
    //     return typename List<T>::iterator(zero_);
    // }


    template <typename T>
    inline typename List<T>::const_iterator List<T>::cbegin()
    {
        // ListIterator it (head_);
        return typename List<T>::const_iterator(zero_->pNext_);
        // return ListIterator<T>::this->begin();

            // iterator begin() const noexcept { return iterator(fake_node_->pNext__); }
        // return  it;
    }


    template <typename T>
    inline typename List<T>::const_iterator List<T>::cend()
    {
        // return typename List<T>::iterator(tail_);
        return typename List<T>::const_iterator(zero_);
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
        // removeAt(size_ - 1);               
        erase(--end());
        tail_->pPrev_->pNext_ = zero_; // убрать, когда erase , будет удалять последний элемент, правильно)
        tail_ = tail_->pPrev_; 
        zero_->pPrev_ = tail_;
    }


    template <typename T>
    bool List<T>::empty() {return head_ == zero_;}


    template <typename T>
    void List<T>::show()
    {
        Node *tmp = head_;
        for(int i = 0; i < size_; i++){ // for
            cout << tmp->value_ << " x ";
            tmp = tmp->pNext_;
        } 
        cout  << endl; 
        cout << "SIZE " << size()  << endl;
        cout  << endl;
    }

    template <typename T>
    T &List<T>::operator[](const int index)
    // обработать обращение за пределы, на несуществующий элемент
    {
        cout << "operator[]" << endl;
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
};
#endif  // SRC_S21_CONTAINERS_OOP_H_