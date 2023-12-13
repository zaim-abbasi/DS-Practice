// implementing queue using stack
#include<iostream>
#include<stack>
using namespace std;
class Queue{
public:
    stack<int> s1;
    stack<int> s2;
    void enqueue(int data)
    {
        s1.push(data);
    }
    void dequeue()
    {
        if(s1.empty() && s2.empty())
            cout << "Queue is empty" << endl;
        else
        {

            // tarnsfer elements from s1 to s2, during transfer reverse ho jaein gey
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop(); // pop the top element of s2 i.e. front element of s1
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    void display()
    {
        if(s1.empty() && s2.empty())
            cout << "Queue is empty" << endl;
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            while(!s2.empty())
            {
                cout << s2.top() << " ";
                s1.push(s2.top());
                s2.pop();
            }
            cout << endl;
        }
    }
};