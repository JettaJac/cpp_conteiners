#ifndef SRC_S21_CONTAINERS_S21_QUEUE_H_
#define SRC_S21_CONTAINERS_S21_QUEUE_H_

#include <iostream>
#include <memory>
#include "list.h"

using namespace std;


namespace s21{  
template<typename T, typename Container = s21::List<T>>
class Queue {

    public:
    using value_type = T;  // defines the type of an element (T is template parameter)
    using reference = T&; // defines the type of the reference to an element
    using const_reference = const T&; // defines the type of the constant reference
    using size_type = std::size_t; // size_t defines the type of the container size (standard type is size_t)
    
    Queue() : basecontainer_ () {}; // default constructor, creates empty queue
    //Queue(std::initializer_list<value_type> const &items)
    
    bool empty() {return basecontainer_.empty();};
    size_type size() {return basecontainer_.size();};
    
    private:
    Container basecontainer_; // !!! не уверено, что правильно написана в соответсвие с кодстайлом
};
}
#endif  // SRC_S21_CONTAINERS_S21_QUEUE_H_