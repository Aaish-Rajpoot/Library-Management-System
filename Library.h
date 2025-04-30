#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <iostream>
#include <queue>

class Library {
private:
    Book* headBook;
    Member* headMember;

public:
    std::queue<std::string> reservationQueue;

    Library() : headBook(nullptr), headMember(nullptr) {}

    void addBook(std::string title, std::string author, std::string isbn) {
        Book* newBook = new Book(title, author, isbn);
        newBook->next = headBook;
        headBook = newBook;
        std::cout << "Book added.\n";
    }

    void addMember(std::string name, std::string id) {
        Member* newMember = new Member(name, id);
        newMember->next = headMember;
        headMember = newMember;
        std::cout << "Member registered.\n";
    }

    void viewBooks() {
        Book* temp = headBook;
        while (temp) {
            temp->display();
            temp = temp->next;
        }
    }

    void viewMembers() {
        Member* temp = headMember;
        while (temp) {
            temp->display();
            temp = temp->next;
        }
    }

    Book* searchBookByISBN(std::string isbn) {
        Book* temp = headBook;
        while (temp) {
            if (temp->isbn == isbn) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void borrowBook(std::string isbn) {
        Book* book = searchBookByISBN(isbn);
        if (book) {
            if (book->isAvailable) {
                book->isAvailable = false;
                std::cout << "Book borrowed successfully.\n";
            }
            else {
                std::cout << "Book not available. Added to reservation queue.\n";
                reservationQueue.push(isbn);
            }
        }
        else {
            std::cout << "Book not found.\n";
        }
    }

    void returnBook(std::string isbn) {
        Book* book = searchBookByISBN(isbn);
        if (book) {
            book->isAvailable = true;
            std::cout << "Book returned.\n";

            if (!reservationQueue.empty() && reservationQueue.front() == isbn) {
                reservationQueue.pop();
                book->isAvailable = false;
                std::cout << "Book reserved for next user in queue.\n";
            }
        }
        else {
            std::cout << "Book not found.\n";
        }
    }

    void deleteBook(std::string isbn) {
        Book* temp = headBook;
        Book* prev = nullptr;

        while (temp && temp->isbn != isbn) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            std::cout << "Book not found.\n";
            return;
        }

        if (!prev) {
            headBook = headBook->next;
        }
        else {
            prev->next = temp->next;
        }

        delete temp;
        std::cout << "Book deleted.\n";
    }
};

#endif

