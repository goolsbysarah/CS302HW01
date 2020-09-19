
//Sarah Goolsby CS 302 STacks HW

#include <cassert>
#include "StackArray.h"

template<class ItemType> 
StackArray<ItemType>::StackArray(int maxNumber){
	maxSize = maxNumber;
	items = new ItemType[maxNumber];
	top = -1;
}


template<class ItemType> 
StackArray<ItemType>::StackArray(const StackArray& other){
	maxSize = other.maxSize;
    top = other.top;
    items = other.items;
}

template<class ItemType> 
StackArray<ItemType>& StackArray<ItemType>::operator=(const StackArray& other){
	maxSize = other.maxSize;
    top = other.top;
    items = other.items;

	return *this;
}

template<class ItemType> 
bool StackArray<ItemType>::isEmpty() const{
	return top < 0;
}

template<class ItemType> 
bool StackArray<ItemType>::isFull() const{
	return top == maxSize - 1;
}

template<class ItemType> 
void StackArray<ItemType>::showStructure() const{
	if (top < 0)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	for (int i = top; i >= 0; i --)
	{
		cout << items[i] << endl;
	}
}


template<class ItemType>
void StackArray <ItemType>::push(const ItemType& newEntry) throw (logic_error){
	if (top < maxSize -1){
		top ++;
		items[top] = newEntry;
	}
	else{
		throw logic_error("Stack is full!");
	}
}

template<class ItemType>
ItemType StackArray<ItemType>::pop() throw (logic_error){
	if (!isEmpty()){
		return items[top--];
		}
	else
		throw logic_error("Stack is empty!");
}

template<class ItemType>
void StackArray<ItemType>::clear(){
	items = new ItemType[maxSize];
	top = -1;
}

template<class ItemType>
StackArray<ItemType>::~StackArray(){
	delete []items;
}



// template<class ItemType>
// ItemType StackArray<ItemType>::peek() const{
// 	assert (!iseEmpty());
// 	return items[top];
// }
