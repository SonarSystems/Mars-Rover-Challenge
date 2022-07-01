#pragma once

#include <string>

#include "Grid.hpp"

using namespace std;

class Rover
{
public:
    /**
     * \brief Status commands for the command string to determine if it is a success or fail
     */
    enum eCommandStatus
    {
        SUCCESS = 1,
        FAIL_NOT_VALID_FORMAT,
        FAIL_OUT_OF_BOUNDS
    };
    
    /**
     * \brief Direction in which the rover robot is facing
     */
    enum eDirection
    {
        NORTH = 1,
        EAST,
        SOUTH,
        WEST
    };
    
    /**
     * \brief Class constructor
     *
     * \param xGridStartPos Starting position of the robot in the x axis
     * \param yGridStartPos Starting position of the robot in the y axis
     * \param direction Initial direction the robot is facinf
     * \param topRightX Grid's top right x coordinate
     * \param topRightY Grid's top right y coordinate
     */
    Rover(const int xGridStartPos, const int yGridStartPos, const char direction, const int topRightX, const int topRightY);
    
    /**
     * \brief Class destructor
     */
    ~Rover() { };
    
    /**
     * \brief Rotate the robot anticlockwise 90 degrees
     */
    void RotateLeft();
    /**
     * \brief Rotate the robot clockwise 90 degrees
     */
    void RotateRight();
    /**
     * \brief Move the robot forward one space in the direction it is facing
     */
    void Move();
    /**
     * \brief Proccesses the movement command string, if valid moves the robot
     *
     * \param commandStr String to process
     *
     * \return Returns success or fail
     */
    [[nodiscard]] eCommandStatus ProcessMovementCommandString(const string &commandStr);
    
    /**
     * \brief Get the robots x coordinate
     *
     * \return Returns the x coordinate
     */
    [[nodiscard]] int GetXPos() const;
    /**
     * \brief Get the robots y coordinate
     *
     * \return Returns the y coordinate
     */
    [[nodiscard]] int GetYPos() const;
    /**
     * \brief Get the direction the robot is facing as a character
     *
     * \return Returns the robot direction
     */
    [[nodiscard]] char GetDirectionAsChar() const;
    
private:
    /**
     * \brief Check if the command character is valid
     *
     * \param command Character to check
     *
     * \return Returns true if it is valid, false if it is not valid
     */
    [[nodiscard]] bool IsCommandCharValid(const char command);
    /**
     * \brief Set the robot's direction
     *
     * \param direction New robot direction
     */
    void SetDirection(const char direction);
    
    /**
     * \brief Robot position and direction
     */
    int _xPos;
    int _yPos;
    eDirection _direction;
    
    /**
     * \brief Top right coordinates of the grid
     */
    int _gridTopRightX;
    int _gridTopRightY;
    
};
