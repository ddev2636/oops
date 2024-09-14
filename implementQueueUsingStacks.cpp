#include <bits/stdc++.h>
using namespace std;

// push(x)
//  s1->s2;
//  x->s1;
//  s2->s1;

// pop()
//  s1.pop();

struct Queue
{
    stack<int> s1, s2;
    bool isEmpty()
    {
        return (s1.empty());
    }
    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty())
        {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
    int front()
    {
        return s1.top();
    }
    int size()
    {
        return s1.size();
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << q.deQueue() << '\n';
    q.enQueue(1);
    cout << "front" << q.front() << endl;
    cout << "size" << q.size() << endl;
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.isEmpty() << '\n';

    return 0;
}
