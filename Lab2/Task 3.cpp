#include <iostream>
#include <string>
using namespace std;

template <typename T>
int linearSearch(T arr[], int size, string key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
template <typename T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[small] > arr[j])
            {
                small = j;
            }
        }
        if (small != i)
        {
            T temp = arr[i];
            arr[i] = arr[small];
            arr[small] = temp;
        }
    }
}
class Item
{
public:
    virtual void display() = 0;
};
class Book : public Item
{
public:
    string title;
    string author;

    int pages;
    Book()
    {
        title = "unknown";
        author = "unknown";
        pages = 0;
    }
    Book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }
    bool operator==(string key)
    {
        return title == key;
    }
    bool operator>(const Book& other) const
    {
        return title > other.title;
    }
    void display()
    {
        cout << "Book =" << title << "  Author=" << author << "    Pages=" << pages << endl;
    }
};
class Newspaper : public Item
{
public:
    string name;
    string date;
    string edition;
    Newspaper()
    {
        name = "unknown";
        date = "unknown";
        edition = "unknown";
    }
    Newspaper(string n, string d, string e)
    {
        name = n;
        date = d;
        edition = e;
    }
    bool operator==(string key)
    {
        return name == key;
    }
    bool operator>(const Newspaper& other) const
    {
        return name > other.name;
    }
    void display()
    {
        cout << "Newspaper =" << name << "   Date=" << date << "    Edition=" << edition << endl;
    }
};
class Library
{
private:
    Book books[10];
    Newspaper newspapers[10];
    int bCount = 0;
    int nCount = 0;
public:
    void addBook(Book b)
    {
        books[bCount++] = b;
    }
    void addNews(Newspaper n)
    {
        newspapers[nCount++] = n;
    }
    void displayCollection()
    {
        cout << "\nBooks =" << endl;
        for (int i = 0; i < bCount; i++)
        {
            books[i].display();
        }
        cout << "\nNewspapers= " << endl;
        for (int i = 0; i < nCount; i++)
        {
            newspapers[i].display();
        }
    }
    void sortbook()
    {
        selectionSort(books, bCount);
    }
    void sortNews()
    {
        selectionSort(newspapers, nCount);
    }

    Book* searchBook(string title)
    {
        int index = linearSearch(books, bCount, title);
        if (index != -1)
        {
            return &books[index];
        }
        return 0;
    }
    Newspaper* searchNews(string name)
    {
        int index = linearSearch(newspapers, nCount, name);
        if (index != -1)
        {
            return &newspapers[index];
        }
        return 0;
    }
};
int main()
{
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;
    library.addBook(book1);

    library.addBook(book2);
    library.addNews(newspaper1);
    library.addNews(newspaper2);

    cout << "Before Sorting=" << endl;
    library.displayCollection();

    library.sortbook();
    library.sortNews();

    cout << "\nAfter Sorting=" << endl;
    library.displayCollection();

    Book* foundBook = library.searchBook("The Catcher in the Rye");
    if (foundBook)
    {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else
    {
        cout << "Book not found\n";
    }

    Newspaper* foundNewspaper = library.searchNews("The Times");
    if (foundNewspaper)
    {
        cout << "\nFound Newspaper=" << endl;
        foundNewspaper->display();
    }
    else
    {
        cout << "Newspaper not found" << endl;
    }

    return 0;
}