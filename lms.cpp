
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a struct to represent book information
struct Book {
    string title;
    string author;
    string isbn;
    bool available;
};

// Function to add a new book to the catalog
void addBook(vector<Book>& catalog) {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    getline(cin, newBook.isbn);
    newBook.available = true;
    catalog.push_back(newBook);
    cout << "Book added to the catalog." << endl;
}

// Function to remove a book from the catalog by ISBN
void removeBook(vector<Book>& catalog, const string& isbn) {
    for (size_t i = 0; i < catalog.size(); ++i) {
        if (catalog[i].isbn == isbn) {
            catalog.erase(catalog.begin() + i);
            cout << "Book removed from the catalog." << endl;
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found." << endl;
}

// Function to check book availability by title
void checkAvailability(const vector<Book>& catalog, const string& title) {
    for (size_t i = 0; i < catalog.size(); ++i) {
        if (catalog[i].title == title) {
            if (catalog[i].available) {
                cout << "Book is available." << endl;
            } else {
                cout << "Book is not available." << endl;
            }
            return;
        }
    }
    cout << "Book with title '" << title << "' not found." << endl;
}

// Function to display the library's catalog
void displayCatalog(const vector<Book>& catalog) {
    cout << "Library Catalog:" << endl;
    for (size_t i = 0; i < catalog.size(); ++i) {
        cout << "Title: " << catalog[i].title << endl;
        cout << "Author: " << catalog[i].author << endl;
        cout << "ISBN: " << catalog[i].isbn << endl;
        cout << "Available: " << (catalog[i].available ? "Yes" : "No") << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    vector<Book> catalog;

    while (true) {
        cout << "Library Management System Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Check Availability" << endl;
        cout << "4. Display Catalog" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(catalog);
                break;
            case 2:
                {
                    string isbn;
                    cout << "Enter ISBN to remove: ";
                    cin >> isbn;
                    removeBook(catalog, isbn);
                }
                break;
            case 3:
                {
                    string title;
                    cout << "Enter book title to check availability: ";
                    cin.ignore();
                    getline(cin, title);
                    checkAvailability(catalog, title);
                }
                break;
            case 4:
                displayCatalog(catalog);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
