#pragma once

#include <string>
#include <initializer_list>

using namespace std;

class InputManager
{
public:
    /**
     * \brief Class constructor
     */
    InputManager( ) { };
    /**
     * \brief Class destructor
     */
    ~InputManager( ) { };
    
    /**
     * \brief Get character input from the console
     *
     * \param errorMessage  Message to be displayed if a single character is not input or an invalid character has been input
     * \param validCharacters List of valid characters
     */
    [[nodiscard]] static char GetChar( const string &errorMessage, const std::initializer_list<char> &validCharacters );
    /**
     * \brief Get integer input from the console
     *
     * \param errorMessage  Message to be displayed if a number is not input
     */
    [[nodiscard]] static int GetInt( const string &errorMessage );
    
    /**
     * \brief Get string input from the console
     *
     * \param errorMessage  Message to be displayed if a string is not input
     */
    [[nodiscard]] static string GetString( const string &errorMessage = "NO STRING INPUT, PLEASE TRY AGAIN" );
        
};
