#include "InputManager.hpp"
#include <iostream>
#include <sstream>

char InputManager::GetChar(const string &errorMessage, const std::initializer_list<char> &validCharacters)
{
    std::string line;
    
    char valueToReturn = ' ';
    
    while (std::getline(std::cin, line))
    {
        if (line.size( ) == 1)
        {
            valueToReturn = line.at( 0 );
            
            for (const char element : validCharacters)
            {
                if (element == valueToReturn )
                { return valueToReturn; }
            }
        }
        
        std::cout << errorMessage << std::endl;
        cout << ">> ";
    }
    
    return valueToReturn;
}

int InputManager::GetInt(const string &errorMessage)
{
    std::string line;
    
    int valueToReturn = 0;
    
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        
        if (ss >> valueToReturn)
        {
            if (ss.eof())
            { break; }
        }
        
        std::cout << errorMessage << std::endl;
        cout << ">> ";
    }
    
    return valueToReturn;
}

string InputManager::GetString(const string &errorMessage)
{
    std::string line;
        
    while (std::getline(std::cin, line))
    {
        if (line.size() > 0)
        { break; }
        
        cout << errorMessage << endl;
        cout << ">> ";
    }
    
    return line;
}
