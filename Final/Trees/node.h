#include "nodeinfo.h"
class Node
{
public:
    NodeInfo *nodeinfo;
    Node *left;
    Node *right;

    Node()
    {
        nodeinfo = nullptr;
        left = right = nullptr;
    }

    Node(NodeInfo *nodeinfo)
    {
        this->nodeinfo = nodeinfo;
        left = right = nullptr;
    }
};