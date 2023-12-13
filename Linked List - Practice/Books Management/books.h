#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int ibanNum;

public:
    Book() {}
    Book(string title, string author, int ibanNum)
    {
        this->title = title;
        this->author = author;
        this->ibanNum = ibanNum;
    }

    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    int GetIbanNum()
    {
        return ibanNum;
    }

    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setIbanNum()
    {
        this->ibanNum = ibanNum;
    }
};