// This program aims at managing book information for a library 
// This excercise aims at practicing single inheritence in C++

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class book
{
    // This class contains info about the book's title and author, and the methods to set and get the book details, and a method to display book details 
    private :
        string title;
        string author;

    public :
        void set_details(string title, string author)
        {
            this->title = title;
            this->author = author;
        }
        
        void get_details(string& title, string& author)
        {
            title = this->title;
            author = this->author;
        }

        void displayBookInfo()
        {
            cout << setw(10) << left << "Title : " << title << endl;
            cout << setw(10) << left << "Author : " << author << endl;
        }

};

class library : private book
{
    private : 
        string libId;

    public :
        library()
        {
            
        }

        void displayBookInfo()
        {
            cout << setw(10) << left << "Book LibID : " << libId << endl;
            book::displayBookInfo();
        }
};

int main()
{

}