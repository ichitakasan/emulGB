#ifndef OPCODES_H
#define OPCODES_H

#include <SDL/SDL.h>
#include "cpu.h"


/************************************************************************************
 *                             LIST OF INSTRUCTIONS
 ************************************************************************************/
// 8bit loads
//void add_A_n(Uint8* n);
//void cp_n(Uint8* n);

// 16bit loads
void push_nn(Uint8* n1, Uint8* n2);
void pop_nn(Uint8* n1, Uint8* n2);
//void ld_A_nn(Uint16* n);

// 8bit ALU

// 16bit Arithmetic

// Miscellaneous
void nop();

// Rotates and shifts

//------------------------------------------------------------------------------
void testCarry3();
void testCarry7();

#endif // OPCODES_H
