#include "node.h"
#include "list.h"
class Matrix_Graph{
    LinkedList l;
    bool arr[5][5]; // bool->unweighted, int->weighted
    // weight->arr: int, int x,y ki value

    Matrix_Graph()
    {
        for (int i = 0; i < 5;i++)
        {
            l.insert(i);
        }
        for (int i = 0; i < 5;i++)
        {
            cout << i << endl;
        }
        int x;
        cin >> x;
        for (int i = 0; i < 5;i++)
        {
            cout << i << endl;
        }
        int y;
        cin >> y;
        arr[x][y] = true;
        arr[y][x] = true; // when graph is undirected
    } 

    void print()
    {
        // while printing, you have to show the data of the linked list as vertices
    }

};

class List_Graph{
    LinkedList l;
    LinkedList arr[5]; // bool->unweighted, int->weighted
    // weight->arr: int, int x,y ki value

    List_Graph()
    {
        for (int i = 0; i < 5;i++)
        {
            l.insert(i);
        }
        for (int i = 0; i < 5;i++)
        {
            cout << i << endl;
        }
        int x;
        cin >> x;
        for (int i = 0; i < 5;i++)
        {
            cout << i << endl;
        }
        int y;
        cin >> y;
        arr[x].insert(y);
        arr[y].insert(x); // when graph is undirected
    } 

    void print()
    {
        // while printing, you have to show the data of the linked list as vertices
    }

};
