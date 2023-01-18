#ifndef GET_INPUT_HPP
#define GET_INPUT_HPP

#include <iostream>
#include <fstream>
#include <vector>


std::vector<std::string> get_input()
{
    std::string line;
    std::vector<std::string> input;
    std::ifstream file("../input.txt");

    while (getline(file, line))
    {
        if (line != "") input.push_back(line);
    }

    return input;
}

#endif