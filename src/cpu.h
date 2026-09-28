#include <stdint.h>

/* 6502 is a single core cpu. It has no threads and no SIMD.
 One instruction stream, one program counter, one ALU.
 We have 6 architectural registers that is available to programmer.

 ARCHITECTURAL STATE is what assembly programmer sees. We see 6 registers,
 but surely there is alot going on beneath. Another thing is
 architectural state is fixed - if you want to do computations 6502 way,
 then you have to follow the 6502 architectural rules. But, you are free
 to improvise with microarchitectural state. The ISA is fixed, implementation
 details - flexible. ISA can be said to be one abstraction level above
 microarchitecture.


 */

struct cpu {
  uint8_t A; // Accumulator (8-bit)
  uint8_t X; // Index Register X (8-bit)
  uint8_t Y; // Index Register Y (8-bit)
  uint8_t S; // Stack Pointer (8-bit)
  uint8_t P; // Processor Status Flags (8-bit)

  uint16_t PC; // Program Counter (16-bit - can address 64KB of RAM)
};

/* The Accumulator is the heavy lifter and most important. 

Index register can be compared to i subscript in C arrays. If we have a base
address 0x2000 and want to jump 3 bytes, the X register holds the index value -
0x03. Obviously math cannot be done on data sitting in memory. They have to be
temporarily hold inside registers. The index register X explicitly holds the
index value 0x03, while 0x2000 is not assigned to any specific register. Base on
https://github.com/Arlet/verilog-6502 which is what I use as a rulebook, 0x2000
is stored by some internal registers.

Arlet's implementation lists several such registers - ABL , ABH and ADD.

*/
