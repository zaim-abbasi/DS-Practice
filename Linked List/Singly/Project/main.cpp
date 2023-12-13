#include "library.h"
int main()
{
    Library l;
    l.AddBook();
    l.AddBook();

    // l.Display();

    l.Remove();

    l.Display();
}