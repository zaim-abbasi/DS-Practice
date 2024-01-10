#include <iostream>
using namespace std;

class NodeInfo
{
public:
    string name;
    string path;
    string type;

    NodeInfo()
    {
        name = path = type = "";
    }

    NodeInfo(string name, string path, string type)
    {
        this->name = name;
        this->path = path;
        this->type = type;
    }
};