#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }

    void push(int item)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push item " << item << endl;
            return;
        }
        arr[++top] = item;
        cout << "Pushed item " << item << " into the stack." << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop item." << endl;
            return -1;
        }
        int item = arr[top--];
        return item;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Size of stack: " << stack.size() << endl;
    cout << "Top element: " << stack.peek() << endl;

    cout << stack.pop() << " popped from stack." << endl;
    cout << stack.pop() << " popped from stack." << endl;

    cout << "Size of stack: " << stack.size() << endl;
    cout << "Top element: " << stack.peek() << endl;

    return 0;
}
