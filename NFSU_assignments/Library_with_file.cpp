#include<iostream>
#include<string>

using namespace std;

// Base class for all library items
class LibraryItem{
    string author, title, year, line;
public:
    // Virtual function to add information about a library item
    virtual void addInfo(){
        cout<<"Enter the name of the author: ";
        cin.ignore();
        getline(cin, author);
        cout<<"Enter the title of the book: ";
        getline(cin, title);
        cout<<"Enter the year of publication: ";
        getline(cin, year);
    }
    // Virtual function to display information about a library item
    virtual void displayInfo(){
        cout<<"\nAuthor: "<<author<<"\nTitle: "<<title<<"\nYear: "<<year<<endl;
    }
    // Virtual destructor to ensure proper cleanup
    virtual ~LibraryItem(){}
};

// Class for books, derived from LibraryItem
class Book: public LibraryItem{
    string genre, publisher, runtime, director, category;
    int pages;
public:
    // Function to add information about a book
    void addInfo(){
        category = "Book";
        LibraryItem::addInfo();
        cout<<"Enter the publisher: ";
        getline(cin, publisher);
        cout<<"Enter the genre: ";
        getline(cin, genre);
        cout<<"Enter the number of pages: ";
        cin>>pages;
    }
    // Function to display information about a book
    void displayInfo(){
        LibraryItem::displayInfo();
        cout<<"\nCategory: "<<category<<"\nPublisher/Studio: "<<publisher<<"\nGenre: "<<genre<<"\nPages: "<<pages<<endl;
    }
};

// Class for DVDs, derived from LibraryItem
class DVD: public LibraryItem{
    string genre, studio, director, category;
    int runtime;
public:
    // Function to add information about a DVD
    void addInfo(){
        category = "DVD";
        LibraryItem::addInfo();
        cout<<"Enter the director: ";
        getline(cin, director);
        cout<<"Enter the genre: ";
        getline(cin, genre);
        cout<<"Enter the studio: ";
        getline(cin, studio);
        cout<<"Enter the runtime: ";
        cin>>runtime;
    }
    // Function to display information about a DVD
    void displayInfo(){
        LibraryItem::displayInfo();
        cout<<"\nCategory: "<<category<<"\nPublisher/Studio: "<<studio<<"\nGenre: "<<genre<<"\nDirector: "<<director<<"\nRuntime: "<<runtime<<endl;
    }
};

// Class for magazines, derived from LibraryItem
class Magazine: public LibraryItem{
    string publisher, category;
    int issueNumber;
public:
    // Function to add information about a magazine
    void addInfo(){
        category = "Magazine";
        LibraryItem::addInfo();
        cout<<"Enter the publisher: ";
        getline(cin, publisher);
        cout<<"Enter the issue number: ";
        cin>>issueNumber;
    }
    // Function to display information about a magazine
    void displayInfo(){
        LibraryItem::displayInfo();
        cout<<"\nCategory: "<<category<<"\nPublisher/Studio: "<<publisher<<"\nissueNumber: "<<issueNumber<<endl;
    }
};

int main(){
    const int MAX_ITEMS = 100;
    // Arrays to store books, DVDs, and magazines
    Book books[MAX_ITEMS];
    DVD dvds[MAX_ITEMS];
    Magazine magazines[MAX_ITEMS];
    int bookCount = 0, dvdCount = 0, magazineCount = 0;

    int choice;
    do{
        // Menu to choose an option
        cout << "1. Add a book\n2. Add a DVD\n3. Add a Magazine\n4. Display the Book record\n5. Display the DVD record\n6. Display the Magazine record\n0. To terminate the program" << endl;
        cin>>choice;
        switch(choice){
            case 1:
                // Add a book
                if(bookCount < MAX_ITEMS){
                    books[bookCount].addInfo();
                    bookCount++;
                } else {
                    cout << "Maximum number of books reached." << endl;
                }
                break;
            case 2:
                // Add a DVD
                if(dvdCount < MAX_ITEMS){
                    dvds[dvdCount].addInfo();
                    dvdCount++;
                } else {
                    cout << "Maximum number of DVDs reached." << endl;
                }
                break;
            case 3:
                // Add a magazine
                if(magazineCount < MAX_ITEMS){
                    magazines[magazineCount].addInfo();
                    magazineCount++;
                } else {
                    cout << "Maximum number of magazines reached." << endl;
                }
                break;
            case 4:
                // Display book records
                for(int i = 0; i < bookCount; i++){
                    books[i].displayInfo();
                }
                break;
            case 5:
                // Display DVD records
                for(int i = 0; i < dvdCount