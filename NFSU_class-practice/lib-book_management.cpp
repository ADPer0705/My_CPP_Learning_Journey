// This program aims at managing book information for a library 
// This exercise aims at practicing single inheritance in C++

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

// Class to represent a book
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
            // Set the title and author of the book
            this->title = title;
            this->author = author;
        }
        
        // Getter function to retrieve the book's title and author
        void get_details(string& title, string& author)
        {
            // Retrieve the title and author of the book
            title = this->title;
            author = this->author;
        }

        // Function to display the book's information
        void displayBookInfo()
        {
            // Display the book's title
            cout << setw(10) << right << "Title : " << title << endl;
            // Display the book's author
            cout << setw(10) << right << "Author : " << author << endl;
        }
};

// Class to represent a library, inherits from the book class
class library : public book
{
    private : 
        string libId;

    public :
        // Default constructor to initialize the library ID
        library()
        {
            // Initialize the library ID
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

// Array to store 100 library objects
library lib_books[100];

int main()
{
    // Initialize all library objects with default title and author
    for ( int i = 0; i < 100; i ++)
    {
        lib_books[i].set_details("N.A.", "N.A.");
    }

    int ctr, adm_ctr, usr_ctr; 
    int choice;
    int adm;
    string adminPasswd = "aVERYstrongPASSWORD", buffPasswd;

    // Main loop to handle user input
    while(ctr != 0)
    {
        system("clear");
        cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "Choose your administrative status : " << endl;
        cout << "1. Administrator" << endl;
        cout << "2. User" << endl;
        cout << "0. Exit" << endl;

        // Get user input
        cin >> choice;

        switch(choice)
        {
            case 1 :
                system("clear");
                // Administrator login
                for ( int i = 0; i < 3; i ++)
                {
                    cout << "Enter your admin ID : ";
                    cin >> buffPasswd;

                    if (adminPasswd != buffPasswd)
                    {
                        system("clear");
                        cout << "Incorrect admin ID. Please try again." << endl;
                    }

                    if (adminPasswd == buffPasswd)
                    {
                        adm = 1;
                        break;
                    }

                    // Administrator menu
                    while(adm != 0)
                    {
                        /* code for admins */
                    }
                }
                break;

            case 2 :
                system("clear");

                // User menu
                switch(usr_ctr)
                {
                    /* code for users */
                }
                break;

            case 0 :
                system("clear");
                cout << "Exiting..." << endl;
                ctr = 0;    
                break;
                
        }

    }

    return 0;
}