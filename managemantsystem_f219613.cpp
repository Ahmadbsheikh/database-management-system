#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    int copies;
};


void createBook(Book& book);
void updateBook(Book& book);
void deleteBook(Book& book);
void searchBook(Book& book);

void createBook(Book& book) {
    ifstream infile;
    ofstream outfile;
    string line;
    bool bookExists = false;
    outfile.open("book.txt", ios::app);
    cout << "Enter the title of the book: ";
    cin >> book.title;
    outfile << book.title << "  ";

    cout << "Enter the author of the book: ";
    cin >> book.author;
    outfile << book.author << "  ";
    cout << "Enter the ISBN of the book: ";
    cin >> book.ISBN;
    outfile << book.ISBN <<"  ";

    cout << "Enter the number of copies available: ";
    cin >> book.copies;
    outfile << book.copies<<endl;

    outfile.close();
    
    infile.open("book.txt");

    while (getline(infile, line)) {
        if (line.find(book.ISBN) != string::npos) {
            bookExists = true;
            break;
        }
    }
    
    infile.close();

   
    if (!bookExists) {
        outfile.open("book.txt", ios::app);
        outfile << book.title << "|" << book.author << "|" << book.ISBN << "|" << book.copies << endl;
        outfile.close();
    }
    else {
        cout << "Book already exists!" << endl;
    }
}

void updateBook(Book& book) {
    ifstream infile;
    ofstream outfile;
    string line;
    string newTitle;
    string newAuthor;
    int newCopies;
    bool bookExists = false;

    cout << "Enter the ISBN of the book: ";
    cin >> book.ISBN;

    // Open file for reading
    infile.open("book.txt");

    // Check if the book exists
    while (getline(infile, line)) {
        if (line.find(book.ISBN) != string::npos) {
            bookExists = true;
            break;
        }
    }

    // Close the file
    infile.close();

    // If the book exists, get the new details
    if (bookExists) {
        cout << "Enter the new title: ";
        cin >> newTitle;

        cout << "Enter the new author: ";
        cin >> newAuthor;

        cout << "Enter the new number of copies available: ";
        cin >> newCopies;

        // Open file for writing
        outfile.open("book.txt", ios::trunc);

        // Read file line by line and update the details
        while (getline(infile, line)) {
            if (line.find(book.ISBN) != string::npos) {
                outfile << newTitle << "|" << newAuthor << "|" << book.ISBN << "|" << newCopies << endl;
            }
            else {
                outfile << line << endl;
            }
        }
    }
    else {
        cout << "Book not found!" << endl;
    }

    // Close the file
    outfile.close();
}
void searchBook(Book& book) {
    ifstream infile;
    string line;
    string searchString;
    bool bookExists = false;

    cout << "Enter the search string: ";
    cin >> searchString;

    // Open file for reading
    infile.open("book.txt");

    // Check if the book exists
    while (getline(infile, line)) {
        if (line.find(searchString) != string::npos) {
            bookExists = true;
            break;
        }
    }

    // Close the file
    infile.close();

    // If the book exists, display the book's details
    if (bookExists) {
        cout << "Book Details:" << endl;
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "ISBN: " << book.ISBN << endl;
        cout << "Copies Available: " << book.copies << endl;
    }
    else {
        cout << "Book not found!" << endl;

    }


}


void deleteBook(Book& book) {
    ifstream infile;
    ofstream outfile;
    string line;
    bool bookExists = false;

    cout << "Enter the ISBN of the book: ";
    cin >> book.ISBN;

    // Open file for reading
    infile.open("book.txt");

    // Check if the book exists
    while (getline(infile, line)) {
        if (line.find(book.ISBN) != string::npos) {
            bookExists = true;
            break;
        }
    }

    // Close the file
    infile.close();

    // If the book exists, delete it from the file
    if (bookExists) {
        // Open file for writing
        outfile.open("book.txt", ios::trunc);

        // Read file line by line and delete the book
        while (getline(infile, line)) {
            if (line.find(book.ISBN) == string::npos) {
                outfile << line << endl;
            }
        }
    }
    else {
        cout << "Book not found!" << endl;
    }

    // Close the file
    outfile.close();
}

int main() {
    Book book;
    string choice;
    cout << "        Library Management System!" << endl;
    while (choice != "5")
    {
        cout << "What would you like to do?" << endl;
        cout << "1. Enter new book details " << endl;
        cout << "2. search a book" << endl;
        cout << "3. Update a book" << endl;
        cout << "4. Delete a book" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            createBook(book);
        }
        else if (choice == "2") {
              searchBook(book);
        }
        else if (choice == "3") {
            updateBook(book);
        }
        else if (choice == "4") {
            deleteBook(book);
        
        }
    }
    system("pause");
    return 0;

}
