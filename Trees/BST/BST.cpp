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
                if (data > nodePtr->data)
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

    bool Search(Node *root, int data)
    {
        if (root == NULL)
            return false;
        if (Search(root->left, data))
            return true;
        if (root->data == data)
            return true;
        if (Search(root->right, data))
            return true;
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
        if(root == NULL)
            return root;
        else if(data < root->data)
            root->left = Delete(root->left, data);
        else if(data > root->data)
            root->right = Delete(root->right, data);
        else
        {
            // Case 1: No Child
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            // Case 2: One Child
            else if(root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            // Case 3: Two Children
            else
            {
                Node *temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
    }

    int RecursiveCounter(Node *root, int x, int counter)
    {
        if (root == NULL)
            return counter;
        if (root->data < x)
        {
            counter++;
        }
        counter = RecursiveCounter(root->left, x, counter);
        counter = RecursiveCounter(root->right, x, counter);
        return counter;
    }

    void Smaller(Node *root, int x)
    {
        int counter = 0;
        cout << RecursiveCounter(root, x, counter) << endl;
    }

    // count number of nodes in a tree
    int NodeCounter(Node* root, int counter)
    {
        if(root == NULL)
            return counter;
        counter = NodeCounter(root->left, counter);
        counter++;
        counter = NodeCounter(root->right, counter);

        return counter; // Add return statement
    }

    void NodeCount(Node* root)
    {
        cout << "Total Nodes are " << NodeCounter(root, 0) << endl;
    }

    void display(Node *root)
    {
        if (root == NULL)
            return;
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }

};

int main()
{
    // full fledged menu driven program
    Tree t;
    int choice;
    int data;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Node Counter" << endl;
        cout << "4. Smaller" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            t.Insert(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            if (t.Search(t.root, data))
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
            break;
        case 3:
            t.NodeCount(t.root);
            break;
        case 4:
            cout << "Enter data: ";
            cin >> data;
            t.Smaller(t.root, data);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
    return 0;
}