#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 

template <typename T, typename PComparator = std::less<T> > //has default parameter
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
  std::vector<T> elements; 
  int m; //m-ary heap
  PComparator comp; 

};

// Add implementation of member functions here

//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) :
  m(m), comp(c)
  {

  }

//destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  //implemtn
  elements.push_back(item);

  int idx = elements.size()-1;

  //trickleup
  /* - find parent node 
  - while current node better than parent node
  - swap the 2
  - otherwise node in right position, break loop */

  int parent = idx/m; 
  while (parent <= 0 && comp(elements[idx], elements[parent])){ //idx better than parent
    std::swap(elements[idx], elements[parent]);
    idx = parent; 
    parent = idx/m; 
  }

}

template <typename T, typename PComparator>
size_t Head<T,PComparator>::size(){
  //implement
  //DONE
  return elements.size(); 
}

template <typename T, typename PComparator>
bool Head<T,PComparator>::empty() const {
  //implement
  //DONE
  return elements.empty(); 
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw underflow_error(); 
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return elements.front(); //element at index 0

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //DONE
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error(); 
  }

  T bestValue = elements[0]; //to-be popped

  elements[0] = elements.back(); //move last element to root

  int current = 0; 
  while (true) {
    int best = current; 
    for (int i = 0; i < m; i++){
      int mthChild = (best*m) + i;
      
      if (mthChild < elements.size() && comp(elements[mthChild], elements[current])){
        best = mthChild; 
      }
    }
    if (best == current){ //node in right spot, no violation of heap property
        break; 
      }
    std::swap(elements[current], elements[best]);
    current = best; //update indices
  }
  return; 

}




#endif

