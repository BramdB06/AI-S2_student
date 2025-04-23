#pragma once
#include "Book.h"

class FictionBook : public Book {
public:
    std::string genre;
    std::string summary() override;
    double getPrice() override;
    FictionBook(std::string title, std::string author, std::string genre);
};
