// implmentation of a graph using adjacency list
#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Graph {
    int V;
    Node** adjList;
public:
    Graph(int V) {
        this->V = V;
        adjList = new Node*[V];
        for(int i=0;i<V;i++) {
            adjList[i] = NULL;
        }
    }
    
    void addEdge(int u,int v) {
        Node* n = new Node(v);
        n->next = adjList[u];
        adjList[u] = n;
        n = new Node(u);
        n->next = adjList[v];
        adjList[v] = n;
    }
    void print() {
        for(int i=1;i<=V;i++) {
            cout<<i<<"->";
            Node* temp = adjList[i];
            while(temp!=NULL) {
                if(temp->next == NULL)
                    cout<<"NULL";
                else
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    int choice;
    cout<<"Enter the number of vertices: ";
    int V;
    cin>>V;
    Graph g(V);
    while(true)
    {
        cout<<"1. Add Edge"<<endl;
        cout<<"2. Print Graph"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1: {
                int u,v;
                cout<<"Enter the vertices: ";
                cin>>u>>v;
                g.addEdge(u,v);
                break;
            }
            case 2: {
                g.print();
                break;
            }
            case 3: {
                exit(0);
                break;
            }
            default: {
                cout<<"Invalid Choice"<<endl;
            }
        }
    }
    return 0;
}