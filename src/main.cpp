#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/lexer.hpp"

int main(int argc, char *argv[])
{
    // catch args
    if (argc != 2)
    {
        std::cout << "Usage: semp <text.semp>" << '\n';
        return EXIT_FAILURE;
    }

    // create lexer object that reads .semp file
    semp::Lexer lexer(static_cast<std::string>(argv[1]));

    // tokenize source file
    std::vector<semp::Token> tokens{lexer.tokenize()};

    for (const auto &element : tokens)
    {
        std::cout << element << '\n';
    }

    return EXIT_SUCCESS;
}
