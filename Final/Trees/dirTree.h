#include "node.h"
class DirectoryTree
{
public:
    Node *root;

    DirectoryTree()
    {
        root = new Node();
        root->left = new Node();
        root->right = new Node();

        root->left->left = new Node();
        root->left->right = new Node();

        root->right->left = new Node();
        root->right->right = new Node();

        root->nodeinfo = new NodeInfo("root", "root", "directory");
        root->left->nodeinfo = new NodeInfo("students", "root/students", "directory");
        root->right->nodeinfo = new NodeInfo("teachers", "root/teachers", "directory");
    }

    void Navigate()
    {
        bool flag = true;
        while (flag == true)
        {
            Node *temp = root;
            string path;
            cout << "Enter path: ";
            cin >> path;

            if (temp->left->nodeinfo->path == path)
            {
                temp = temp->left;
            }
            else if (temp->right->nodeinfo->path == path)
            {
                temp = temp->right;
            }
            else
            {
                cout << "Path doesn't exist." << endl;
            }

            cout << "Current path: " << path << endl;

            cout << "Do you want to enter more paths? (y/n)";
            char ch;
            cin >> ch;
            if (ch == 'y')
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
    }

    void Display()
    {
        // Your display logic goes here
    }
};