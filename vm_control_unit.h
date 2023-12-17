#ifndef VM_CONTROL_UNIT_H
#define VM_CONTROL_UNIT_H
#include "vm_cpu.h"


void fetch(REG16 *r16, REG12 *r12,uint16_t M[]){
    r12->AR = r12->PC;
    r16->IR = M[r12->AR];
    r12->PC++;
}
    
void decode(){}
#endif // !VM_INSTRUCTION_SET_H