#ifndef VM_CONTROL_UNIT_H
#define VM_CONTROL_UNIT_H
#include "vm_cpu.h"
#include "./helpers/helpers.h"


void fetch(REG16 *r16, REG12 *r12,uint16_t M[]){
	r12->AR = r12->PC;
	r16->IR = M[r12->AR];
	r12->PC++;
}



uint16_t decode_and_execute(REG16 *r16, REG12 *r12,uint16_t M[],FLAGS *f){

	int I = getBitValue(r16->AC, 15);
	unsigned short opcode=0;
	for(int i = 0;i<3;i++){
		opcode = opcode<<1;
		if(getBitValue(r16->IR,14-i)){
			opcode++;
		}
	}

	if (opcode==7){

		if(I==0){
			exe_regref(&r16->AC,&(f->E),&r12->PC);
		}
	}



}


#endif 
