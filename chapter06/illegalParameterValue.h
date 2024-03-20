#pragma once

#include <exception>

class illegalParameterValue : public std::exception
{
public:
    illegalParameterValue(const std::string& str) {

    }
};