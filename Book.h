#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

    Book* next;

    Book(std::string t, std::string a, std::string i)
        : title(t), author(a), isbn(i), isAvailable(true), next(nullptr) {
    }

    void display() const {
        std::cout << "Title: " << title
            << ", Author: " << author
            << ", ISBN: " << isbn
            << ", Status: " << (isAvailable ? "Available" : "Borrowed") << "\n";
    }
};

#endif
