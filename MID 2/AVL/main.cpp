#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
        height = 0;
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
};
int getHeight(Node *n)
{
    if (n == nullptr)
        return 0;
    return n->height;
}
Node *singleLeftRotate(Node *&root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}
