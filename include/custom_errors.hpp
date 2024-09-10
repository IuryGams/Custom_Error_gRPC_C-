#pragma once
#include <exception>
#include <map>
#include "enums.hpp"

namespace exceptions
{

    class CustomException final : public std::exception
    {
    private:
        ErrorType code_;
  
    public:
        explicit CustomException(ErrorType code) : code_(code) {}

        ErrorType code() const { return code_; }

        const char *what() const noexcept override
        {
            return "A custom exception ocurred";
        }
    };
}