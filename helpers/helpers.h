#ifndef BOOLEAN_H
#define BOOLEAN_H
#include<unistd.h>
int getBitValue(uint16_t num, int bitPosition) {
    // Create a bitmask with only the specified bit set to 1
    uint16_t bitmask = (uint16_t)(1U << bitPosition);

    // Use bitwise AND to check if the bit is set
    uint16_t result = num & bitmask;

    // Return 1 if the bit is set, 0 otherwise
    return (result != 0);
}


#endif // !
