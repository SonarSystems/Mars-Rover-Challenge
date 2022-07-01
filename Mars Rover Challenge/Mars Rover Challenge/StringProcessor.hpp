#pragma once

#include <string>

using namespace std;

struct StringFormatType
{
    int xCoordinateLength = 0;
    int yCoordinateLength = 0;
    bool isDirection = false;
};

[[nodiscard]] static StringFormatType ProcessString(const string &str, bool isDirection)
{
    StringFormatType format;
    
    int currentProcessStage = 1;
    int maxProcessStages = 2;
    
    if (isDirection)
    { maxProcessStages = 3; }
    
    for (int i = 0; i < str.size( ); i++)
    {
        if (currentProcessStage == 1)
        {
            if (!isdigit(str[i]))
            {
                if (i > 0 && str[i] == ' ')
                {
                    format.xCoordinateLength = i;
                    currentProcessStage++;
                }
                else
                { break; }
            }
        }
        else if (currentProcessStage == 2)
        {
            if (!isdigit(str[i]))
            {
                if (i > format.xCoordinateLength && str[i] == ' '
                    && maxProcessStages == 3)
                {
                    format.yCoordinateLength = i - format.xCoordinateLength - 1;
                    
                    currentProcessStage++;
                }
                else
                { break; }
            }
            
            if (i + 1 == str.size() && maxProcessStages == 2)
            { format.yCoordinateLength = (int)str.size() - format.xCoordinateLength - 1; }
        }
        else if (currentProcessStage == 3)
        {
            if (i + 1 == str.size())
            {
                switch (str[i])
                {
                    case 'N':
                    case 'n':
                    case 'E':
                    case 'e':
                    case 'S':
                    case 's':
                    case 'W':
                    case 'w':
                        format.isDirection = true;
                        
                        break;
                }
            }
        }
    }
    
    return format;
}
