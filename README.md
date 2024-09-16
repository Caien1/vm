# Virtual Machine (VM) Implementation

## Overview

This project is a basic implementation of a virtual machine (VM) that simulates CPU functionality. It includes a basic control unit, memory, and several CPU registers. The VM performs fetching, decoding, and basic operations such as clearing registers, complementing values, and handling specific instructions like HALT, SKIP, and INCREMENT. The instruction set includes both standard operations and register reference instructions (RRI).

## Features

- **Registers**:
  - 12-bit Address Register (AR) and Program Counter (PC)
  - 16-bit Data Register (DR), Accumulator (AC), Instruction Register (IR), Temporary Register (TR)
  - 8-bit Input Register (INPR) and Output Register (OUT)
- **Memory**: 4KB memory space (4096 words of 16 bits each).
- **Fetch, Decode, Execute Cycle**: Fetches instructions from memory, decodes them, and performs operations based on the instruction set.
- **Instruction Set (RRI)**: Includes register reference instructions such as `CLA`, `CLE`, `CMA`, `INC`, `SPA`, `SNA`, and more.
- **Helper Functions**: Includes utility functions for bitwise operations, such as retrieving bit values from registers.

## File Descriptions

### 1. `main.c`

The entry point of the virtual machine program. It initializes the CPU registers and memory, performs the fetch operation, and prints the current state of the CPU after the fetch.

- **Key Functionality**:
  - Initializes registers and memory.
  - Executes a `fetch()` to retrieve an instruction from memory.
  - Prints the state of various CPU registers.

### 2. `vm_cpu.h`

Defines the CPU registers and basic operations.

- **Structures**:
  - `REG12`: For 12-bit registers, containing the **Address Register (AR)** and **Program Counter (PC)**.
  - `REG16`: For 16-bit registers, including the **Data Register (DR)**, **Accumulator (AC)**, **Instruction Register (IR)**, and **Temporary Register (TR)**.
  - `IO`: For 8-bit input/output handling with **Input Register (INPR)** and **Output Register (OUT)**.

- **Functions**:
  - `clear(uint16_t*)`: Clears the content of a register.
  - `incr(uint16_t*)`: Increments the content of a register.
  - `complement(uint16_t*)`: Performs a bitwise NOT operation on a register.

### 3. `vm_control_unit.h`

Contains the logic for the control unit, responsible for fetching and decoding instructions.

- **Functions**:
  - `fetch(REG16 *r16, REG12 *r12, uint16_t M[])`: Fetches the next instruction from memory and increments the program counter (PC).
  - `decode(REG16 *r16, REG12 *r12, uint16_t M[])`: Placeholder function for decoding instructions, extracting the opcode from the instruction register (IR).

### 4. `vm_memory.h`

Defines the memory for the virtual machine.

- **Memory**:
  - `uint16_t M[4096]`: An array representing 4KB of memory (4096 words of 16 bits each).

### 5. `vm_iset_rri.h`

Defines the Register Reference Instructions (RRI) for the VM. These instructions manipulate the accumulator and other registers directly.

- **Instructions**:
  - `CLA`: Clear the Accumulator.
  - `CLE`: Clear the E (extended) register.
  - `CMA`: Complement the Accumulator (bitwise NOT).
  - `CIR`: Circulate the Accumulator and E register to the right.
  - `CIL`: Circulate the Accumulator and E register to the left.
  - `INC`: Increment the Accumulator.
  - `SPA`: Skip next instruction if Accumulator is positive.
  - `SNA`: Skip next instruction if Accumulator is negative.
  - `SZA`: Skip next instruction if Accumulator is zero.
  - `SZE`: Skip next instruction if E is zero.
  - `HLT`: Halt the machine.

- **Functions**:
  - `clearAC(uint16_t* ac)`: Clears the Accumulator.
  - `complementAC(uint16_t* ac)`: Complements the Accumulator.
  - `skipifpositive(uint16_t* ac, int* pc)`: Skips the next instruction if the Accumulator is positive.
  
### 6. `boolean.h`

Contains helper functions for bitwise operations.

- **Functions**:
  - `getBitValue(uint16_t num, int bitPosition)`: Returns the value (1 or 0) of the bit at the specified position in a 16-bit number.

## Getting Started

### Prerequisites

To compile and run the project, you need:

- A C compiler (e.g., GCC)
- Make sure you include the standard libraries:
  - `stdint.h`
  - `stdio.h`
  - `unistd.h`

### Compilation

You can compile the project using GCC with the following command:

```bash
gcc -o vm main.c
