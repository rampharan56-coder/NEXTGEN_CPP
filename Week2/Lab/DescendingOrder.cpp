#include <iostream>
#include <string>

struct Book
{
    std::string title;
    std::string author;
    int year;
};

void copyString(Book *src, Book *dest, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

void printBooks(Book *books, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "$ " << books[i].year << " - " << books[i].title << " by " << books[i].author << std::endl;
        std::cout << std::endl;
    }
}

// Bubble Sort
void BubbleSort(Book *books, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (books[j].year < books[j + 1].year)
            {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
};
int main()
{
    Book b[3];
    b[0] = {"Tom and Jerry", "I don't know", 1990};
    b[1] = {"Naruto", "I don't know", 1985};
    b[2] = {"One Piece", "I don't know", 1990};
    std::cout << "Before sorting: " << std::endl;
    std::cout << "=======================" << std::endl;
    printBooks(b, 3);
    BubbleSort(b, 3);
    std::cout << "After sorting: " << std::endl;
    std::cout << "=======================" << std::endl;
    printBooks(b, 3);
    return 0;
}