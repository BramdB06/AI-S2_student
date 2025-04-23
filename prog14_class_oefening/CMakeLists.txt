cmake_minimum_required(VERSION 3.30)
project(untitled1)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled1 main.cpp
        IForSale.h
        OfficeArticle.h
        OfficeArticle.cpp
        Book.cpp
        Book.h
        FictionBook.cpp
        FictionBook.h
        Biography.cpp
        Biography.h
        Employee.h
        Branch.cpp
        Branch.h
        BookCompany.h)
