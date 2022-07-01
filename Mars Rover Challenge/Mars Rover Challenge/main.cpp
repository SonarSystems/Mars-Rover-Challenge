#include <iostream>
#include <ctype.h>
#include <stdlib.h>

// UNCOMMENT TO RUN TESTS
//#define RUN_TESTS

#include "Grid.hpp"
#include "Rover.hpp"
#include "InputManager.hpp"
#include "StringProcessor.hpp"

#ifdef RUN_TESTS
#include "TESTING.hpp"
#endif

using namespace std;

int main(int argc, const char *argv[])
{
#ifdef RUN_TESTS
    RunTests();
#else
    int x, y;
    
    cout << "---------------------------------------" << endl;
    cout << "|  WELCOME TO THE MARS ROVER PROGRAM  |" << endl;
    cout << "---------------------------------------" << endl;
    
    cout << "\nIn this program, you will get to control robots on Mars." << endl;
    cout << "Please input the grid size (for example '5 10' is a 5 by 10 grid)" << endl;
    
    // Get the grid size from the user
    while (true)
    {
        while (true)
        {            
            cout << ">> ";
            string gridSizeInputStr = InputManager::GetString( );
            
            StringFormatType format = ProcessString(gridSizeInputStr, false);
            
            // Check if coordinates are the right length
            if (format.xCoordinateLength > 0 && format.yCoordinateLength > 0)
            {
                x = atoi(gridSizeInputStr.substr(0, format.xCoordinateLength + 1).c_str());
                y = atoi(gridSizeInputStr.substr(format.xCoordinateLength + 1, format.yCoordinateLength).c_str());
                
                if (x > 0 && y > 0)
                { break; }
            }
            
            cout << "ERROR: INVALID GRID SIZE, PLEASE TRY AGAIN" << endl;
        }
        
        cout << "You have chosen a grid size of " << x << ":" << y << endl;
        cout << "Is this correct (y for yes and n for no)?" << endl;
        cout << ">> ";
        
        char isCorrectInput = InputManager::GetChar("PLEASE INPUT A VALID CHARACTER (SINGLE LETTER ONLY)", { 'y', 'Y', 'n', 'N' });
        
        if (isCorrectInput == 'y' || isCorrectInput == 'Y')
        { break; }
        else if (isCorrectInput == 'n' || isCorrectInput == 'N')
        { cout << "Sorry to hear that, please input the correct grid size" << endl; }
    }
    
    Grid grid(x, y);
    
    // Spawn robots based on the user input and move them
    while (true)
    {
        cout << "\n\n\n";
        
        char direction;
        
        cout << "Enter robot starting coordinates initial direction (for example '1 2 N')" << endl;
        cout << "N - North" << endl;
        cout << "E - East" << endl;
        cout << "S - South" << endl;
        cout << "W - West" << endl;
        cout << "Type \"END\" to stop spawning robots" << endl;
        
        // Get input for the robot starting position and direction
        while (true)
        {
            cout << ">> ";
            string robotSpawnInputStr = InputManager::GetString( );
            
            if (robotSpawnInputStr == "END" || robotSpawnInputStr == "end")
            {
                cout << "\n\nGoodbye\n\n" << endl;
                
                return EXIT_SUCCESS;
            }
            
            StringFormatType format = ProcessString(robotSpawnInputStr, true);
            
            if (format.xCoordinateLength > 0 && format.yCoordinateLength > 0)
            {
                x = atoi(robotSpawnInputStr.substr(0, format.xCoordinateLength + 1).c_str());
                y = atoi(robotSpawnInputStr.substr(format.xCoordinateLength + 1, format.yCoordinateLength).c_str());
                
                direction = robotSpawnInputStr.substr(robotSpawnInputStr.size() - 1, 1)[0];
                
                if (x > 0 && y > 0 && format.isDirection
                    && x <= grid.GetX() && y <= grid.GetY())
                { break; }
            }
            
            cout << "ERROR: INVALID ROBOT START POSITION/DIRECTION, PLEASE TRY AGAIN" << endl;
        }
        
        cout << "You have chosen to spawn the robot at " << x << ":" << y << " and with direction " << direction << endl;
        cout << "Is this correct (y for yes and n for no)?" << endl;
        cout << ">> ";
        
        char isCorrectInput = InputManager::GetChar("PLEASE INPUT A VALID CHARACTER (SINGLE LETTER ONLY)", { 'y', 'Y', 'n', 'N' });
        
        if (isCorrectInput == 'y' || isCorrectInput == 'Y')
        {
            Rover robot(x, y, direction, grid.GetX(), grid.GetY());
            
            cout << "Please input movement command. It must be entered as a single command with the following characters, no spaces allowed." << endl;
            cout << "L - Left" << endl;
            cout << "R - Right" << endl;
            cout << "M - Move" << endl;
            cout << "For example \"LMLMLMLMM\"" << endl;
            cout << ">> ";
            string movementCommandStr = InputManager::GetString();
            
            Rover::eCommandStatus status = robot.ProcessMovementCommandString(movementCommandStr);
            
            switch (status)
            {
                case Rover::eCommandStatus::SUCCESS:
                    cout << "\n\n\n";
                    cout << "------------------------" << endl;
                    cout << "| Movement Successful: |" << endl;
                    cout << "------------------------" << endl;
                    cout << "  -New robot position-  " << endl;
                    cout << robot.GetXPos() << " " << robot.GetYPos() << " " << robot.GetDirectionAsChar() << endl;
                    
                    break;
                case Rover::FAIL_NOT_VALID_FORMAT:
                    cout << "ERROR: MOVEMENT COMMAND IS NOT VALID" << endl;
                    
                    break;
                case Rover::FAIL_OUT_OF_BOUNDS:
                    cout << "YOU HAVE MOVED THE ROBOT OUTSIDE OF THE BOUNDARY, TERRIBLE THINGS WILL HAPPEN WHEN THE MARTIANS GET HOLD OF THIS TECHNOLOGY" << endl;
                    
                    break;
            }
        }
        else if (isCorrectInput == 'n' || isCorrectInput == 'N')
        { cout << "Sorry to hear that, please input the correct coordinates and direction" << endl; }
    }
#endif
    
    return EXIT_SUCCESS;
    
}
