#include "Rover.hpp"

Rover::Rover(const int xGridStartPos, const int yGridStartPos, const char direction, const int topRightX, const int topRightY)
{
    _xPos = xGridStartPos;
    _yPos = yGridStartPos;
    
    _gridTopRightX = topRightX;
    _gridTopRightY = topRightY;
    
    SetDirection(direction);
}

void Rover::RotateLeft()
{
    // Check if direction needs to loop around for the enum
    if ((int)_direction - 1 == 0)
    { _direction = eDirection::WEST; }
    else
    { _direction = (eDirection)((int)_direction - 1); }
}

void Rover::RotateRight()
{
    // Check if direction needs to loop around for the enum
    if ((int)_direction + 1 == 5)
    { _direction = eDirection::NORTH; }
    else
    { _direction = (eDirection)((int)_direction + 1); }
}

void Rover::Move()
{
    switch (_direction)
    {
        case eDirection::NORTH:
            _yPos++;
            
            break;
            
        case eDirection::EAST:
            _xPos++;
            
            break;
            
        case eDirection::SOUTH:
            _yPos--;
            
            break;
            
        case eDirection::WEST:
            _xPos--;
            
            break;
    }
}

Rover::eCommandStatus Rover::ProcessMovementCommandString(const string &commandStr)
{
    eCommandStatus status = eCommandStatus::SUCCESS;
    
    for (int i = 0; i < commandStr.size( ); i++)
    {
        // Check if the move command is valid
        if (!IsCommandCharValid(commandStr[i]))
        {
            status = eCommandStatus::FAIL_NOT_VALID_FORMAT;
            
            break;
        }
    }
    
    // If command is valid, then check if the robot will stay within the boundary
    if (status == eCommandStatus::SUCCESS)
    {
        int initialXPos = _xPos;
        int initialYPos = _yPos;
        
        for (int i = 0; i < commandStr.size( ); i++)
        {
            switch (commandStr[i])
            {
                case 'L':
                case 'l':
                    RotateLeft();
                    
                    break;
                    
                case 'R':
                case 'r':
                    RotateRight();
                    
                    break;
                    
                case 'M':
                case 'm':
                    Move();
                    
                    break;
            }
            
            if (!( _xPos >= 0 && _xPos <= _gridTopRightX
                && _yPos >= 0 && _yPos <= _gridTopRightY))
            {
                status = eCommandStatus::FAIL_OUT_OF_BOUNDS;
                _xPos = initialXPos;
                _yPos = initialYPos;
                
                break;
            }
        }
    }
    
    return status;
}

int Rover::GetXPos() const
{ return _xPos; }

int Rover::GetYPos() const
{ return _yPos; }

char Rover::GetDirectionAsChar() const
{
    switch (_direction)
    {
        case eDirection::NORTH:
            return 'N';
            
            break;
            
        case eDirection::EAST:
            return 'E';
            
            break;
            
        case eDirection::SOUTH:
            return 'S';
            
            break;
            
        case eDirection::WEST:
            return 'W';
            
            break;
    }
}

bool Rover::IsCommandCharValid(const char command)
{
    switch (command)
    {
        case 'L':
        case 'l':
        case 'R':
        case 'r':
        case 'M':
        case 'm':
            return true;
            
            break;
    }
    
    return false;
}

void Rover::SetDirection(const char direction)
{
    // Check which direction has been passed through
    switch (direction)
    {
        case 'N':
        case 'n':
            _direction = eDirection::NORTH;
            
            break;
            
        case 'E':
        case 'e':
            _direction = eDirection::EAST;
            
            break;
            
        case 'S':
        case 's':
            _direction = eDirection::SOUTH;
            
            break;
            
        case 'W':
        case 'w':
            _direction = eDirection::WEST;
            
            break;
            
        default:
            _direction = eDirection::NORTH;
    }
}
