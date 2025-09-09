#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Book {
private:
    string title, author;
    bool isBorrowed;

public:
    Book(string t, string a) : title(t), author(a), isBorrowed(false) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool getStatus() { return isBorrowed; }

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << title << " borrowed successfully!\n";
        } else {
            cout << title << " is already borrowed.\n";
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << title << " returned successfully!\n";
        } else {
            cout << title << " was not borrowed.\n";
        }
    }

    void display() {
        cout << "- " << title << " by " << author 
             << (isBorrowed ? " [Borrowed]" : " [Available]") << endl;
    }
};


class Library {
private:
    vector<Book> books;

public:
    void addBook(string t, string a) {
        books.push_back(Book(t, a));
        cout << "Book added: " << t << endl;
    }

    void showBooks() {
        cout << "\nLibrary Collection:\n";
        if (books.empty()) {
            cout << "No books in the library yet.\n";
        }
        for (auto &b : books) b.display();
    }

    void borrowBook(string t) {
        for (auto &b : books) {
            if (b.getTitle() == t) {
                b.borrowBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook(string t) {
        for (auto &b : books) {
            if (b.getTitle() == t) {
                b.returnBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    int choice;
    string title, author;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                lib.addBook(title, author);
                break;
            case 2:
                lib.showBooks();
                break;
            case 3:
                cout << "Enter title to borrow: ";
                getline(cin, title);
                lib.borrowBook(title);
                break;
            case 4:
                cout << "Enter title to return: ";
                getline(cin, title);
                lib.returnBook(title);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
