#pragma once

#include <exception>

class illegalIndex : public std::exception
{
public:
    illegalIndex(const std::string& str) {

    }
};