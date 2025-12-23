#include <iostream>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

Book books[100];
int bookCount = 0;

void addBook() {
    cout << "\nEnter Book ID: ";
    cin >> books[bookCount].id;

    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, books[bookCount].title);

    cout << "Enter Author Name: ";
    getline(cin, books[bookCount].author);

    books[bookCount].isIssued = false;
    bookCount++;

    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << books[i].id
             << " | Title: " << books[i].title
             << " | Author: " << books[i].author
             << " | Status: "
             << (books[i].isIssued ? "Issued" : "Available")
             << endl;
    }
}

void issueBook() {
    int id;
    cout << "\nEnter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued) {
                cout << "Book is already issued.\n";
            } else {
                books[i].isIssued = true;
                cout << "Book issued successfully.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void returnBook() {
    int id;
    cout << "\nEnter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (!books[i].isIssued) {
                cout << "Book was not issued.\n";
            } else {
                books[i].isIssued = false;
                cout << "Book returned successfully.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
