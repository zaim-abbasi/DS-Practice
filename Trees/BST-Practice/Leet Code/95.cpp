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

    obj.Display(obj.root);
    // return 0;
}
