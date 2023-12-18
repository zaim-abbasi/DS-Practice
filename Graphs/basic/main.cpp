// implementation of a graph using adjacency matrix

#include <iostream>
using namespace std;

class Graph
{
public:
    int **adjMatrix;
    int numVertices;

    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }

    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }

    void print()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void PrintMaze()
    {
        // display the maze in a 2D grid format using colors to show the path. Show the connection from a node to another node using a line. 
        

        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    cout << "----";
                }
                else
                {
                    cout << "    ";
                }
            }
            cout << endl;
            cout << "     ";
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    cout << "|   ";
                }
                else
                {
                    cout << "    ";
                }
            }
            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    cout << "----";
                }
                else
                {
                    cout << "    ";
                }
            }
            cout << endl;
        }

        cout << endl;

        

    }

    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main()
{
    // hard code to make a 2 by 2 maze like structure using some specific formula to generate a new graph each time the program is executed. Also there should be a path from first node to last node.

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // g.addEdge(3, 0);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    
    


    g.PrintMaze();


    return 0;
}