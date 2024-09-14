#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a node at the end of the list
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Delete a node with a specific value
    void deleteNode(int value)
    {
        if (head == nullptr)
            return; // List is empty

        // If the node to be deleted is the head node
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr && current->data != value)
        {
            prev = current;
            current = current->next;
        }

        // If the value was not found
        if (current == nullptr)
            return;

        // Unlink the node and free memory
        prev->next = current->next;
        delete current;
    }

    // Print the linked list
    void printList() const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Search for a node with a specific value
    bool search(int value) const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    std::cout << "Linked List: ";
    list.printList();

    std::cout << "Deleting 20...\n";
    list.deleteNode(20);
    list.printList();

    std::cout << "Searching for 30: " << (list.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 50: " << (list.search(50) ? "Found" : "Not Found") << std::endl;

    return 0;
}
