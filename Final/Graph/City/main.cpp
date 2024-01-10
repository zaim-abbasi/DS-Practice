#include <iostream>
using namespace std;
class Node
{
public:
    string data; // Assuming string data type for nodes
};

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int peek()
    {
        if (!isEmpty())
        {
            return front->data;
        }
        throw out_of_range("Queue is empty");
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }
};

class Graph
{
private:
    int numVertices;
    int **adjacencyMatrix;
    Node *nodes;

public:
    Graph(int vertices) : numVertices(vertices)
    {
        // Initialize adjacency matrix
        adjacencyMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; ++i)
        {
            adjacencyMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; ++j)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }

        // Initialize nodes array
        nodes = new Node[numVertices];
    }

    // Add a node to the graph
    void addNode(const string &value, int index)
    {
        if (index < 0 || index >= numVertices)
        {
            cout << "Invalid node index." << endl;
            return;
        }

        nodes[index].data = value;
    }

    // Add an edge between two nodes with a specified weight
    void addEdge(int source, int destination, int weight)
    {
        if (source < 0 || source >= numVertices || destination < 0 || destination >= numVertices)
        {
            cout << "Invalid node index." << endl;
            return;
        }

        adjacencyMatrix[source][destination] = weight;
        adjacencyMatrix[destination][source] = weight; // Assuming an undirected graph
    }

    // Display the graph
    void displayGraph()
    {
        cout << "Graph:" << endl;
        for (int i = 0; i < numVertices; ++i)
        {
            cout << "Node " << i << ": ";
            for (int j = 0; j < numVertices; ++j)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    cout << " -> Node " << j << " (Weight: " << adjacencyMatrix[i][j] << ")";
                }
            }
            cout << endl;
        }
    }

    // Dijkstra's algorithm to find the shortest path
    int *findShortestPath(int start, int end)
    {
        Queue pq;

        int *distance = new int[numVertices];
        bool *visited = new bool[numVertices];

        for (int i = 0; i < numVertices; ++i)
        {
            distance[i] = INT_MAX;
            visited[i] = false;
        }

        pq.enqueue(start);
        distance[start] = 0;

        while (!pq.isEmpty())
        {
            int current = pq.peek();
            pq.dequeue();

            if (visited[current])
            {
                continue;
            }

            visited[current] = true;

            for (int i = 0; i < numVertices; ++i)
            {
                if (adjacencyMatrix[current][i] != 0 && distance[current] + adjacencyMatrix[current][i] < distance[i])
                {
                    distance[i] = distance[current] + adjacencyMatrix[current][i];
                    pq.enqueue(i);
                }
            }
        }

        delete[] visited;
        return distance;
    }

    ~Graph()
    {
        // Delete dynamically allocated memory
        for (int i = 0; i < numVertices; ++i)
        {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
        delete[] nodes;
    }
};

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Add Node\n";
    cout << "2. Add Edge\n";
    cout << "3. Display Graph\n";
    cout << "4. Find Shortest Path\n";
    cout << "5. Exit\n";
}

int main()
{
    int vertices, choice;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph socialNetwork(vertices);

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string nodeName;
            int nodeIndex;
            cout << "Enter the node name: ";
            cin >> nodeName;
            cout << "Enter the node index: ";
            cin >> nodeIndex;
            socialNetwork.addNode(nodeName, nodeIndex);
            break;
        }
        case 2:
        {
            int source, destination, weight;
            cout << "Enter source node index: ";
            cin >> source;
            cout << "Enter destination node index: ";
            cin >> destination;
            cout << "Enter edge weight: ";
            cin >> weight;
            socialNetwork.addEdge(source, destination, weight);
            break;
        }
        case 3:
            socialNetwork.displayGraph();
            break;
        case 4:
        {
            int startNode, endNode;
            cout << "Enter start node index: ";
            cin >> startNode;
            cout << "Enter end node index: ";
            cin >> endNode;

            int *shortestPath = socialNetwork.findShortestPath(startNode, endNode);

            cout << "Shortest path from Node " << startNode << " to Node " << endNode << ": ";
            for (int i = 0; i < vertices; ++i)
            {
                if (shortestPath[i] == INT_MAX)
                {
                    cout << "Inf";
                }
                else
                {
                    cout << shortestPath[i];
                }

                if (i != vertices - 1)
                {
                    cout << " -> ";
                }
            }
            cout << endl;

            delete[] shortestPath;
            break;
        }
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
