#include "processing.h"

commandTypeDef currentCommand = DO_NOTHING;
uint16_t count = 300;

void InvokeCommand(void)
{
    if(currentCommand)
    {
        RespondSensorValue(GetSensorValue());
        
        count = 300; // Reset count
        invokeCommandFlag = 0;
    }
}

uint8_t CheckCommand(void)
{
    if(isCommandTypingFlag)
    {
        switch (buffer[1])
        {
        // Check both capital or regular character
        // Check RST cmd
        case 0x52: case 0x72:
            if(buffer[2] == 0x53 || buffer[2] == 0x73)
            {
                if(buffer[3] == 0x54 || buffer[3] == 0x74)
                {
                    currentCommand = REQUEST;
                    return 1;
                }
            }
            break;

        // Check OK cmd
        case 0x4f: case 0x6f:
            if(buffer[2] == 0x4b || buffer[2] == 0x6b)
            {
                currentCommand = DO_NOTHING;
                invokeCommandFlag = 0;
                return 1;
            }
            break;
        
        default:
            break;
        }
    }

    return 0;
}


