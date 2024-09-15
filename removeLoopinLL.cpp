#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to detect and remove loop
void removeLoop(Node* head) {
    if (!head || !head->next) {
        return; // No loop if list is empty or has only one element
    }
    
    Node *slow = head, *fast = head;

    // Step 1: Detect if there's a loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        // If slow and fast meet, there's a loop
        if (slow == fast) {
            break;
        }
    }

    // If no loop was found
    if (slow != fast) {
        return;
    }

    // Step 2: Find the start of the loop
    slow = head;
    if (slow == fast) {
        // Special case: When the loop starts at the head of the list
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Remove the loop
    fast->next = nullptr;
}

// Helper function to insert nodes at the end
void insertNode(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;
    
    // Creating a linked list with a loop
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    
    // Creating a loop for testing
    head->next->next->next->next->next = head->next;  // 5 -> 2 (loop)

    // Detect and remove the loop
    removeLoop(head);
    
    // Print the list after removing the loop
    printList(head);
    
    return 0;
}