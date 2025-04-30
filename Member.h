#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

class Member {
public:
    std::string name;
    std::string id;
    Member* next;

    Member(std::string n, std::string i)
        : name(n), id(i), next(nullptr) {
    }

    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << "\n";
    }
};

#endif
