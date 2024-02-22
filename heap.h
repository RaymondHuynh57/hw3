#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> vector_heap;
  int m_ary;
  PComparator predicate;


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): m_ary(m), predicate(c){
/*
    m_ary = m;
    predicate = c;
*/
    //std::cout << "HEAP CONSTRUCTOR" << std::endl;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
    //std::cout << "HEAP DESTRUCTOR" << std::endl;
}
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
    //std::cout << "PUSH " << item << std::endl;
    vector_heap.push_back(item);
    //std::cout << "item: " << item << std::endl;
    int beg_index = (int) (vector_heap.size() - 1);
    while(true){  //Use while true and then break based off of an if condition fron now on
        //int parent_index = (beg_index/2) - 1;
        int parent_index = ((beg_index - 1)/2);
        //std::cout << "WHILE LOOP" << std::endl;
        //std::cout << "PARENT INDEX: " << parent_index << std::endl;
        //std::cout << std::boolalpha << "TRUE OR FALSE: " << predicate(vector_heap[beg_index], vector_heap[parent_index]) << std::endl;
        if(parent_index >= 0 && predicate(vector_heap[beg_index], vector_heap[parent_index])){
            //std::cout << "SWAP" << std::endl;
            //std::swap(vector_heap[parent_index], vector_heap[beg_index]);
            std::swap(vector_heap[beg_index], vector_heap[parent_index]);
            beg_index = parent_index;
        }else{
            break;
        }


    }
    //std::cout << "------------>" << std::endl;
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
    //std::cout << "TOP" << std::endl;
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error");

  }
  //std::cout << "TOP: " << vector_heap[0] << " END" << std::endl;
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vector_heap[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //std::cout << "POP" << std::endl;
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error");

  }
  //vector_heap.pop_back();
  //Steps

  std::swap(vector_heap[0], vector_heap[vector_heap.size() - 1]);
  vector_heap.pop_back();

  int beg_index = 0;
  int chosen_index = beg_index;
  while(true){
      int left_index = 2 * beg_index + 1;
      int right_index = left_index + 1;

      if(left_index < (int) vector_heap.size()){
          chosen_index = left_index;
      }

      if(right_index < (int) vector_heap.size() && predicate(vector_heap[right_index], vector_heap[left_index])){
          chosen_index = right_index;
      }


      if(!predicate(vector_heap[chosen_index], vector_heap[beg_index])){
          break;
      }

      std::swap(vector_heap[chosen_index], vector_heap[beg_index]);
      beg_index = chosen_index;
  }




}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
    return vector_heap.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
    return vector_heap.size();
}



#endif

