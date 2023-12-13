#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }

    void Insert(int data)
    {
        Node *newNode = new Node(data);
        Node *nodePtr;
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        else
        {
            nodePtr = root;
            while (nodePtr != NULL)
            {
                if (data < nodePtr->data)
                {
                    if (nodePtr->left == NULL)
                    {
                        nodePtr->left = newNode;
                        return;
                    }
                    else
                    {
                        nodePtr = nodePtr->left;
                    }
                }
                else
                {
                    if (nodePtr->right == NULL)
                    {
                        nodePtr->right = newNode;
                        return;
                    }
                    else
                    {
                        nodePtr = nodePtr->right;
                    }
                }
            }
        }
    }

    bool isBST(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            if (temp->left->data > temp->data)
                return false;
            temp = temp->left;
        }

        temp = root;
        while (temp->right != NULL)
        {
            if (temp->right->data < temp->data)
                return false;
            temp = temp->right;
        }

        return true;
    }

    bool SearchRecurcive(Node *root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (data == root->data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return SearchRecurcive(root->left, data);
        }
        else
        {
            return SearchRecurcive(root->right, data);
        }
    }

    bool Search(Node *root, int data)
    {
        Node *temp = root;
        while (temp)
        {
            if (temp->data == data)
            {
                return true;
            }

            if (data < temp->data)
            {
                temp = temp->left;
            }

            if (data > temp->data)
            {
                temp = temp->right;
            }
        }
        return false;
    }

    Node *FindMin(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *Delete(Node *root, int data)
    {
        if (root == nullptr)
        {
            return root;
        }

        if(root->data == data)
        {
            //0th child
            if(root->left == NULL && root->right == NULL)
                {
                    delete root;
                    return NULL;
                }
            //1 child

            //left child
            if(root->left != NULL && root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            //right child
            if (root->right != NULL && root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            //2 child
            if(root->left != NULL && root->right != NULL)
            {
                int min = FindMin(root->right)->data;
                root->data = min;

                root->right = Delete(root->right, min);
                return root;
            }
        }

        else if (root->data > data)
        {
            // left me chale jao
            root->left = Delete(root->left, data);
            return root;
        }
        else
        {
            // right me chale jao
            root->right = Delete(root->right, data);
            return root;
        }






        // else if (data < root->data)
        // {
        //     root->left = Delete(root->left, data);
        // }
        // else if (data > root->data)
        // {
        //     root->right = Delete(root->right, data);
        // }
        // else
        // {
        //     if (root->right == nullptr && root->left == nullptr)
        //     {
        //         // Case 1: No Child
        //         delete root;
        //         return NULL;
        //     }
        //     else if (root->right != nullptr && root->left != nullptr)
        //     {
        //         // Case 3: Two Children
        //         Node *temp = FindMin(root->right);
        //         root->data = temp->data;
        //         root->right = Delete(root->right, temp->data);
        //     }
        //     else
        //     {
        //         // Case 2: One Child
        //         Node *temp = root;
        //         if (root->left == nullptr)
        //         {
        //             root = root->right;
        //         }
        //         else
        //         {
        //             root = root->left;
        //         }
        //         delete temp;
        //     }
        // }
    }

    int RecursiveCounter(Node*root, int x, int counter)
    {
        if(root == NULL)
            return counter;
        RecursiveCounter(root->left, x, counter);
        if(root->data < x)
            counter++;
        RecursiveCounter(root->right, x, counter);
    }
    void Smaller(Node*root, int x)
    {
        int counter = 0;
        cout << RecursiveCounter(root, x, counter) << endl;
    }
};
int main()
{
    Tree t;
    t.Insert(10);
    t.Insert(20);
    t.Insert(30);
    t.Insert(5);
    t.Insert(15);
    t.Insert(25);

    t.Smaller(t.root, 20);

}