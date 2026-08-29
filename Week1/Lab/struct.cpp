#include <iostream>
struct Book{
    std::string title;
    std::string author;
    int year;
};
void display(Book &b){
    std::cout << "Title: " << b.title << std::endl;
    std::cout << "Author: " << b.author << std::endl;
    std::cout << "Year: " << b.year << std::endl;
    std::cout << "=================================" << std::endl;

    std::cout << std::endl;
}
int main() {
    Book b[3];
    b[0] = {"Tom and Jerry", "I don't know", 1990};
    b[1] = {"Naruto", "I don't know", 1990};
    b[2] = {"One Piece", "I don't know", 1990};

    display(b[0]);
    display(b[1]);
    display(b[2]);

    return 0;
}