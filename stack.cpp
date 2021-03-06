
#include <stdio.h>
using namespace std;

/**
 * @file stack.cpp
 * Implementation of the Stack class.
 *
 */

/**
 * Default constructor. Remember to initialize any variables you need
 * and allocate any required memory. The initial size of `items` should
 * be DEFAULTCAPACITY defined in stack.h.
 *
 */
template <class T> Stack<T>::Stack()
{
    /**
     * @todo Your code here!
     */
    size_t max_items = DEFAULTCAPACITY;
    items = new T[max_items];
    size_t num_items = 0;

}

/**
 * Destructor. Remember to free any memory allocated.
 *
 */
template <class T> Stack<T>::~Stack()
{
    /**
     * @todo Your code here!
     */
    delete [] items;
}

/**
 * Adds the parameter object to the top of the Stack. That is, the
 * element should go at the beginning of the list. If the dynamic array
 * holding the stack elements is full the array should be resized. Resize should be
 * called by multiplying  current capacity EXPANSIONFACTOR defined in stack.h.
 * To be clear resize should happen before adding the element to the stack and only
 * when the stack is completely full.
 *
 * @param value The object to be added to the Stack.
 */
template <class T>
void Stack<T>::push(const T &newItem){

    if (num_items >= max_items) {
        max_items = max_items * EXPANSIONFACTOR;
        resize(max_items);
    }

    int num_items_int = num_items;
    for (int i=(num_items_int - 1); i > -1; i--) {
        items[i+1] = items[i];
    }
    
    
    items[0] = newItem; //items[0] = &newItem;
    num_items = num_items + 1;
    
};

/**
 * Removes the object on top of the Stack, and returns it. That is, remove
 * the element at the beginning of the list. You may assume this function
 * is only called when the Stack is not empty. If the size of the stack changes
 * to strictly less than 1 / SHRINKRATE (where SHRINKRATE is defined in stack.h)
 * after the item is removed the Stack should be resized to 1 / EXPANSIONFACTOR.
 *
 * @return The element that used to be at the top of the Stack.
 */
template <class T>
T Stack<T>::pop(){

    T temp1 = items[0]; //T temp1 = *items[0];
    items[0] = NULL;
    num_items = num_items - 1;

    for (int i=1; i <= num_items; i++) {
        items[i-1] = items[i];
        items[i] = NULL;
    }

    if (num_items < (max_items / SHRINKRATE)) {
        max_items = max_items / EXPANSIONFACTOR;
        resize(max_items);
    }

    return temp1;
};

/**
 * Adds an element to the ordering structure.
 *
 * @see OrderingStructure::add()
 */
template <class T> void Stack<T>::add(const T &theItem)
{

    push(theItem);

}

/**
 * Removes an element from the ordering structure.
 *
 * @see OrderingStructure::remove()
 */
template <class T> T Stack<T>::remove()
{

    pop();

}

/**
 * Finds the object on top of the Stack, and returns it to the caller.
 * Unlike pop(), this operation does not alter the Stack itself. It should
 * look at the beginning of the list. You may assume this function is only
 * called when the Stack is not empty.
 *
 * @return The element at the top of the Stack.
 */
template <class T>
T Stack<T>::peek(){

    T temp = items[0];
    return temp;

};

/**
 * Determines if the Stack is empty.
 *
 * @return Whether or not the stack is empty (bool).
 */
template <class T>
bool Stack<T>::isEmpty() const {
    return (num_items == 0);
};

/**
 * Return the maximum number of items the stack can hold.
 *
 * Note: This is an implementation detail we would normally hide.
 * We include it here for testing purposes.
 *
 * @return Maximum number of items the stack can hold (int)
 */
template <class T>
size_t Stack<T>::capacity() const {
    return max_items;
};

/**
 * Return the number of items on the stack.
 *
 * @return Number of items on the stack (int)
 */
template <class T>
size_t Stack<T>::size() const {
    return num_items;
};

/**
 * Resize the the member variable `items`.
 * Don't forget to free up any memory that is no longer used.
 *
 * @param n The size of the stack after resizing
 */
template <class T>
void Stack<T>::resize(size_t n){

        T* temp;
        temp = new T[n];
        for (int i = 0; i < num_items; i++) {
            temp[i] = items[i];  //temp[i] = items[i]; 
        }

       delete [] items;
       items = temp;

};
