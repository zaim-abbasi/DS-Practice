#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};
class AVL{
public:
    Node *root;
    AVL()
    {
        root = NULL;
    }

    int height(Node* t)
    {
        if(t == NULL)
            return -1;
        return t->height;
    }
    Node* insert(int x, Node* root)
    {
        if (root == NULL)
        {
            root = new Node();
            root->data = x;
            root->height = 0;
            root->left = root->right = NULL;
        }

        else if(x < root->data)
        {
            // yani ke left me jana ha
            root->left = insert(x, root->left);

            if(height(root->left) - height(root->right) == 2)
            {
                
            }
        }

    }
};