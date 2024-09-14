#include <iostream>
#include <vector>
using namespace std;

class Structure
{
public:
    virtual bool push(int e) = 0;
    virtual int peek() = 0;
    virtual int pop() = 0;
    virtual int size() = 0;
    virtual vector<int> getData() = 0;

    static Structure *createStructure(string type, int size)
    {
        if (type == "Stack")
        {
            return new Stack(size);
        }
        else if (type == "Queue")
        {
            return new Queue(size);
        }
        return nullptr;
    }
};

class Stack : public Structure
{
private:
    int top_stack;
    vector<int> data;

public:
    Stack(int size)
    {
        data.resize(size);
        top_stack = -1;
    }

    bool push(int e)
    {
        if (top_stack == data.size() - 1)
        {
            return false;
        }
        data[++top_stack] = e;
        return true;
    }

    int peek()
    {
        if (top_stack == -1)
        {
            return -1;
        }
        return data[top_stack];
    }

    int pop()
    {
        if (top_stack == -1)
        {
            return -1;
        }
        return data[top_stack--];
    }

    int size()
    {
        return top_stack + 1;
    }

    vector<int> getData()
    {
        return vector<int>(data.begin(), data.begin() + size());
    }
};

class Queue : public Structure
{
private:
    int front_queue;
    int rear_queue;
    vector<int> data;

public:
    Queue(int size)
    {
        data.resize(size);
        front_queue = 0;
        rear_queue = -1;
    }

    bool push(int e)
    {
        if (rear_queue == data.size() - 1)
        {
            return false;
        }
        data[++rear_queue] = e;
        return true;
    }

    int peek()
    {
        if (front_queue > rear_queue)
        {
            return -1;
        }
        return data[front_queue];
    }

    int pop()
    {
        if (front_queue > rear_queue)
        {
            return -1;
        }
        return data[front_queue++];
    }

    int size()
    {
        return rear_queue - front_queue + 1;
    }

    vector<int> getData()
    {
        return vector<int>(data.begin() + front_queue, data.begin() + rear_queue + 1);
    }
};

int main()
{
    int m;
    cin >> m;

    vector<Structure *> structures(m);

    for (int i = 0; i < m; i++)
    {
        string type;
        int n;
        cin >> type >> n;
        structures[i] = Structure::createStructure(type, n);
    }

    int k;
    cin >> k;

    while (k-- > 0)
    {
        int idx;
        string operation;
        int value;
        cin >> idx >> operation >> value;

        if (operation == "push")
        {
            cout << structures[idx]->push(value) << endl;
        }
        else if (operation == "pop")
        {
            cout << structures[idx]->pop() << endl;
        }
        else if (operation == "peek")
        {
            cout << structures[idx]->peek() << endl;
        }
        else if (operation == "size")
        {
            cout << structures[idx]->size() << endl;
        }
        else if (operation == "print")
        {
            vector<int> elements = structures[idx]->getData();
            for (int i = 0; i < elements.size(); i++)
            {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
    }

    // Clean up
    for (int i = 0; i < m; i++)
    {
        delete structures[i];
    }

    return 0;
}
