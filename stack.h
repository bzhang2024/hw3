#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

};

//constructor
template <typename T>
Stack<T>::Stack(){

}

//destructor
template <typename T>
Stack<T>::~Stack(){

}

template <typename T>
bool Stack<T>::empty() const {
    //implement
    return std::vector<T>empty(); //this-> not needed 
}

template <typename T>
size_t Stack<T>::size(){
    //impleemt
    return std::vector<T>size(); 
}

template <typename T>
void Stack<T>::push(const T& item) {
    //impelemnt
    std::vector<T>push_back(item);
}

template <typename T>
void Stack<T>::pop() {
    if (std::vector<T>empty()){
        throw std::underflow_error(); 
    }
    std::vector<T>pop_back(); 
}

template <typename T>
const T& Stack<T>::top() const {
    //impelemtn
    if (std::vector<T>empty()){
        throw std::underflow_error(); 
    }
    return std::vector<T>front(); 
}

#endif