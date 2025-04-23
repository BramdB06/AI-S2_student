//
// Created by disaa on 23/04/2025.
//

#pragma once
#include <string>
#include "IForSale.h"

class Book : public IForSale {
public:
    std::string title;
    std::string author;
    double getPrice() override;
    virtual std::string summary() = 0;
};
