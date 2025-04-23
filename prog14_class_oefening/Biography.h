#pragma once
#include <string>
#include "Book.h"

class Biography : public Book {
public:
    std::string summary() override;
    std::string subject;

    Biography(std::string& title, std::string& author, std::string& subject);
};
