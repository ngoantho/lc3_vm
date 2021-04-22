#ifndef OPCODES
#define OPCODES

/* Instruction Set */
enum {
  OP_BR = 0,  /* Branch */
  OP_ADD,     /* Add */
  OP_LD,      /* Load */
  OP_ST,      /* Store */
  OP_JSR,     /* Jump to Subroutine */
  OP_AND,     /* Bitwise AND */
  OP_LDR,     /* Load Register */
  OP_STR,     /* Store Register */
  OP_RTI,     /* Return from Interrupt (unused) */
  OP_NOT,     /* Bitwise NOT */
  OP_LDI,     /* Load Indirect */
  OP_STI,     /* Store Indirect */
  OP_JMP,     /* Jump (also RET return) */
  OP_RES,     /* Reserved (unused) */
  OP_LEA,     /* Load Effective Address */
  OP_TRAP     /* Execute Trap */
};

/* Trap Code */
enum {
  TRAP_GETC = 0x20, // get character
  TRAP_OUT = 0x21, // output character
  TRAP_PUTS = 0x22, // output string
  TRAP_IN = 0x23, // input string
  TRAP_PUTSP = 0x24, // output byte string
  TRAP_HALT = 0x25 // halt
};

#endif // OPCODES
