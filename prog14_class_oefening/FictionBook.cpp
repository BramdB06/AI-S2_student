//
// Created by disaa on 23/04/2025.
//

#include "FictionBook.h"

std::string FictionBook::summary() {
    std::string result = "lorum ipsum";
    return result;
}

double FictionBook::getPrice() {
    return 100000;
}

FictionBook::FictionBook(std::string title, std::string author, std::string genre) {
    this->title     = title;
    this->author    = author;
    this->genre     = genre;
}


