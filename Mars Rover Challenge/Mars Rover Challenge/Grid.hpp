#pragma once

class Grid
{
public:
    /**
     * \brief Class constructor
     */
    Grid(const int x, const int y) : _x(x), _y(y) { }
    
    /**
     * \brief Class destructor
     */
    ~Grid() { }
    
    /**
     * \brief Get the grid top right x coordinate
     *
     * \return Returns the x coordinate
     */
    [[nodiscard]] int GetX() const;
    /**
     * \brief Get the grid top right y coordinate
     *
     * \return Returns the y coordinate
     */
    [[nodiscard]] int GetY() const;
    
private:
    /**
     * \brief Grid top right coordinates
     */
    int _x, _y;
    
};
