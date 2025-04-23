#pragma once
#include <string>
#include "IForSale.h"

class OfficeArticle : public IForSale {
public:
    std::string name;
    int quantity;
    double getPrice() override;
};


