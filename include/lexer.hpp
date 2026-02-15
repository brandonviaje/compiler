#pragma once
#include <vector>
#include <iostream>
#include "token.hpp"

namespace semp
{
    class Lexer
    {
    private:
        std::string contents;
    public:
        Lexer(std::string source_code) 
            : contents{std::move(source_code)} 
        {
        }
        std::vector<Token> tokenize();
    };
};
