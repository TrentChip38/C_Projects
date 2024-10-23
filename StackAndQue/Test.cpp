#include <iostream> 
#include "MyStack.h" 
#include "MyQueue.h" 
#define co 65
using namespace std;

int main()
{
    MyStack <char> s1;
    MyQueue <char> q1;
    int i;

    cout << "Filling stack and queue." << endl;

    for (i = (0 + co); i < (11 + co); i++)
    {
        s1.push(i);
        q1.push(i);
        cout << "Top of stack = " << s1.peek() << "\t" <<
            "Stack size = " << s1.size() << endl;
        cout << "Front of queue = " << q1.peek() << "\t" <<
            "Queue size = " << q1.size() << endl;
    }
    cout << "Emptying stack and queue." << endl;

    for (i = (0+co); i < (11+co); i++)
    {
        s1.pop();
        cout << "Top of stack = " << s1.peek() << "\t" <<
            "Stack size = " << s1.size() << endl;
    }
    for (i = (0 + co); i < (7 + co); i++)
    {
        q1.pop();
        cout << "Front of queue = " << q1.peek() << "\t" <<
            "Queue size = " << q1.size() << endl;
    }
    for (i = (0 + co); i < (6 + co); i++)
    {
        q1.push(i);
        cout << "Front of queue = " << q1.peek() << "\t" <<
            "Queue size = " << q1.size() << endl;
    }
    for (i = (0 + co); i < (6 + co); i++)
    {
        q1.pop();
        cout << "Front of queue = " << q1.peek() << "\t" <<
            "Queue size = " << q1.size() << endl;
    }

    return 0;
}