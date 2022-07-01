#pragma once

// https://boost-ext.github.io/ut/#quick-start
#include "boost/ut.hpp"
#include "Grid.hpp"
#include "Rover.hpp"
#include "StringProcessor.hpp"

static void RunTests()
{
    // Check string processing for coordinates only - for grid creation
    boost::ut::expect(ProcessString("1 1", false).xCoordinateLength == 1);
    boost::ut::expect(ProcessString("1 1", false).yCoordinateLength == 1);
    boost::ut::expect(ProcessString("5 5", false).xCoordinateLength == 1);
    boost::ut::expect(ProcessString("5 5", false).yCoordinateLength == 1);
    boost::ut::expect(ProcessString("100 100", false).xCoordinateLength == 3);
    boost::ut::expect(ProcessString("100 100", false).yCoordinateLength == 3);
    boost::ut::expect(ProcessString("5 5", false).isDirection == false);
    boost::ut::expect(ProcessString("5 5", true).isDirection == false);
    
    // Check string processing for robot creation
    boost::ut::expect(ProcessString("1 2 n", true).xCoordinateLength == 1);
    boost::ut::expect(ProcessString("1 2 n", true).yCoordinateLength == 1);
    boost::ut::expect(ProcessString("1 2 n", true).isDirection == true);
    boost::ut::expect(ProcessString("3 3 e", true).xCoordinateLength == 1);
    boost::ut::expect(ProcessString("3 3 e", true).yCoordinateLength == 1);
    boost::ut::expect(ProcessString("3 3 e", true).isDirection == true);
    boost::ut::expect(ProcessString("10 10 s", true).xCoordinateLength == 2);
    boost::ut::expect(ProcessString("10 10 s", true).yCoordinateLength == 2);
    boost::ut::expect(ProcessString("10 10 s", true).isDirection == true);
}
