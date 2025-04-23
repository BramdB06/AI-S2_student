#pragma once
#include <string>

class Branch;
struct Employee {
    std::string name;
    Branch* branch;
    std::string position;
    Employee(std::string& name, std::string& position) : name(name), position(position), branch(nullptr) {}

};
