// Binary Search Tree into a sorted doubly linked list in - place.The head of the doubly linked list should be the smallest element.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }

    void Insert(int data)
    {
        Node *newNode = new Node(data);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *traverse = root;
        while (traverse != nullptr)
        {
            if (data < traverse->data)
            {
                if (traverse->left == nullptr)
                {
                    traverse->left = newNode;
                    return;
                }
                else
                {
                    traverse = traverse->left;
                }
            }
            else if (data > traverse->data)
            {
                if (traverse->right == nullptr)
                {
                    traverse->right = newNode;
                    return;
                }
                else
                {
                    traverse = traverse->right;
                }
            }
        }
    }

    void SearchBST(int data)
    {
        Node *traverse = root;
        while (traverse != nullptr)
        {
            if (data == traverse->data)
            {
                cout << "Found" << endl;
                return;
            }
            else if (data < traverse->data)
            {
                traverse = traverse->left;
            }
            else if (data > traverse->data)
            {
                traverse = traverse->right;
            }
        }
        cout << "Not Found" << endl;
    }
    void Display(Node *root)
    {
        if (root == nullptr)
            return;
        Display(root->left);
        cout << root->data << " ";
        Display(root->right);
    }

    int sizeCounter(Node *root)
    {
        Node *temp = root;
        static int size = 0;
        if (temp == nullptr)
            return 0;
        sizeCounter(temp->left);
        size++;
        sizeCounter(temp->right);

        return size;
    }
    int Sort(Node *root)
    {
        static int counter = 0;
        static int size = sizeCounter(root);
        static int *arr = new int[size];
        if (root == nullptr)
            return 0;
        Sort(root->left);
        arr[counter] = root->data;
        cout << arr[counter] << " ";
        counter++;
        Sort(root->right);
    }
};

int main()
{
    BST obj;
    obj.Insert(5);
    obj.Insert(10);
    obj.Insert(7);
    obj.Insert(6);
    obj.Insert(9);
    obj.Insert(15);

    obj.Sort(obj.root);
    // return 0;
}
