#ifndef CPU_H
#define CPU_H

#include <SDL/SDL.h>

#include "screen.h"

#define BIOS_SIZE		256
#define ROM_SIZE		32768
#define VRAM_SIZE		8192
#define ERAM_SIZE		8192
#define WRAM_SIZE		8192
#define OAM_SIZE		160
#define ZRAM_SIZE		128

#define MEMORY_SIZE		65536

/************************************************************************************
 *                                  CPU STRUCT
 ************************************************************************************/
typedef struct {
	Uint8 A;	// Accumulator
	Uint8 F;	// Flag register (lower 8bit of AF register):
		//  - Bit num 7: Zero flag (Z). Becomes set (1) if the result of an operation has been zero (used for conditional jumps)
		//  - Bit num 6: Add/Sub (n) flag (BCD)
		//  - Bit num 5: Half Carry (h) flag (BCD)
		//  - Bit num 4: Carry flag (C or Cy). Becomes set (1) when the result of an addition became bigger than FFh (8bit) or FFFFh (16bit)
		//  - Bit num 3-0: Not used flags (always zero)
	Uint8 B, C, D, E, H, L;	// Other registers

	Uint16 PC;	// Program counter
	Uint16 SP;	// Stack pointer

	Uint8 m, t;	// Clock for last instruction
	Uint8 M, T;	// Z80 time clock

	Uint8 bios[BIOS_SIZE];		// BIOS memory
	Uint8 rom[ROM_SIZE];		// ROM Memory + ROM bank 1
	Uint8 vram[VRAM_SIZE];		// Graphics Video Memory
	Uint8 eram[ERAM_SIZE];		// External RAM Memory
	Uint8 wram[WRAM_SIZE];		// Working RAM Memory
	Uint8 oam[OAM_SIZE];		// Graphics Object Attribute Memory
	Uint8 zram[ZRAM_SIZE];		// Zero-page RAM Memory

	Uint8 memory[MEMORY_SIZE];	// Memory
		// Interrupt Enable Register _______FFFF
		// Internal RAM ____________________FF80
		// Empty but unusable for I/O ______FF4C
		// I/O ports _______________________FF00
		// Empty but unusable for I/O ______FEA0
		// Sprite Attrib Memory (OAM) ______FE00
		// Echo of 8kB Internal RAM ________E000
		// 8kB Internal RAM ________________C000
		// 8kB switchable RAM bank _________A000
		// 8kB Video RAM ___________________8000
		// 16kB switchable ROM bank ________4000
		// 16kB ROM bank #0 ________________0000

	// Flag indicating BIOS is mapped in
	// BIOS is unmapped with the first instruction above 0x00FF
	char bInBIOS;
	// Flag indicating CPU is down until an interrupt occurs
	char bHalt;
	// Flag indicating CPU and LCD are stopped until a button is pressed
	char bStop;
	// Flag indicating that interrupt is to be activated
	char bInterrupt;
} CPU;

/************************************************************************************
 *                                  VARIABLES
 ************************************************************************************/
CPU cpu;
extern void (*opcodes[256])();		// Stores all the Z80 8bit opcodes mapping (coming from opcodes.h)
extern void (*CBopcodes[256])();	// Stores all the Z80 16bit opcodes mapping starting by 0xCB (coming from opcodes.h)

/************************************************************************************
 *                                  FUNCTIONS
 ************************************************************************************/
// Init functions ...
void initialiseCPU();
void reset();

Uint8 loadROM(char *filename);

// Update function ...
void updateCPU();

// I/O functions ...
Uint8 readByte(Uint16 addr);
Uint16 readWord(Uint16 addr);
void writeByte(Uint16 addr, Uint8 val);
void writeWord(Uint16 addr, Uint16 val);

// Information ...
void printGameInfo();


#endif // CPU_H
