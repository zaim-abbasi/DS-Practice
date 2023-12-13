#include <iostream>
using namespace std;
class Book{
private:
    string title;
    string author;
    int ibanNum;
public:
    Book()
    {
        title = "";
        author = "";
        ibanNum = 0;
    }
    Book(string title, string author, int ibanNum)
    {
        this->title = title;
        this->author = author;
        this->ibanNum = ibanNum;
    }
    string GetTitle()
    {
        return title;
    }
    string GetAuthor()
    {
        return author;
    }
    int GetIban()
    {
        return ibanNum;
    }

    void SetTitle(string title)
    {
        this->title = title;
    }
    void SetAuthor(string author)
    {
        this->author = author;
    }
    void SetIban(int ibanNum)
    {
        this->ibanNum = ibanNum;
    }
};