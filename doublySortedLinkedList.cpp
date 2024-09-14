#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class SortedDoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SortedDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~SortedDoublyLinkedList() {
        clear();
    }

    void insert(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (!head) {
            head = tail = newNode;
        } else if (data < head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (data >= tail->data) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            Node<T>* current = head;
            while (current->data < data) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void remove(T data) {
        if (!head) return;

        Node<T>* current = head;
        while (current && current->data != data) {
            current = current->next;
        }

        if (!current) return;

        if (current == head) {
            head = current->next;
            if (head) head->prev = nullptr;
        } else if (current == tail) {
            tail = current->prev;
            if (tail) tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
    }

    void display() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
};

int main() {
    SortedDoublyLinkedList<int> list;

    list.insert(10);
    list.insert(5);
    list.insert(20);
    list.insert(15);

    list.display(); // Output: 5 10 15 20

    list.remove(10);
    list.display(); // Output: 5 15 20

    list.clear();
    list.display(); // Output: (empty line)

    return 0;
}
