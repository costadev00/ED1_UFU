/*

*/
#include <bits/stdc++.h>
using namespace std;

class Book
{
public:
    string title;
    string author;
    int pages;
    Book()
    {
        title = "no title";
        author = "no author";
        pages = 0;
    }
    Book(string atitle, string aAuthor, int aPages)
    {
        title = atitle;
        author = aAuthor;
        pages = aPages;
    }
    bool bigBook()
    {
        if (pages >= 300)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Book b1("Harry Potter", "JK Rowling", 500);
    // b1.title = "Harry Potter";
    // b1.author = "JK Rowling";
    // b1.pages = 500;

    Book b2("How life imitate chess", "Garry Kasparov", 250);
    // b2.title = "How life imitate chess";
    // b2.author = "Garry Kasparov";
    // b2.pages = 250;
    Book b3;
    cout << b1.title << "from" << b1.author << endl;
    cout << b2.author << "is the best chess player in the world\n";
    cout << b3.title;
    if (b1.bigBook())
    {
        cout << b1.title << "is a big book\n";
    }
    return 0;
}