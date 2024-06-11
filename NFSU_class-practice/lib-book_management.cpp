// This program aims at managing book information for a library 
// This excercise aims at practicing single inheritence in C++

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class book
{
    // Member variables to store the book's title and author
    private :
        string title;
        string author;

    public :
        // Setter function to set the book's title and author
        void set_details(string title, string author)
        {
            this->title = title;
            this->author = author;
        }
        
        // Getter function to retrieve the book's title and author
        void get_details(string& title, string& author)
        {
            title = this->title;
            author = this->author;
        }

        // Function to display the book's information
        void displayBookInfo()
        {
            cout << setw(10) << right << "Title : " << title << endl;
            cout << setw(10) << right << "Author : " << author << endl;
        }
};

class library : private book
{
    private : 
        string libId;

    public :
        // Default constructor to initialize the library ID
        library()
        {
            
        }

        // Function to display the book's information with the library ID
        void displayBookInfo()
        {
            // Display the library ID
            cout << setw(10) << right << "Book LibID : " << libId << endl;
            
            // Call the base class's displayBookInfo function to display the book's title and author
            book::displayBookInfo();
        }
};

int main()
{
    // Main function to test the program
    return 0;
}