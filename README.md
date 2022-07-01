# Mars Rover Challenge

## Instructions
1. Enter the grid's top right coordinates, for example "5 5"
2. Spawn a robot by entering it's starting position and direction, for example "1 2 N"
3. Move the spawned robot using the letters L, R & M, for example "LMLMLMLMM"
4. See output for robot's new position
5. Repeat spawning robots until the "END" command is input

### Legend

#### Direction Commands
- N - North
- E - East
- S - South
- W - West

#### Movement Commands
- L - Left (rotate anticlockwise by 90 degrees)
- R - Right (rotate clockwise by 90 degrees)
- M - Move forward one space in the direction the robot is facing

## Testing

To enable testing, uncomment the line "#define RUN_TESTS" in main.cpp.

## What Was Missed

-Not required but I would have liked to add a graphical element using a framework such as SFML
-Making a templated GetInput function
-Using glm::vectors for coordinates
-"END" command requires all capitals, would have made it so it wasn't case sensitive
-Whitespace at the start or end of a string currently produces an invalid command, if further expanded it would have trimmed whitespace
-More than a single space in the middle of a string currently produces an invalid command, if further expanded it would have ignored the extra whitespace
-More precise error messages when inputting incorrect strings

## Assumptions
-Grid size would be n+1 due to the lower-left starting at (0, 0)
-Robots cannot go outside of the plateau, even if it ends up back inside of the plateau by the end of the movement command
-Robots can overlap one another

## Design Decisions
-The grid though simple, was abstracted into its own class to provide a foundation for extending it if need be for more complex functionality
-while (true) was used because the problem was similar to a game, in game development game loops akin to this are very common - it allowed repeated user input until the user ended the application
-Robot position was reset if movement failed, providing the ability to add retry functionality in the future
-GetInt though not used, was implemented in the scenario it could be used to get the inputs separately instead of all on one line
