//
// Created by disaa on 23/04/2025.
//

#include "Biography.h"

std::string Biography::summary() {
    std::string result = "iets over iemand";
    return result;
}

Biography::Biography(std::string& title, std::string& author, std::string& subject){
    this->title     = title;
    this->author    = author;
    this->subject   = subject;
}

