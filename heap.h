#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

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
  std::vector<T> info;
  int d; // max # of branches a node can have
  PComparator comp;
  void trickleUp(int loc);
  void trickleDown();

};

// Add implementation of member functions here


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
    throw std::underflow_error("Unable to obtain top from empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return info.front();
  
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Unable to pop from empty heap");
    return;
  }
  // trickleDown always called on index 0
  info[0] = info.back();
  info.pop_back();
  trickleDown();

}

template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c){
  d = m;
  comp = c;
}

template <typename T, typename Comparator>
Heap<T,Comparator>::~Heap(){
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  // trickle up
  info.push_back(item);
  trickleUp(info.size()-1);

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return info.empty();

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return info.size();

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
  int parent = (loc-1)/d; 
  while(parent >= 0)
  { 
    if(comp(info[loc], info[parent])){
      T tempLoc = info[loc];
      info[loc] = info[parent];
      info[parent] = tempLoc;
      loc = parent;
      parent = (loc-1)/d;
    }
    else{
      break;
    }
  }

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown()
{
  int loc = 0;
  //check if leaf node
  if(info.size() <= 1){
    return;
  }

  int children[d+1]; // array of indicies of children of d-ary heap
  while(true)
  {
    for(int i = 1; i <= d;i++){ // fills array with index if valid, else -1
      children[i] = ((d*loc + i) < (int)(info.size())) ?
        (d*loc + i) : -1;
    }
    
    if(children[1] == -1){
      break;
    }
    //std::cout <<children[1] << " .... " << children[2] <<std::endl;
    T bestChild;
    bestChild = info[children[1]]; //initialize a "best child" with first child 
    int bestChildIndex = children[1];

    for (int i = 1; i <= d; i++)
      {
        if (children[i] != -1)
          {
            if(comp(info[children[i]],bestChild)){

              bestChildIndex = children[i];
              bestChild = info[children[i]];
            }
          }
      }
    
    if(children[1] == -1){
      break;
    }
    if (comp(info[bestChildIndex], info[loc])){
      // std::cout << "TESTING123" <<std::endl;
      T temploc = info[loc];
      info[loc] = info[bestChildIndex];
      info[bestChildIndex] = temploc;

    }

      loc = bestChildIndex;

  }
  
}

#endif

