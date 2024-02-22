#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
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
private:
    std::vector<T> stack_vector;    //Composition. Has - a relationship
};

//LIFOS - Last In First Out Stack
template <typename T>
Stack<T>::Stack(){

}

template <typename T>
Stack<T>::~Stack(){

}
template <typename T>
bool Stack<T>::empty() const{
    return stack_vector.empty();
}

template <typename T>
size_t Stack<T>::size() const{
    return stack_vector.size(); //Can use const methods only
}

template <typename T>
void Stack<T>::push(const T& item){ //Usually, one pointer parameter or memory parameter can modify inner content. However, since const is before that, that means that I can't modify the one level below
    stack_vector.push_back(item); //O(1)
}

template <typename T>
void Stack<T>::pop(){

    if(empty()){
        throw std::underflow_error("Underflow Error");
        
    }
    stack_vector.pop_back();  //O(1)
}

template <typename T>
const T& Stack<T>::top() const{

    if(empty()){
        throw std::underflow_error("Underflow Error");
        //throw underflow_error();
    }
    return stack_vector.back(); //back is a const method for the vector instance
    //returning const T& will make it that you can't change on level lower. So I can't change the content of the returned value after this.
}

#endif