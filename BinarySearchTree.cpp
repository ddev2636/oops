#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node *deleteNode(Node *node, int value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Node found
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    bool search(Node *node, int value)
    {
        if (node == nullptr)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
            return search(node->left, value);
        return search(node->right, value);
    }

public:
    Node *root;

    BST() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    void deleteNode(int value)
    {
        root = deleteNode(root, value);
    }

    void inorderTraversal()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    bool search(int value)
    {
        return search(root, value);
    }
};

int main()
{
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal: ";
    bst.inorderTraversal();

    std::cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 25: " << (bst.search(25) ? "Found" : "Not Found") << std::endl;

    std::cout << "Deleting 20...\n";
    bst.deleteNode(20);
    std::cout << "In-order traversal after deleting 20: ";
    bst.inorderTraversal();

    std::cout << "Deleting 30...\n";
    bst.deleteNode(30);
    std::cout << "In-order traversal after deleting 30: ";
    bst.inorderTraversal();

    std::cout << "Deleting 50...\n";
    bst.deleteNode(50);
    std::cout << "In-order traversal after deleting 50: ";
    bst.inorderTraversal();

    return 0;
}