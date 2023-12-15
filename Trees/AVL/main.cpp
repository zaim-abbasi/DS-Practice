#include <iostream>
using namespace std;

// An AVL tree node
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int key)
    {
        this->key = key;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL
{
public:
    Node *root;

    AVL()
    {
        root = NULL;
    }

    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    Node *newNode(int key)
    {
        Node *node = new Node(key);
        return node;
    }

    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        Node *Yr = y->right;

        // Perform rotation
        y->right = x;
        x->left = Yr;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *Yl = y->left;

        // Perform rotation
        y->left = x;
        x->right = Yl;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Get Balance factor of node node
    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *BST_Insert(Node *node, int key)
    {
        if (node == NULL)
            return newNode(key);

        if (key < node->key)
            node->left = BST_Insert(node->left, key);
        else if (key > node->key)
            node->right = BST_Insert(node->right, key);
        else
        {
            cout << "Duplicate key" << endl;
            return node;
        }

        return node;
    }

    Node *insert(Node *node, int key)
    {
        /* 1. Normal BST Insertion*/
        node = BST_Insert(node, key);

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->left), height(node->right));

        /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case, left me zyada lamba hai
        // yani key jo ha, node ke left ke left mei hai
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case, right me zyada lamba hai
        // yani key jo ha, node ke right ke right mei hai
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        // yani ke key us node ke left se bari hai
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case 
        // yani ke key us node ke right se bari hai
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    void preOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main()
{
    // full fledged menu
    AVL tree;
    int choice, key;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Preorder" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            tree.root = tree.insert(tree.root, key);
            break;
        case 2:
            tree.preOrder(tree.root);
            cout << endl;
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}