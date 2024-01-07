#include "queue.h"
int main()
{
    Queue queueObj;
    queueObj.Enqueue(5);
    queueObj.Enqueue(10);
    queueObj.Enqueue(15);
    queueObj.Enqueue(20);

    queueObj.display();
}