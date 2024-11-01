#include <stdio.h>
#include "vm_memory.h"
#include "vm_cpu.h"
#include "vm_control_unit.h"

// #include "InstructionSET/vm_iset_RRI.h"
int main() {
  REG16 reg={0,0,0,0};
  REG12 reg12={0,0};
  IO io={0,0};
  M[0]=0x7400;
FLAGS f={0};






 prntf("AC: %x DR: %x IR: %x  TR: %x\n",reg.AC, reg.DR, reg.IR, reg.TR);

printf("AR: %x PC: %x \n",reg12.AR, reg12.PC);
printf("INPR: %x  OUT: %x\n",io.INPR, io.OUT);

 

    return 0;
}
