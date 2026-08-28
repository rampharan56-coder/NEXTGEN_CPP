#include <iostream>
#include <string>
class Book
{
    private:
        std::string title;
        std::string author;
        int year;
    public:
        void setTitle(std::string t){
        title = t;
    }
        std::string getTitle(){
        return title;
    }

    void setAuthor(std::string a)
    {
        author = a;
    }
    std::string getAuthor()
    {
        return author;
    }

    void setYear(int y)
    {
        year = y;
    }
    int getYear()
    {
        return year;
    }
};
void display(Book &b)
{
    std::cout << "Title: " << b.getTitle() << std::endl;
    std::cout << "Author: " << b.getAuthor() << std::endl;
    std::cout << "Year: " << b.getYear() << std::endl;
    std::cout << "=================================" << std::endl;

    std::cout << std::endl;
}
int main()
{
    Book b;
    // b[0] = {"Tom and Jerry", "I don't know", 1990};
    // b[1] = {"Naruot", "I don't know", 1990};
    // b[2] = {"One Piece", "I don't knwo", 1990};

    // Book *ptr = &b[2];
    // ptr->year = 1999;

    b.setTitle("Tom and Jerry");
    b.setAuthor("I dont know");
    b.setYear(1990);
    display(b);

    // display(b[0]);
    // display(b[1]);
    // display(b[2]);

    return 0;
}