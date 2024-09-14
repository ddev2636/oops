#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class CircularQueue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void push(int number)
    {
        if (isFull())
        {
            cout << "Queue full" << endl;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = number;
            if (front == -1)
            {
                front = rear; // Set front to the first element in the queue
            }
            cout << number << " pushed" << endl;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Empty queue" << endl;
            return -1;
        }
        else
        {
            int number = arr[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % MAX_SIZE;
            }
            cout << number << " popped" << endl;
            return number;
        }
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Empty queue" << endl;
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        if (isEmpty())
        {
            return 0;
        }
        else if (front <= rear)
        {
            return rear - front + 1;
        }
        else
        {
            return MAX_SIZE - front + rear + 1;
        }
    }

    bool isFull()
    {
        return (front == (rear + 1) % MAX_SIZE);
    }
};

int main()
{
    CircularQueue cq;
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.push(6); // Trying to push into a full queue
    cout << cq.Front() << endl;

    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop(); // Trying to pop from an empty queue

    return 0;
}
