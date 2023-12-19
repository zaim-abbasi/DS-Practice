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

    #include <iostream>

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

        if (root->data == data)
        {
            // 0th child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // 1 child

            // left child
            if (root->left != NULL && root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            // right child
            if (root->right != NULL && root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // 2 child
            if (root->left != NULL && root->right != NULL)
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
        cout << "3. Delete" << endl;
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
            cout << "Enter data: ";
            cin >> data;
            // t.Delete(t.root, data);
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