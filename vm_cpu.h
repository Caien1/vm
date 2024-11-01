#ifndef VM_CPU_H
#define VM_CPU_H

#include <stdint.h>

void clear( uint16_t*);
void incr(uint16_t*);
void compliment(uint16_t*);
typedef struct tweleBit{
    uint16_t AR :12;
    uint16_t PC :12;
}REG12;

typedef struct REG{
    uint16_t DR;  //16 bit Data Register
    uint16_t AC; //16 bit Accumulator Register
    uint16_t IR; // 16 bit Instruction Register
    uint16_t TR; // 16 bit Temporary Register

}REG16;


typedef struct IO{
    uint8_t INPR;
    uint8_t OUT;
}IO;
 
 typedef struct flags{
    uint16_t E;} FLAGS;

void print(){
    printf("Memory");
}
  

#endif //VM_CPU_H

