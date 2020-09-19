#include <iostream>
#include <stdexcept>
using namespace std;

#include "StackLinked.h"


template <typename DataType>
  StackLinked<DataType>::StackLinked(int maxNumber /*defaulted parameter*/) {
  top = nullptr;
}


template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other) {

  *this = other;

}


template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other) {

  StackNode* otherCurr = other.top;
  StackNode* lastNode = nullptr;
  StackNode* newNode = nullptr;

  if( this == &other ) {

    return *this;
  }

// case: other stack is empty
  if( other.isEmpty() ) {

  }

  else {
    top = new StackNode(other.top->dataItem, nullptr);
    StackNode * previous_node = top;


    while( otherCurr->next != nullptr ) {

      otherCurr = otherCurr->next;

      newNode = new StackNode(otherCurr->dataItem, nullptr);

      lastNode->next = newNode;


      previous_node = previous_node->next;

    }
  }

  return *this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked() {

  clear();
}

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr) {

  dataItem = nodeData;
  next = nextPtr;

}


template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error){

  StackNode* newNode = nullptr;

  if( !isFull() ) {

    if( isEmpty() ) {

      newNode = new StackNode(newDataItem, nullptr);
    }

    else {

      newNode = new StackNode(newDataItem, top);
    }

   
    top = newNode;

    
    newNode = nullptr;
  }

  else {
    throw logic_error("Stack is full!");
  }

}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error) {

  DataType topData;
  StackNode* prevTop;
if (!isEmpty()){

  if( isEmpty() ) {
    throw logic_error("Stack is empty!");
    return 0;
   
  }

  else {
   
    prevTop = top;
    topData = top->dataItem;

   
    top = top->next; 

   
    delete prevTop;
    prevTop = nullptr;

   
    return topData;
  }
}
}

template <typename DataType>
void StackLinked<DataType>::clear() {

  while( !isEmpty() ) {
    
    pop();
  }


}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const{

  if( top == nullptr ) {
   
    return true;
  }

  else {
  
    return false;
  }


}


template <typename DataType>
bool StackLinked<DataType>::isFull() const {



  return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const



{
  if( isEmpty() )
  {
   cout << "This is an empty stack" << endl;
 }
 else
 {
  cout << "Top of the stack\t";
  for (StackNode* temp = top; temp != 0; temp = temp->next) {
    if( temp == top ) {
     cout << "[" << temp->dataItem << "]\t";
   }
   else {
     cout << temp->dataItem << "\t";
   }
 }
 cout << "Bottom of the stack" << endl;
}

}
