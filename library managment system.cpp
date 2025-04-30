#include <iostream>
#include "Library.h"

void menu() {
    std::cout << "\n===== Library Management System =====\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Register Member\n";
    std::cout << "3. View All Books\n";
    std::cout << "4. View All Members\n";
    std::cout << "5. Borrow Book\n";
    std::cout << "6. Return Book\n";
    std::cout << "7. Delete Book\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Library library;
    int choice;
    std::string title, author, isbn, name, id;

    do {
        menu();
        std::cin >> choice;
        std::cin.ignore(); // flush newline

        switch (choice) {
        case 1:
            std::cout << "Enter Title: ";
            getline(std::cin, title);
            std::cout << "Enter Author: ";
            getline(std::cin, author);
            std::cout << "Enter ISBN: ";
            getline(std::cin, isbn);
            library.addBook(title, author, isbn);
            break;

        case 2:
            std::cout << "Enter Member Name: ";
            getline(std::cin, name);
            std::cout << "Enter Member ID: ";
            getline(std::cin, id);
            library.addMember(name, id);
            break;

        case 3:
            library.viewBooks();
            break;

        case 4:
            library.viewMembers();
            break;

        case 5:
            std::cout << "Enter ISBN to borrow: ";
            getline(std::cin, isbn);
            library.borrowBook(isbn);
            break;

        case 6:
            std::cout << "Enter ISBN to return: ";
            getline(std::cin, isbn);
            library.returnBook(isbn);
            break;

        case 7:
            std::cout << "Enter ISBN to delete: ";
            getline(std::cin, isbn);
            library.deleteBook(isbn);
            break;

        case 8:
            std::cout << "Exiting program...\n";
            break;

        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}
