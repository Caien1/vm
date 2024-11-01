#ifndef VM_ISET_RRI_H
#define VM_ISET_RRI_H
#include <unistd.h>
#include <./helpers/helpers.h>
// Register Refrence instructions 
#define CLA 0x7800  //clear ac ..
#define CLE 0x7400 //clear E ..
#define CMA 0x7200  // complement AC ..
#define CIR 0x7100 // complement E ..
#define CME 0x7080 // CIRculate RIght AC And E not //done
#define CIL 0x7040 // circulate LEFT AC And E //not done
#define INC 0x7020  // increment AC
#define SPA 0x7010  //Skip instruction if AC is positive
#define SNA 0x7008 //Skip instruction if AC is negative
#define SZA 0x7004 //Skip instruction if AC is zero
#define SZE 0x7002   //Skip instruction if E is zero
#define HLT 0x7001 //HALT COMPUTER

void exe_reg_ref(uint16_t *ac, uint16_t *e, uint16_t *pc){
    switch (*ac)
    {
    case CLA:
          *ac=0;
        break;
    case CLE:
        *e=0;
        break;

    case CMA:
        *ac=~(*ac);
        break; 

    case INC:
        *ac++;
        break;
    case CME:
        *e =~(*e);
        break; 
    case SPA:
   int check = getBitValue(*ac, 15); 
    if(check==0){
        *pc++;
break;
}
    
    default:
        break;
    }

}







void skipifpositive(uint16_t *ac, int *pc){
    int check = getBitValue(*ac, 15); 
    if(check==0){
        *pc++;
    }
}



void skipifnegative(uint16_t *ac, int *pc){
    int check = getBitValue(*ac, 15); 
    if(check>0){
        *pc++;
    }
}


void skipifaczero(uint16_t *ac, uint16_t *pc){
if(*ac==0){
    *pc++;
}
}

void halt(){
    while(1){
    }
}
#endif // DEBUG
