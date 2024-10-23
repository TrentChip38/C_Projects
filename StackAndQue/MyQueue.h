#pragma once
#include <iostream>
using namespace std;

// MyQueue class template
template <class T>
class MyQueue {
    //an array, and pointers to front and end, beggining and top
    T queue[10], * front, * end, *beg, *top;
    int s;//size
public:
    MyQueue();
    T peek();
    T pop(); 
    void push(T i);
    void clear();
    int size();
    int full();
    int empty();
};

/*************************************************
* @name MyQueue
* @brief Constructor for a queue array using the class MyQueue
* @param None
* @retval None
*************************************************/
template <class T>
MyQueue<T>::MyQueue() {
    //set all variables
    //front and end start in first spot
    front = &queue[0];
    end = &queue[0];
    //beggining set to beggining spot
    beg = &queue[0];
    //top set to top spot of array
    top = &queue[9];
    //start size at 0
    s = 0;
}

/*************************************************
* @name peek
* @brief non-destructively returns the value at front of the queue
* @param None
* @retval front value of queue (type of class <T>: char, float, or int)
*************************************************/
template <class T>
T MyQueue <T>::peek()
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
        cout << "Exception: Tried to peek at an empty queue!" << '\n';
        return 0;
    }
    //return front value
    T retval;
    retval = *(front);
    return retval;
}

/*************************************************
* @name pop
* @brief remove and return front of queue
* @param None
* @retval front of queue (type of class <T>: char, float, or int)
*************************************************/
template <class T>
T MyQueue <T>::pop()
{
    //try if full print exception
    try
    {
        if (empty()) {
            throw 3;
        }
    }
    catch (int e)
    {
        cout << "Exception: Tried to pop from an empty queue!" << '\n';
        return 0;
    }
    //get value of front
    T retval;
    retval = *front;
    //get rid of and advance front spot
    *front = 0;
    //advance looping around if in last spot
    if (front == top) {
        front = beg;
    }else front++;//else advance normally

    //size minus 1
    s--;
    //return value
    return retval;
}

/*************************************************
* @name push
* @brief put variable on top of queue
* @param variabe (type of class <T>: char, float, or int)
* @retval None
*************************************************/
template <class T>
void MyQueue<T>::push(T i)
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
        cout << "Exception: Tried to push to a full queue!" << '\n';
        return;
    }
    //set end spot(put value on queue)
    *end = i;
    //advance end
    if (end == top) {
        end = beg;
    }
    else end++;
    //size plus one
    s++;
}

/*************************************************
* @name clear
* @brief clears the whole queue
* @param None
* @retval None
*************************************************/
template <class T>
void MyQueue <T>::clear()
{
    //loop while anything left in queue
    while (s > 0) {
        //decrement end
        if (end == beg) {
            end = top;
        }
        else {
            end--;
        }
        //set spot to 0
        *end = 0;
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
int MyQueue <T>::size()
{
    return s;
}

/*************************************************
* @name full
* @brief returns true if queue is full
* @param None
* @retval int 1 if full, 0 if not
*************************************************/
template <class T>
int MyQueue <T>::full()
{
    if (s == 10) { return 1; }
    else { return 0; }
}

/*************************************************
* @name empty
* @brief returns true if queue is empty
* @param None
* @retval int 1 if empty, 0 if not
*************************************************/
template <class T>
int MyQueue <T>::empty()
{
    if (s == 0) return 1;
    else return 0;
}