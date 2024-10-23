//my one question:
//what should be in an empty spot?
//I have it just set spots to 0
//They are ffectively empty 
//and ready to be filled

#pragma once
#include <iostream>
using namespace std;

// MyStack class template
template <class T>
class MyStack {
    //stack has an array, and pointer to top
    T stack[11], * top;
    int s;//size
public:
    MyStack();
    T peek();
    T pop(); 
    void push(T i);
    void clear(); 
    int size(); 
    int full(); 
    int empty();
};

/*************************************************
* @name MyStack
* @brief Constructor for a stack array using the class MyStack
* @param None
* @retval None
*************************************************/
template <class T>
MyStack<T>::MyStack() {
    //set top to first position
    top = &stack[0];
    //start size at 0
    s = 0;
}

/*************************************************
* @name peek
* @brief non-destructively returns the value on top of the stack
* @param None
* @retval top of stack (type of class <T>: char, float, or int)
*************************************************/
template <class T>
T MyStack <T>::peek()
{
    //try if empty print exception
    try
    {
        if (empty()) {
            throw 3;
        }
    }
    catch (int e)
    {
        cout << "Exception: Tried to peek at an empty stack!" << '\n';
        return 0;
    }
    //return value
    T retval;
    retval = *(top-1);
    return retval;
}

/*************************************************
* @name pop
* @brief remove and return top of stack
* @param None
* @retval top of stack (type of class <T>: char, float, or int)
*************************************************/
template <class T>
T MyStack <T>::pop()
{
    //try if empty print exception
    try
    {
        if (empty()) {
            throw 3;
        }
    }
    catch (int e)
    {
        cout << "Exception: Tried to pop from an empty stack!" << '\n';
        return 0;
    }
    //get top value
    T retval;
    top--;
    retval = *top;
    //set to 0
    *top = 0;
    //decrement size
    s--;
    //return value
    return retval;
}

/*************************************************
* @name push
* @brief put variable on top of stack
* @param variabe (type of class <T>: char, float, or int)
* @retval None
*************************************************/
template <class T>
void MyStack<T>::push(T i)
{
    //try if full print exception
    try
    {
        if (full()) {
            throw 3;
        }
    }
    catch (int e)
    {
        cout << "Exception: Tried to push to a full stack!" << '\n';
        return;
    }
    //put value on top
    *top = i;
    //increment size
    s++;
    //move on top
    top++;
}

/*************************************************
* @name clear
* @brief clears the whole stack and starts back at begining
* @param None
* @retval None
*************************************************/
template <class T>
void MyStack <T>::clear()
{
    //loop while stack has values
    while (size() > 0) {
        //go down one
        top--;
        //and set to 0
        *top = 0;
        //decrement size
        s--;
    }
}

/*************************************************
* @name size
* @brief returns size of aray as int
* @param None
* @retval size of array (int)
*************************************************/
template <class T>
int MyStack <T>::size()
{
    return s;
}

/*************************************************
* @name full
* @brief returns true if stack is full
* @param None
* @retval int 1 if full, 0 if not
*************************************************/
template <class T>
int MyStack <T>::full()
{
    if (s == 10) { return 1; }
    else { return 0; }
}

/*************************************************
* @name empty
* @brief returns true if stack is empty
* @param None
* @retval int 1 if empty, 0 if not
*************************************************/
template <class T>
int MyStack <T>::empty()
{
    if (s == 0) return 1;
    else return 0;
}