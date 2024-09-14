#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int arr[MAX_SIZE];
    int front;
    int end;

public:
    Queue()
    {
        front = 0;
        end = 0;
    }
    bool isEmpty()
    {
        if (front == end)
        {
            cout << "Queue is empty" << endl;
            return true;
        }
        return false;
    }
    void push(int number)
    {
        arr[end] = number;
        cout << "Element " << arr[end] << " pushed" << endl;
        end++;
    }
    int pop()
    {
        front++;
        cout << "Element " << arr[front - 1] << " popped" << endl;
        return arr[front - 1];
    }
    int Front()
    {
        cout << "Front element is:" << arr[front] << endl;
        return arr[front];
    }
    int size()
    {
        return end - front;
    }
};

int main()
{
    Queue queue;
    cout << queue.isEmpty() << endl;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    cout << queue.isEmpty() << endl;
    queue.pop();
    cout << queue.Front() << endl;
    queue.pop();
    cout << queue.Front() << endl;
    cout << queue.size() << endl;
    return 0;
}
