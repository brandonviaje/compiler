#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/token.hpp"
 
// convert characters into tokens
std::vector<semp::Token> tokenize(const std::string& str) 
{
    std::vector<semp::Token> tokens;
    std::string buffer;

    std::size_t i {};
    while (i < str.length()) {
        char c = str[i];

        // skip whitespace
        if (std::isspace(c)) 
        {
            i++;
            continue;
        }

        // semicolon
        if (c == ';') 
        {
            tokens.push_back({semp::TokenType::_SEMICOLON, ";", 0});
            i++;
            continue;
        }

        // identifier / keyword
        if (std::isalpha(c)) 
        {
            buffer.clear();
            while (i < str.length() && std::isalpha(str[i])) {
                buffer.push_back(str[i]);
                i++;
            }

            // check for keywords
            if (buffer == "ret") 
            {
                tokens.push_back({semp::TokenType::_RETURN, buffer, 0});
            } 
            else 
            {
                std::cerr << "Unknown identifier: " << buffer << std::endl;
                exit(EXIT_FAILURE);
            }
            continue;
        }

        // integer literal
        if (std::isdigit(c)) 
        {
            buffer.clear();

            // keep scanning if char is still a digit
            while (i < str.length() && std::isdigit(str[i])) 
            {
                buffer.push_back(str[i]);
                i++;
            }

            tokens.push_back({semp::TokenType::_INT_LITERAL, buffer, 0});  // add to tokens
            continue;
        }

        std::cerr << "Unexpected character: " << c << std::endl; // unknown character
        exit(EXIT_FAILURE);
    }

    return tokens;
}

int main(int argc, char * argv[])
{
    // catch args
    if(argc != 2)
    {
        std::cout << "Usage: semp <text.semp>" << '\n';
        return EXIT_FAILURE;
    }

    std::fstream input(argv[1], std::ios::in);
    std::stringstream buffer_stream;
    
    buffer_stream << input.rdbuf();         // load file into buffer
    input.close();

    std::string contents {buffer_stream.str()};
    std::vector<semp::Token> tokens {tokenize(contents)};

    for (const auto& element : tokens) 
    {
        std::cout << element << '\n';
    }

    return EXIT_SUCCESS;
}
