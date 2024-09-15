#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    // Insert a node into the tree
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

    // In-order traversal (left, root, right)
    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Search for a node with a specific value
    bool search(Node *node, int value)
    {
        if (node == nullptr)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
        {
            return search(node->left, value);
        }
        else
        {
            return search(node->right, value);
        }
    }

    // Find the minimum value node in a tree
    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // Delete a node from the tree
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
            // Node with only one child or no child
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

            // Node with two children: Get the inorder successor
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
};

int main()
{
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    std::cout << "In-order traversal: ";
    tree.inorderTraversal(tree.root);
    std::cout << std::endl;

    std::cout << "Searching for 40: " << (tree.search(tree.root, 40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 25: " << (tree.search(tree.root, 25) ? "Found" : "Not Found") << std::endl;

    std::cout << "Deleting 20...\n";
    tree.root = tree.deleteNode(tree.root, 20);
    std::cout << "In-order traversal after deleting 20: ";
    tree.inorderTraversal(tree.root);
    std::cout << std::endl;

    std::cout << "Deleting 30...\n";
    tree.root = tree.deleteNode(tree.root, 30);
    std::cout << "In-order traversal after deleting 30: ";
    tree.inorderTraversal(tree.root);
    std::cout << std::endl;

    std::cout << "Deleting 50...\n";
    tree.root = tree.deleteNode(tree.root, 50);
    std::cout << "In-order traversal after deleting 50: ";
    tree.inorderTraversal(tree.root);
    std::cout << std::endl;

    return 0;
}
