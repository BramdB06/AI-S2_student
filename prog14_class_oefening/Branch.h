#pragma once
#include <vector>

#include "Book.h"
#include "Employee.h"
#include "OfficeArticle.h"

class Branch {
    std::vector<Employee> employees;
    std::vector<Book> books;
    std::vector<OfficeArticle> officeArticles;
};
