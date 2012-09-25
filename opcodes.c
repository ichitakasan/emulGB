
#include "opcodes.h"


/************************************************************************************
 *                              8bit LOADS
 ************************************************************************************/
// LD nn, n >> Put value nn into n
void ld_B_n()	{ cpu.B = readByte(cpu.PC++); cpu.m = 2; cpu.t = 8; }			/* Opcode: 0x06 */
void ld_C_n()	{ cpu.C = readByte(cpu.PC++); cpu.m = 2; cpu.t = 8; }			/* Opcode: 0x0E */
void ld_D_n()	{ cpu.D = readByte(cpu.PC++); cpu.m = 2; cpu.t = 8; }			/* Opcode: 0x16 */
void ld_E_n()	{ cpu.E = readByte(cpu.PC++); cpu.m = 2; cpu.t = 8; }			/* Opcode: 0x1E */
void ld_H_n()	{ cpu.H = readByte(cpu.PC++); cpu.m = 2; cpu.t = 8; }			/* Opcode: 0x26 */
void ld_L_n()	{ cpu.L = readByte(cpu.PC++); cpu.m = 2; cpu.t = 8; }			/* Opcode: 0x2E */

void ld_mHL_n()	{ writeByte((cpu.H<<8) + cpu.L, readByte(cpu.PC++)); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0x36 */
void ld_A_n()	{ cpu.A = readByte(cpu.PC++); cpu.m = 2; cpu.t = 8; }							/* Opcode: 0x3E */
void ld_A_mm()	{ cpu.A = readByte(readWord(cpu.PC)); cpu.PC+=2; cpu.m = 4; cpu.t = 16; }		/* Opcode: 0xFA */
void ld_mm_A()	{ writeByte(readWord(cpu.PC), cpu.A); cpu.PC+=2; cpu.m = 4; cpu.t = 16; }		/* Opcode: 0xEA */

// LD r1, r2 >> Put value r2 into r1
void ld_A_mBC()	{ cpu.A = readByte((cpu.B<<8) + cpu.C); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x0A */
void ld_A_mDE()	{ cpu.A = readByte((cpu.D<<8) + cpu.E); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x1A */

void ld_B_B()	{ cpu.m = 1; cpu.t = 4; }										/* Opcode: 0x40 */
void ld_B_C()	{ cpu.B = cpu.C; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x41 */
void ld_B_D()	{ cpu.B = cpu.D; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x42 */
void ld_B_E()	{ cpu.B = cpu.E; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x43 */
void ld_B_H()	{ cpu.B = cpu.H; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x44 */
void ld_B_L()	{ cpu.B = cpu.L; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x45 */
void ld_B_mHL()	{ cpu.B = readByte((cpu.H<<8) + cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x46 */
void ld_B_A()	{ cpu.B = cpu.A; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x47 */

void ld_C_B()	{ cpu.C = cpu.B; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x48 */
void ld_C_C()	{ cpu.m = 1; cpu.t = 4; }										/* Opcode: 0x49 */
void ld_C_D()	{ cpu.C = cpu.D; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x4A */
void ld_C_E()	{ cpu.C = cpu.E; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x4B */
void ld_C_H()	{ cpu.C = cpu.H; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x4C */
void ld_C_L()	{ cpu.C = cpu.L; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x4D */
void ld_C_mHL()	{ cpu.C = readByte((cpu.H<<8) + cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x4E */
void ld_C_A()	{ cpu.C = cpu.A; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x4F */

void ld_D_B()	{ cpu.D = cpu.B; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x50 */
void ld_D_C()	{ cpu.D = cpu.C; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x51 */
void ld_D_D()	{ cpu.m = 1; cpu.t = 4; }										/* Opcode: 0x52 */
void ld_D_E()	{ cpu.D = cpu.E; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x53 */
void ld_D_H()	{ cpu.D = cpu.H; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x54 */
void ld_D_L()	{ cpu.D = cpu.L; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x55 */
void ld_D_mHL()	{ cpu.D = readByte((cpu.H<<8) + cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x56 */
void ld_D_A()	{ cpu.D = cpu.A; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x57 */

void ld_E_B()	{ cpu.E = cpu.B; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x58 */
void ld_E_C()	{ cpu.E = cpu.C; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x59 */
void ld_E_D()	{ cpu.E = cpu.D; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x5A */
void ld_E_E()	{ cpu.m = 1; cpu.t = 4; }										/* Opcode: 0x5B */
void ld_E_H()	{ cpu.E = cpu.H; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x5C */
void ld_E_L()	{ cpu.E = cpu.L; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x5D */
void ld_E_mHL()	{ cpu.E = readByte((cpu.H<<8) + cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x5E */
void ld_E_A()	{ cpu.E = cpu.A; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x5F */

void ld_H_B()	{ cpu.H = cpu.B; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x60 */
void ld_H_C()	{ cpu.H = cpu.C; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x61 */
void ld_H_D()	{ cpu.H = cpu.D; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x62 */
void ld_H_E()	{ cpu.H = cpu.E; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x63 */
void ld_H_H()	{ cpu.m = 1; cpu.t = 4; }										/* Opcode: 0x64 */
void ld_H_L()	{ cpu.H = cpu.L; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x65 */
void ld_H_mHL()	{ cpu.H = readByte((cpu.H<<8) + cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x66 */
void ld_H_A()	{ cpu.H = cpu.A; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x67 */

void ld_L_B()	{ cpu.L = cpu.B; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x68 */
void ld_L_C()	{ cpu.L = cpu.C; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x69 */
void ld_L_D()	{ cpu.L = cpu.D; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x6A */
void ld_L_E()	{ cpu.L = cpu.E; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x6B */
void ld_L_H()	{ cpu.L = cpu.H; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x6C */
void ld_L_L()	{ cpu.m = 1; cpu.t = 4; }										/* Opcode: 0x6D */
void ld_L_mHL()	{ cpu.L = readByte((cpu.H<<8) + cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x6E */
void ld_L_A()	{ cpu.L = cpu.A; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x6F */

void ld_mBC_A()	{ writeByte((cpu.B<<8) + cpu.C, cpu.A); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x02 */
void ld_mDE_A()	{ writeByte((cpu.D<<8) + cpu.E, cpu.A); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x12 */
void ld_mHL_A()	{ writeByte((cpu.H<<8) + cpu.L, cpu.A); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x77 */

void ld_mHL_B()	{ writeByte((cpu.H<<8) + cpu.L, cpu.B); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x70 */
void ld_mHL_C()	{ writeByte((cpu.H<<8) + cpu.L, cpu.C); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x71 */
void ld_mHL_D()	{ writeByte((cpu.H<<8) + cpu.L, cpu.D); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x72 */
void ld_mHL_E()	{ writeByte((cpu.H<<8) + cpu.L, cpu.E); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x73 */
void ld_mHL_H()	{ writeByte((cpu.H<<8) + cpu.L, cpu.H); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x74 */
void ld_mHL_L()	{ writeByte((cpu.H<<8) + cpu.L, cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x75 */

void ld_A_B()	{ cpu.A = cpu.B; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x78 */
void ld_A_C()	{ cpu.A = cpu.C; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x79 */
void ld_A_D()	{ cpu.A = cpu.D; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x7A */
void ld_A_E()	{ cpu.A = cpu.E; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x7B */
void ld_A_H()	{ cpu.A = cpu.H; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x7C */
void ld_A_L()	{ cpu.A = cpu.L; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x7D */
void ld_A_mHL()	{ cpu.A = readByte((cpu.H<<8) + cpu.L); cpu.m = 2; cpu.t = 8; }	/* Opcode: 0x7E */
void ld_A_A()	{ cpu.m = 1; cpu.t = 4; }										/* Opcode: 0x7F */

// LDH r1, (r2) >> Put value at address $FF00 + register r2 into r1
void ldh_A_mC(){ cpu.A = readByte(0xFF00 + cpu.C); cpu.m = 2; cpu.t = 8; }		/* Opcode: 0xF2 */
void ldh_mC_A(){ writeByte(0xFF00 + cpu.C, cpu.A); cpu.m = 2; cpu.t = 8; }		/* Opcode: 0xE2 */

// LD r1, (r2D) >> Put value at address r2 into r1. Decrement r2
void ld_A_mHLd(){ cpu.A = readByte((cpu.H<<8) + cpu.L);							/* Opcode: 0x3A */
				  cpu.L--; if (cpu.L == 0xFF) cpu.H--; cpu.m = 2; cpu.t = 8; }
void ld_mHLd_A(){ writeByte((cpu.H<<8) + cpu.L, cpu.A);							/* Opcode: 0x32 */
				  cpu.L--; if (cpu.L == 0xFF) cpu.H--; cpu.m = 2; cpu.t = 8; }

// LD r1, (r2I) >> Put value at address r2 into r1. Increment r2
void ld_A_mHLi(){ cpu.A = readByte((cpu.H<<8) + cpu.L); 						/* Opcode: 0x2A */
				  cpu.L++; if (cpu.L == 0x00) cpu.H++; cpu.m = 2; cpu.t = 8; }
void ld_mHLi_A(){ writeByte((cpu.H<<8) + cpu.L, cpu.A); 						/* Opcode: 0x22 */
				  cpu.L++; if (cpu.L == 0x00) cpu.H++; cpu.m = 2; cpu.t = 8; }

// LDH A, (n) >> Put memory address $FF00 + n into A
void ldh_mn_A()	{ writeByte(0xFF00 + readByte(cpu.PC++), cpu.A); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0xE0 */
void ldh_A_mn()	{ cpu.A = readByte(0xFF00 + readByte(cpu.PC++)); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0xF0 */

/************************************************************************************
 *                              16bit LOADS
 ************************************************************************************/
// LD n, nn >> Put value nn into n
void ld_BC_nn()	{ cpu.C = readByte(cpu.PC++); cpu.B = readByte(cpu.PC++); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0x01 */
void ld_DE_nn()	{ cpu.E = readByte(cpu.PC++); cpu.D = readByte(cpu.PC++); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0x11 */
void ld_HL_nn()	{ cpu.L = readByte(cpu.PC++); cpu.H = readByte(cpu.PC++); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0x21 */
void ld_SP_nn()	{ cpu.SP = readWord(cpu.PC); cpu.PC += 2; cpu.m = 3; cpu.t = 12; }					/* Opcode: 0x31 */

// LD SP, HL >> Put HL into Stack Pointer (SP)
void ld_SP_HL()	{ cpu.SP = (cpu.H<<8) + cpu.L; cpu.m = 2; cpu.t = 8; }								/* Opcode: 0xF9 */

// LDHL SP, n >> Put SP + n effective address into HL
void ldhl_SP_n(){ Sint8 n = (Sint8)readByte(cpu.PC++);												/* Opcode: 0xF8 */
				  Sint32 val = cpu.SP + n; cpu.H = (val>>8) & 0xFF; cpu.L = (val & 0xFF);
				  cpu.F = ((val>>16) != 0) ? 0x10 : 0;										// Carry flag
				  if (n >= 0) {
					if ((cpu.SP & 0x0F) + (n & 0x0F) > 0x0F) cpu.F |= 0x20;					// If carry from bit 3
				  } else{ if ((cpu.SP & 0x0F) < (n & 0x0F)) cpu.F |= 0x20; }				// If borrow from bit 3
				  cpu.m = 3; cpu.t = 12; }

// LD (nn), SP >> Put Stack Pointer (SP) at address n
void ld_mnn_SP(){ writeWord(cpu.PC, cpu.SP); cpu.PC += 2; cpu.m = 5; cpu.t = 20; }					/* Opcode: 0x08 */

// PUSH nn >> Push register pair nn onto stack. Decrement Stack Pointer (SP) twice
void push_BC()	{ cpu.SP--; writeByte(cpu.SP, cpu.B); cpu.SP--; writeByte(cpu.SP, cpu.C); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0xC5 */
void push_DE()	{ cpu.SP--; writeByte(cpu.SP, cpu.D); cpu.SP--; writeByte(cpu.SP, cpu.E); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0xD5 */
void push_HL()	{ cpu.SP--; writeByte(cpu.SP, cpu.H); cpu.SP--; writeByte(cpu.SP, cpu.L); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0xE5 */
void push_AF()	{ cpu.SP--; writeByte(cpu.SP, cpu.A); cpu.SP--; writeByte(cpu.SP, cpu.F); cpu.m = 3; cpu.t = 12; }	/* Opcode: 0xF5 */

// POP nn >> Pop two bytes off stack into register pair nn. Increment Stack Pointer (SP) twice
void pop_BC()	{ cpu.C = readByte(cpu.SP++); cpu.B = readByte(cpu.SP++); cpu.m = 3; cpu.t = 12; }		/* Opcode: C1 */
void pop_DE()	{ cpu.E = readByte(cpu.SP++); cpu.D = readByte(cpu.SP++); cpu.m = 3; cpu.t = 12; }		/* Opcode: D1 */
void pop_HL()	{ cpu.L = readByte(cpu.SP++); cpu.H = readByte(cpu.SP++); cpu.m = 3; cpu.t = 12; }		/* Opcode: E1 */
void pop_AF()	{ cpu.F = readByte(cpu.SP++); cpu.A = readByte(cpu.SP++); cpu.m = 3; cpu.t = 12; }		/* Opcode: F1 */

/************************************************************************************
 *                               8bit ALU
 ************************************************************************************/
// ADD A, n >> Add n to A
void add_A_B()	{ Uint8 val = cpu.A + cpu.B; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag		/* Opcode: 0x80 */
				  if ((cpu.A & 0x0F) + (cpu.B & 0x0F) > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.B > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void add_A_C()	{ Uint8 val = cpu.A + cpu.C; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag		/* Opcode: 0x81 */
				  if ((cpu.A & 0x0F) + (cpu.C & 0x0F) > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.C > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void add_A_D()	{ Uint8 val = cpu.A + cpu.D; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag		/* Opcode: 0x82 */
				  if ((cpu.A & 0x0F) + (cpu.D & 0x0F) > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.D > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void add_A_E()	{ Uint8 val = cpu.A + cpu.E; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag		/* Opcode: 0x83 */
				  if ((cpu.A & 0x0F) + (cpu.E & 0x0F) > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.E > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void add_A_H()	{ Uint8 val = cpu.A + cpu.H; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag		/* Opcode: 0x84 */
				  if ((cpu.A & 0x0F) + (cpu.H & 0x0F) > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.H > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void add_A_L()	{ Uint8 val = cpu.A + cpu.L; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag		/* Opcode: 0x85 */
				  if ((cpu.A & 0x0F) + (cpu.L & 0x0F) > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.L > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void add_A_mHL(){ Uint8 b = readByte((cpu.H<<8) + cpu.L); 												/* Opcode: 0x86 */
				  Uint8 val = cpu.A + b; cpu.F = (val == 0) ? 0x80 : 0;				// Zero flag
				  if ((cpu.A & 0x0F) + (b & 0x0F) > 0x0F) cpu.F |= 0x20;			// If carry from bit 3
				  if (cpu.A + b > 0xFF) cpu.F |= 0x10;								// If carry from bit 7
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }
void add_A_A()	{ Uint8 val = cpu.A + cpu.A; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag		/* Opcode: 0x87 */
				  if ((cpu.A & 0x0F) + (cpu.A & 0x0F) > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.A > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void add_A_n()	{ Uint8 b = readByte(cpu.PC++);															/* Opcode: 0xC6 */
				  Uint8 val = cpu.A + b; cpu.F = (val == 0) ? 0x80 : 0;				// Zero flag
				  if ((cpu.A & 0x0F) + (b & 0x0F) > 0x0F) cpu.F |= 0x20;			// If carry from bit 3
				  if (cpu.A + b > 0xFF) cpu.F |= 0x10;								// If carry from bit 7
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }

// ADC A, n >> Add n + Carry flag to A
void adc_A_B()	{ Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag	/* Opcode: 0x88 */
				  Uint8 val = cpu.A + cpu.B + c; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag
				  if ((cpu.A & 0x0F) + (cpu.B & 0x0F) + c > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.B + c > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void adc_A_C()	{ Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag	/* Opcode: 0x89 */
				  Uint8 val = cpu.A + cpu.C + c; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag
				  if ((cpu.A & 0x0F) + (cpu.C & 0x0F) + c > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.C + c > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void adc_A_D()	{ Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag	/* Opcode: 0x8A */
				  Uint8 val = cpu.A + cpu.D + c; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag
				  if ((cpu.A & 0x0F) + (cpu.D & 0x0F) + c > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.D + c > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void adc_A_E()	{ Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag	/* Opcode: 0x8B */
				  Uint8 val = cpu.A + cpu.E + c; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag
				  if ((cpu.A & 0x0F) + (cpu.E & 0x0F) + c > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.E + c > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void adc_A_H()	{ Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag	/* Opcode: 0x8C */
				  Uint8 val = cpu.A + cpu.H + c; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag
				  if ((cpu.A & 0x0F) + (cpu.H & 0x0F) + c > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.H + c > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void adc_A_L()	{ Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag	/* Opcode: 0x8D */
				  Uint8 val = cpu.A + cpu.L + c; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag
				  if ((cpu.A & 0x0F) + (cpu.L & 0x0F) + c > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.L + c > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void adc_A_mHL(){ Uint8 b = readByte((cpu.H<<8) + cpu.L);													/* Opcode: 0x8E */
				  Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag
				  Uint8 val = cpu.A + b + c; cpu.F = (val == 0) ? 0x80 : 0;				// Zero flag
				  if ((cpu.A & 0x0F) + (b & 0x0F) + c > 0x0F) cpu.F |= 0x20;			// If carry from bit 3
				  if (cpu.A + b + c > 0xFF) cpu.F |= 0x10;								// If carry from bit 7
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }
void adc_A_A()	{ Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag	/* Opcode: 0x8F */
				  Uint8 val = cpu.A + cpu.A + c; cpu.F = (val == 0) ? 0x80 : 0;			// Zero flag
				  if ((cpu.A & 0x0F) + (cpu.A & 0x0F) + c > 0x0F) cpu.F |= 0x20;		// If carry from bit 3
				  if (cpu.A + cpu.A + c > 0xFF) cpu.F |= 0x10;							// If carry from bit 7
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void adc_A_n()	{ Uint8 b = readByte(cpu.PC++);																/* Opcode: 0xCE */
				  Uint8 c = ((cpu.F>>4) & 0x01);										// Old carry flag
				  Uint8 val = cpu.A + b + c; cpu.F = (val == 0) ? 0x80 : 0;				// Zero flag
				  if ((cpu.A & 0x0F) + (b & 0x0F) + c > 0x0F) cpu.F |= 0x20;			// If carry from bit 3
				  if (cpu.A + b + c > 0xFF) cpu.F |= 0x10;								// If carry from bit 7
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }

// SUB n >> Substract n from A (N always set)
void sub_B()	{ Uint8 val = cpu.A - cpu.B; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag		/* Opcode: 0x90 */
				  if ((cpu.A & 0x0F) < (cpu.B & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
				  if (cpu.A < cpu.B) cpu.F |= 0x10;										// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sub_C()	{ Uint8 val = cpu.A - cpu.C; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag		/* Opcode: 0x91 */
				  if ((cpu.A & 0x0F) < (cpu.C & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
				  if (cpu.A < cpu.C) cpu.F |= 0x10;										// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sub_D()	{ Uint8 val = cpu.A - cpu.D; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag		/* Opcode: 0x92 */
				  if ((cpu.A & 0x0F) < (cpu.D & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
				  if (cpu.A < cpu.D) cpu.F |= 0x10;										// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sub_E()	{ Uint8 val = cpu.A - cpu.E; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag		/* Opcode: 0x93 */
				  if ((cpu.A & 0x0F) < (cpu.E & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
				  if (cpu.A < cpu.E) cpu.F |= 0x10;										// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sub_H()	{ Uint8 val = cpu.A - cpu.H; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag		/* Opcode: 0x94 */
				  if ((cpu.A & 0x0F) < (cpu.H & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
				  if (cpu.A < cpu.H) cpu.F |= 0x10;										// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sub_L()	{ Uint8 val = cpu.A - cpu.L; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag		/* Opcode: 0x95 */
				  if ((cpu.A & 0x0F) < (cpu.L & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
				  if (cpu.A < cpu.L) cpu.F |= 0x10;										// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sub_mHL()	{ Uint8 b = readByte((cpu.H<<8) + cpu.L);													/* Opcode: 0x96 */
				  Uint8 val = cpu.A - b; cpu.F = (val == 0) ? 0xC0 : 0x40;				// Zero flag
				  if ((cpu.A & 0x0F) < (b & 0x0F)) cpu.F |= 0x20;						// If borrow from bit 4
				  if (cpu.A < b) cpu.F |= 0x10;											// If borrow
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }
void sub_A()	{ Uint8 val = cpu.A - cpu.A; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag		/* Opcode: 0x97 */
				  if ((cpu.A & 0x0F) < (cpu.A & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
				  if (cpu.A < cpu.A) cpu.F |= 0x10;										// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sub_n()	{ Uint8 b = readByte(cpu.PC++);																/* Opcode: 0xD6 */
				  Uint8 val = cpu.A - b; cpu.F = (val == 0) ? 0xC0 : 0x40;				// Zero flag
				  if ((cpu.A & 0x0F) < (b & 0x0F)) cpu.F |= 0x20;						// If borrow from bit 4
				  if (cpu.A < b) cpu.F |= 0x10;											// If borrow
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }

// SBC A, n >> Substract n + Carry flag from A (N always set)
void sbc_A_B()	{ Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag	/* Opcode: 0x98 */
				  Uint8 val = cpu.A - cpu.B - c; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag
				  if ((cpu.A & 0x0F) - (cpu.B & 0x0F) - c < 0x00) cpu.F |= 0x20;			// If borrow from bit 4
				  if (cpu.A - cpu.B - c < 0x00) cpu.F |= 0x10;								// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sbc_A_C()	{ Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag	/* Opcode: 0x99 */
				  Uint8 val = cpu.A - cpu.C - c; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag
				  if ((cpu.A & 0x0F) - (cpu.C & 0x0F) - c < 0x00) cpu.F |= 0x20;			// If borrow from bit 4
				  if (cpu.A - cpu.C - c < 0x00) cpu.F |= 0x10;								// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sbc_A_D()	{ Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag	/* Opcode: 0x9A */
				  Uint8 val = cpu.A - cpu.D - c; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag
				  if ((cpu.A & 0x0F) - (cpu.D & 0x0F) - c < 0x00) cpu.F |= 0x20;			// If borrow from bit 4
				  if (cpu.A - cpu.D - c < 0x00) cpu.F |= 0x10;								// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sbc_A_E()	{ Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag	/* Opcode: 0x9B */
				  Uint8 val = cpu.A - cpu.E - c; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag
				  if ((cpu.A & 0x0F) - (cpu.E & 0x0F) - c < 0x00) cpu.F |= 0x20;			// If borrow from bit 4
				  if (cpu.A - cpu.E - c < 0x00) cpu.F |= 0x10;								// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sbc_A_H()	{ Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag	/* Opcode: 0x9C */
				  Uint8 val = cpu.A - cpu.H - c; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag
				  if ((cpu.A & 0x0F) - (cpu.H & 0x0F) - c < 0x00) cpu.F |= 0x20;			// If borrow from bit 4
				  if (cpu.A - cpu.H - c < 0x00) cpu.F |= 0x10;								// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sbc_A_L()	{ Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag	/* Opcode: 0x9D */
				  Uint8 val = cpu.A - cpu.L - c; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag
				  if ((cpu.A & 0x0F) - (cpu.L & 0x0F) - c < 0x00) cpu.F |= 0x20;			// If borrow from bit 4
				  if (cpu.A - cpu.L - c < 0x00) cpu.F |= 0x10;								// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sbc_A_mHL(){ Uint8 b = readByte((cpu.H<<8) + cpu.L);														/* Opcode: 0x9E */
				  Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag
				  Uint8 val = cpu.A - b - c; cpu.F = (val == 0) ? 0xC0 : 0x40;				// Zero flag
				  if ((cpu.A & 0x0F) - (b & 0x0F) - c < 0x00) cpu.F |= 0x20;				// If borrow from bit 4
				  if (cpu.A - b - c < 0x00) cpu.F |= 0x10;									// If borrow
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }
void sbc_A_A()	{ Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag	/* Opcode: 0x9F */
				  Uint8 val = cpu.A - cpu.A - c; cpu.F = (val == 0) ? 0xC0 : 0x40;			// Zero flag
				  if ((cpu.A & 0x0F) - (cpu.A & 0x0F) - c < 0x00) cpu.F |= 0x20;			// If borrow from bit 4
				  if (cpu.A - cpu.A - c < 0x00) cpu.F |= 0x10;								// If borrow
				  cpu.A = val; cpu.m = 1; cpu.t = 4; }
void sbc_A_n()	{ Uint8 b = readByte(cpu.PC++);																	/* Opcode: 0x98 */
				  Uint8 c = ((cpu.F>>4) & 0x01);											// Old carry flag
				  Uint8 val = cpu.A - b - c; cpu.F = (val == 0) ? 0xC0 : 0x40;				// Zero flag
				  if ((cpu.A & 0x0F) - (b & 0x0F) - c < 0x00) cpu.F |= 0x20;				// If borrow from bit 4
				  if (cpu.A - b - c < 0x00) cpu.F |= 0x10;									// If borrow
				  cpu.A = val; cpu.m = 2; cpu.t = 8; }

// AND n >> Logically AND n with A, result in A (H always set)
void and_B()	{ cpu.A &= cpu.B; cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA0 */
void and_C()	{ cpu.A &= cpu.C; cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA1 */
void and_D()	{ cpu.A &= cpu.D; cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA2 */
void and_E()	{ cpu.A &= cpu.E; cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA3 */
void and_H()	{ cpu.A &= cpu.H; cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA4 */
void and_L()	{ cpu.A &= cpu.L; cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA5 */
void and_mHL()	{ cpu.A &= readByte((cpu.H<<8) + cpu.L); cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; 	/* Opcode: 0xA6 */
				  cpu.m = 2; cpu.t = 8; }
void and_A()	{ cpu.A &= cpu.A; cpu.F = (cpu.A == 0) ? 0xA0 : 0x20; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA7 */
void and_n()	{ cpu.A &= readByte(cpu.PC++); cpu.F = (cpu.A == 0) ? 0xA0 : 0x20;				/* Opcode: 0xE6 */
				  cpu.m = 2; cpu.t = 8; }

// OR n >> Logical OR n with register A, result in A
void or_B()		{ cpu.A |= cpu.B; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xB0 */
void or_C()		{ cpu.A |= cpu.C; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xB1 */
void or_D()		{ cpu.A |= cpu.D; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xB2 */
void or_E()		{ cpu.A |= cpu.E; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xB3 */
void or_H()		{ cpu.A |= cpu.H; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xB4 */
void or_L()		{ cpu.A |= cpu.L; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xB5 */
void or_mHL()	{ cpu.A |= readByte((cpu.H<<8) + cpu.L); cpu.F = (cpu.A == 0) ? 0x80 : 0x00;	/* Opcode: 0xB6 */
				  cpu.m = 2; cpu.t = 8; }
void or_A()		{ cpu.A |= cpu.A; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xB7 */
void or_n()		{ cpu.A |= readByte(cpu.PC++); cpu.F = (cpu.A == 0) ? 0x80 : 0x00;				/* Opcode: 0xF6 */
				  cpu.m = 2; cpu.t = 8; }

// XOR n >> Logical XOR n with register A, result in A
void xor_B()	{ cpu.A ^= cpu.B; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA8 */
void xor_C()	{ cpu.A ^= cpu.C; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xA9 */
void xor_D()	{ cpu.A ^= cpu.D; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xAA */
void xor_E()	{ cpu.A ^= cpu.E; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xAB */
void xor_H()	{ cpu.A ^= cpu.H; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xAC */
void xor_L()	{ cpu.A ^= cpu.L; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xAD */
void xor_mHL()	{ cpu.A ^= readByte((cpu.H<<8) + cpu.L); cpu.F = (cpu.A == 0) ? 0x80 : 0x00; 	/* Opcode: 0xAE */
				  cpu.m = 2; cpu.t = 8; }
void xor_A()	{ cpu.A ^= cpu.A; cpu.F = (cpu.A == 0) ? 0x80 : 0x00; cpu.m = 1; cpu.t = 4; }	/* Opcode: 0xAF */
void xor_n()	{ cpu.A ^= readByte(cpu.PC++); cpu.F = (cpu.A == 0) ? 0x80 : 0x00; 				/* Opcode: 0xEE */
				  cpu.m = 2; cpu.t = 8; }

// CP n >> Compare A with n. This is basically an A - n substraction instruction but the results are thrown away (N always set)
void cp_B()		{ if (cpu.A == cpu.B) cpu.F = 0xC0;	else { cpu.F = 0x40;			// Z and N flags	/* Opcode: 0xB8 */
					if ((cpu.A & 0x0F) < (cpu.B & 0x0F)) cpu.F |= 0x20;				// If borrow from bit 4
					if (cpu.A < cpu.B) cpu.F |= 0x10; }	cpu.m = 1; cpu.t = 4; }		// If borrow
void cp_C()		{ if (cpu.A == cpu.C) cpu.F = 0xC0;	else { cpu.F = 0x40;			// Z and N flags	/* Opcode: 0xB9 */
					if ((cpu.A & 0x0F) < (cpu.C & 0x0F)) cpu.F |= 0x20;				// If borrow from bit 4
					if (cpu.A < cpu.C) cpu.F |= 0x10; }	cpu.m = 1; cpu.t = 4; }		// If borrow
void cp_D()		{ if (cpu.A == cpu.D) cpu.F = 0xC0;	else { cpu.F = 0x40;			// Z and N flags	/* Opcode: 0xBA */
					if ((cpu.A & 0x0F) < (cpu.D & 0x0F)) cpu.F |= 0x20;				// If borrow from bit 4
					if (cpu.A < cpu.D) cpu.F |= 0x10; }	cpu.m = 1; cpu.t = 4; }		// If borrow
void cp_E()		{ if (cpu.A == cpu.E) cpu.F = 0xC0;	else { cpu.F = 0x40;			// Z and N flags	/* Opcode: 0xBB */
					if ((cpu.A & 0x0F) < (cpu.E & 0x0F)) cpu.F |= 0x20;				// If borrow from bit 4
					if (cpu.A < cpu.E) cpu.F |= 0x10; }	cpu.m = 1; cpu.t = 4; }		// If borrow
void cp_H()		{ if (cpu.A == cpu.H) cpu.F = 0xC0;	else { cpu.F = 0x40;			// Z and N flags	/* Opcode: 0xBC */
					if ((cpu.A & 0x0F) < (cpu.H & 0x0F)) cpu.F |= 0x20;				// If borrow from bit 4
					if (cpu.A < cpu.H) cpu.F |= 0x10; }	cpu.m = 1; cpu.t = 4; }		// If borrow
void cp_L()		{ if (cpu.A == cpu.L) cpu.F = 0xC0;	else { cpu.F = 0x40;			// Z and N flags	/* Opcode: 0xBD */
					if ((cpu.A & 0x0F) < (cpu.L & 0x0F)) cpu.F |= 0x20;				// If borrow from bit 4
					if (cpu.A < cpu.L) cpu.F |= 0x10; }	cpu.m = 1; cpu.t = 4; }		// If borrow
void cp_mHL()	{ Uint8 b = readByte((cpu.H<<8) + cpu.L);												/* Opcode: 0xBE */
				  if (cpu.A == b) cpu.F = 0xC0;	else { cpu.F = 0x40;				// Z and N flags
					if ((cpu.A & 0x0F) < (b & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
					if (cpu.A < b) cpu.F |= 0x10; }	cpu.m = 2; cpu.t = 8; }			// If borrow
void cp_A()		{ if (cpu.A == cpu.A) cpu.F = 0xC0;	else { cpu.F = 0x40;			// Z and N flags	/* Opcode: 0xBF */
					if ((cpu.A & 0x0F) < (cpu.A & 0x0F)) cpu.F |= 0x20;				// If borrow from bit 4
					if (cpu.A < cpu.A) cpu.F |= 0x10; }	cpu.m = 1; cpu.t = 4; }		// If borrow
void cp_n()		{ Uint8 b = readByte(cpu.PC++);															/* Opcode: 0xFE */
				  if (cpu.A == b) cpu.F = 0xC0; else { cpu.F = 0x40;				// Z and N flags
					if ((cpu.A & 0x0F) < (b & 0x0F)) cpu.F |= 0x20;					// If borrow from bit 4
					if (cpu.A < b) cpu.F |= 0x10; }	cpu.m = 2; cpu.t = 8; }			// If borrow

// INC n >> Increment register n (C from register F not affected)
void inc_B()	{ cpu.B++; cpu.F &= 0x10; if (cpu.B == 0) cpu.F |= 0x80;				// Z and C flags	/* Opcode: 0x04 */
				  if (cpu.B == 0x10) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If carry from bit 3
void inc_C()	{ cpu.C++; cpu.F &= 0x10; if (cpu.C == 0) cpu.F |= 0x80;				// Z and C flags	/* Opcode: 0x0C */
				  if (cpu.C == 0x10) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If carry from bit 3
void inc_D()	{ cpu.D++; cpu.F &= 0x10; if (cpu.D == 0) cpu.F |= 0x80;				// Z and C flags	/* Opcode: 0x14 */
				  if (cpu.D == 0x10) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If carry from bit 3
void inc_E()	{ cpu.E++; cpu.F &= 0x10; if (cpu.E == 0) cpu.F |= 0x80;				// Z and C flags	/* Opcode: 0x1C */
				  if (cpu.E == 0x10) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If carry from bit 3
void inc_H()	{ cpu.H++; cpu.F &= 0x10; if (cpu.H == 0) cpu.F |= 0x80;				// Z and C flags	/* Opcode: 0x24 */
				  if (cpu.H == 0x10) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If carry from bit 3
void inc_L()	{ cpu.L++; cpu.F &= 0x10; if (cpu.L == 0) cpu.F |= 0x80;				// Z and C flags	/* Opcode: 0x2C */
				  if (cpu.L == 0x10) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If carry from bit 3
void inc_mHL()	{ Uint8 b = readByte((cpu.H<<8) + cpu.L) + 1; writeByte((cpu.H<<8) + cpu.L, b);				/* Opcode: 0x34 */
				  cpu.F &= 0x10; if (b == 0) cpu.F |= 0x80;								// Z and C flags
				  if (b == 0x10) cpu.F |= 0x20; cpu.m = 3; cpu.t = 12; }				// If carry from bit 3
void inc_A()	{ cpu.A++; cpu.F &= 0x10; if (cpu.A == 0) cpu.F |= 0x80;				// Z and C flags	/* Opcode: 0x3C */
				  if (cpu.A == 0x10) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If carry from bit 3

// DEC n >> Decrement register n (C from register F not affected, N is always set)
void dec_B()	{ cpu.B--; cpu.F &= 0x10; cpu.F |= (cpu.B == 0) ? 0xC0 : 0x40;			// Z and C flags	/* Opcode: 0x05 */
				  if (cpu.B == 0xFF) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If borrow from bit 4
void dec_C()	{ cpu.C--; cpu.F &= 0x10; cpu.F |= (cpu.B == 0) ? 0xC0 : 0x40;			// Z and C flags	/* Opcode: 0x0D */
				  if (cpu.C == 0xFF) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If borrow from bit 4
void dec_D()	{ cpu.D--; cpu.F &= 0x10; cpu.F |= (cpu.D == 0) ? 0xC0 : 0x40;			// Z and C flags	/* Opcode: 0x15 */
				  if (cpu.D == 0xFF) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If borrow from bit 4
void dec_E()	{ cpu.E--; cpu.F &= 0x10; cpu.F |= (cpu.E == 0) ? 0xC0 : 0x40;			// Z and C flags	/* Opcode: 0x1D */
				  if (cpu.E == 0xFF) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If borrow from bit 4
void dec_H()	{ cpu.H--; cpu.F &= 0x10; cpu.F |= (cpu.H == 0) ? 0xC0 : 0x40;			// Z and C flags	/* Opcode: 0x25 */
				  if (cpu.H == 0xFF) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If borrow from bit 4
void dec_L()	{ cpu.L--; cpu.F &= 0x10; cpu.F |= (cpu.L == 0) ? 0xC0 : 0x40;			// Z and C flags	/* Opcode: 0x2D */
				  if (cpu.L == 0xFF) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If borrow from bit 4
void dec_mHL()	{ Uint8 b = readByte((cpu.H<<8) + cpu.L) - 1; writeByte((cpu.H<<8) + cpu.L, b);				/* Opcode: 0x35 */
				  cpu.F &= 0x10; cpu.F |= (b == 0) ? 0xC0 : 0x40;						// Z and C flags
				  if (b == 0xFF) cpu.F |= 0x20; cpu.m = 3; cpu.t = 12; }				// If borrow from bit 4
void dec_A()	{ cpu.A--; cpu.F &= 0x10; cpu.F |= (cpu.A == 0) ? 0xC0 : 0x40;			// Z and C flags	/* Opcode: 0x3D */
				  if (cpu.A == 0xFF) cpu.F |= 0x20; cpu.m = 1; cpu.t = 4; }				// If borrow from bit 4


/************************************************************************************
 *                           16bit ARITHMETIC
 ************************************************************************************/
// ADD HL, n >> Add n to HL (Zero flag not affected)
void add_HL_BC(){ Uint16 hl = (cpu.H<<8) + cpu.L, bc = (cpu.B<<8) + cpu.C; cpu.F &= 0x80; // Zero flag	/* Opcode: 0x09 */
				  if ((hl & 0x0FFF) + (bc & 0x0FFF) > 0x0FFF) cpu.F |= 0x20;		// If carry from bit 11
				  if (hl + bc > 0xFFFF) cpu.F |= 0x10;								// If carry from bit 15
				  cpu.m = 3; cpu.t = 12; }
void add_HL_DE(){ Uint16 hl = (cpu.H<<8) + cpu.L, de = (cpu.D<<8) + cpu.E; cpu.F &= 0x80; // Zero flag	/* Opcode: 0x19 */
				  if ((hl & 0x0FFF) + (de & 0x0FFF) > 0x0FFF) cpu.F |= 0x20;		// If carry from bit 11
				  if (hl + de > 0xFFFF) cpu.F |= 0x10;								// If carry from bit 15
				  cpu.m = 3; cpu.t = 12; }
void add_HL_HL(){ Uint16 hl = (cpu.H<<8) + cpu.L; cpu.F &= 0x80; 					// Zero flag		/* Opcode: 0x29 */
				  if ((hl & 0x0FFF) + (hl & 0x0FFF) > 0x0FFF) cpu.F |= 0x20;		// If carry from bit 11
				  if (hl + hl > 0xFFFF) cpu.F |= 0x10;								// If carry from bit 15
				  cpu.m = 3; cpu.t = 12; }
void add_HL_SP(){ Uint16 hl = (cpu.H<<8) + cpu.L; cpu.F &= 0x80; 					// Zero flag		/* Opcode: 0x39 */
				  if ((hl & 0x0FFF) + (cpu.SP & 0x0FFF) > 0x0FFF) cpu.F |= 0x20;	// If carry from bit 11
				  if (hl + cpu.SP > 0xFFFF) cpu.F |= 0x10;							// If carry from bit 15
				  cpu.m = 3; cpu.t = 12; }

// ADD SP, n >> Add n to Stack Pointer
void add_SP_n()	{ Sint8 n = (Sint8)readByte(cpu.PC++); Sint32 val = cpu.SP + n;							/* Opcode: 0xE8 */
				  cpu.F = ((val>>16) != 0) ? 0x10 : 0;										// Carry flag
				  if (n >= 0) {
					if ((cpu.SP & 0x0F) + (n & 0x0F) > 0x0F) cpu.F |= 0x20;					// If carry from bit 3
				  } else{ if ((cpu.SP & 0x0F) < (n & 0x0F)) cpu.F |= 0x20; }				// If borrow from bit 3
				  cpu.SP = val; cpu.m = 4; cpu.t = 16; }

// INC nn >> Increment register nn
void inc_BC()	{ cpu.C++; if (cpu.C == 0x00) cpu.B++; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x03 */
void inc_DE()	{ cpu.E++; if (cpu.E == 0x00) cpu.D++; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x13 */
void inc_HL()	{ cpu.L++; if (cpu.L == 0x00) cpu.H++; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x23 */
void inc_SP()	{ cpu.SP++; cpu.m = 1; cpu.t = 4; }													/* Opcode: 0x33 */

// DEC nn >> Decrement register nn
void dec_BC()	{ cpu.C--; if (cpu.C == 0xFF) cpu.B--; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x0B */
void dec_DE()	{ cpu.E--; if (cpu.E == 0xFF) cpu.D--; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x1B */
void dec_HL()	{ cpu.L--; if (cpu.L == 0xFF) cpu.H--; cpu.m = 1; cpu.t = 4; }						/* Opcode: 0x2B */
void dec_SP()	{ cpu.SP--; cpu.m = 1; cpu.t = 4; }													/* Opcode: 0x3B */

/************************************************************************************
 *                              MISCELLANEOUS
 ************************************************************************************/
// SWAP n >> Swap upper & lower nibbles of n
void swap_n()	{ Uint8 b, n;
				  switch (cpu.PC++) {
				  case 0x30: b = (cpu.B>>4) + (cpu.B<<4);	cpu.B = b;							/* Opcode: 0xCB 30 */
					if (cpu.B == 0x00) cpu.F |= 0x80; cpu.m = 2; cpu.t = 8; break;
				  case 0x31: b = (cpu.C>>4) + (cpu.C<<4);	cpu.C = b;							/* Opcode: 0xCB 31 */
					if (cpu.C == 0x00) cpu.F |= 0x80; cpu.m = 2; cpu.t = 8; break;
				  case 0x32: b = (cpu.D>>4) + (cpu.D<<4);	cpu.D = b;							/* Opcode: 0xCB 32 */
					if (cpu.D == 0x00) cpu.F |= 0x80; cpu.m = 2; cpu.t = 8; break;
				  case 0x33: b = (cpu.E>>4) + (cpu.E<<4);	cpu.E = b;							/* Opcode: 0xCB 33 */
					if (cpu.E == 0x00) cpu.F |= 0x80; cpu.m = 2; cpu.t = 8; break;
				  case 0x34: b = (cpu.H>>4) + (cpu.H<<4);	cpu.H = b;							/* Opcode: 0xCB 34 */
					if (cpu.H == 0x00) cpu.F |= 0x80; cpu.m = 2; cpu.t = 8; break;
				  case 0x35: b = (cpu.L>>4) + (cpu.L<<4);	cpu.L = b;							/* Opcode: 0xCB 35 */
					if (cpu.L == 0x00) cpu.F |= 0x80; cpu.m = 2; cpu.t = 8; break;
				  case 0x36: n = readByte((cpu.H<<8) + cpu.L); b = (n>>4) + (n<<4);				/* Opcode: 0xCB 36 */
					writeByte((cpu.H<<8) + cpu.L, b); if (b == 0x00) cpu.F |= 0x80; cpu.m = 4; cpu.t = 16; break;
				  case 0x37: b = (cpu.A>>4) + (cpu.A<<4);	cpu.A = b;							/* Opcode: 0xCB 37 */
					if (cpu.A == 0x00) cpu.F |= 0x80; cpu.m = 2; cpu.t = 8; break;
				  }}

// DAA >> Decimal adjust register A (N not affected)
//void daa()		{ cpu.m = 1; cpu.t = 4; }														/* Opcode: 0x27 */

// CPL >> Complement A register (flip all bits)
void cpl()		{ cpu.A = ~cpu.A; cpu.F |= 0x60; cpu.m = 1; cpu.t = 4; }							/* Opcode: 0x2F */
// CCF >> Complement carry flag
void ccf()		{ cpu.F &= 0x90; cpu.F ^= 0x10; cpu.m = 1; cpu.t = 4; }								/* Opcode: 0x3F */
// SCF >> Set carry flag
void scf()		{ cpu.F &= 0x80; cpu.F |= 0x10; cpu.m = 1; cpu.t = 4; }								/* Opcode: 0x37 */

// NOP >> No-operation
void nop()		{ cpu.m = 1; cpu.t = 4; }															/* Opcode: 0x00 */

// HALT >> Power down CPU until an interrupt occurs
void halt()		{ cpu.bHalt = 1; cpu.m = 1; cpu.t = 4; }											/* Opcode: 0x76 */
// STOP >> Halt CPU & LCD display until button pressed
void stop()		{ cpu.bStop = 1; cpu.m = 1; cpu.t = 4; }											/* Opcode: 0x10 00 */
// DI >> This instruction disables interrupts but not immediately
void di()		{ cpu.bInterrupt = 0; cpu.m = 1; cpu.t = 4; }										/* Opcode: 0xF3 */
// EI >> This instruction enables interrupts but not immediately
void ei()		{ cpu.bInterrupt = 1; cpu.m = 1; cpu.t = 4; }										/* Opcode: 0xFB */

/************************************************************************************
 *                             ROTATES AND SHIFTS
 ************************************************************************************/
// RLCA >> Rotate A left. Old bit 7 to Carry flag.
void rlca()		{ cpu.m = 1; cpu.t = 4; }															/* Opcode: 0x07 */


// XX >> Undefined 8bit map entry
void XX()		{ fprintf(stderr, "Undefined 8bit opcode: 0x%x\n", cpu.PC); }

// XX >> Undefined 16bit map entry
void XXXX()		{ cpu.PC++; fprintf(stderr, "Undefined 16bit opcode: 0xCB %x\n", cpu.PC); }

/************************************************************************************
 *                            OPCODES MAPPING TABLES
 ************************************************************************************/
void (*opcodes[256])() = { \
//  	0          1          2          3          4          5          6          7          8          9          A          B          C          D          E          F
/* 0 */	nop,       ld_BC_nn,  ld_mBC_A,  inc_BC,    inc_B,     dec_B,     ld_B_n,    XX,        ld_mnn_SP, add_HL_BC, ld_A_mBC,  dec_BC,    inc_C,     dec_C,     ld_C_n,    XX, \
/* 1 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 2 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 3 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 4 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 5 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 6 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 7 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 8 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* 9 */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* A */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* B */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* C */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* D */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* E */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX, \
/* F */	XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX,        XX \
};

// Opcodes in the form of "0xCB XX"
void (*CBopcodes[256])() = { \
//  	0          1          2          3          4          5          6          7          8          9          A          B          C          D          E          F
/*0*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*1*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*2*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*3*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*4*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*5*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*6*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*7*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*8*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*9*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*A*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*B*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*C*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*D*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*E*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX, \
/*F*/ XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX,      XXXX \
};
