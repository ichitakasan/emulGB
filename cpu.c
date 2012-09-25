#include "cpu.h"

// Stores the GameBoy BIOS memory
Uint8 GB_BIOS[BIOS_SIZE] = \
	{0x31, 0xFE, 0xFF, 0xAF, 0x21, 0xFF, 0x9F, 0x32, 0xCB, 0x7C, 0x20, 0xFB, 0x21, 0x26, 0xFF, 0x0E,\
	0x11, 0x3E, 0x80, 0x32, 0xE2, 0x0C, 0x3E, 0xF3, 0xE2, 0x32, 0x3E, 0x77, 0x77, 0x3E, 0xFC, 0xE0,\
	0x47, 0x11, 0x04, 0x01, 0x21, 0x10, 0x80, 0x1A, 0xCD, 0x95, 0x00, 0xCD, 0x96, 0x00, 0x13, 0x7B,\
	0xFE, 0x34, 0x20, 0xF3, 0x11, 0xD8, 0x00, 0x06, 0x08, 0x1A, 0x13, 0x22, 0x23, 0x05, 0x20, 0xF9,\
	0x3E, 0x19, 0xEA, 0x10, 0x99, 0x21, 0x2F, 0x99, 0x0E, 0x0C, 0x3D, 0x28, 0x08, 0x32, 0x0D, 0x20,\
	0xF9, 0x2E, 0x0F, 0x18, 0xF3, 0x67, 0x3E, 0x64, 0x57, 0xE0, 0x42, 0x3E, 0x91, 0xE0, 0x40, 0x04,\
	0x1E, 0x02, 0x0E, 0x0C, 0xF0, 0x44, 0xFE, 0x90, 0x20, 0xFA, 0x0D, 0x20, 0xF7, 0x1D, 0x20, 0xF2,\
	0x0E, 0x13, 0x24, 0x7C, 0x1E, 0x83, 0xFE, 0x62, 0x28, 0x06, 0x1E, 0xC1, 0xFE, 0x64, 0x20, 0x06,\
	0x7B, 0xE2, 0x0C, 0x3E, 0x87, 0xF2, 0xF0, 0x42, 0x90, 0xE0, 0x42, 0x15, 0x20, 0xD2, 0x05, 0x20,\
	0x4F, 0x16, 0x20, 0x18, 0xCB, 0x4F, 0x06, 0x04, 0xC5, 0xCB, 0x11, 0x17, 0xC1, 0xCB, 0x11, 0x17,\
	0x05, 0x20, 0xF5, 0x22, 0x23, 0x22, 0x23, 0xC9, 0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B,\
	0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,\
	0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99, 0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC,\
	0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E, 0x3c, 0x42, 0xB9, 0xA5, 0xB9, 0xA5, 0x42, 0x4C,\
	0x21, 0x04, 0x01, 0x11, 0xA8, 0x00, 0x1A, 0x13, 0xBE, 0x20, 0xFE, 0x23, 0x7D, 0xFE, 0x34, 0x20,\
	0xF5, 0x06, 0x19, 0x78, 0x86, 0x23, 0x05, 0x20, 0xFB, 0x86, 0x20, 0xFE, 0x3E, 0x01, 0xE0, 0x50};

/************************************************************************************
 *                               INIT FUNCTIONS
 ************************************************************************************/
/** Initialises CPU ROM memory and reset RAM. */
void initialiseCPU() {

	// Memory initalisation ...
	int i;
	for (i = 0; i < BIOS_SIZE; i++)
		cpu.bios[i] = GB_BIOS[i];
	for (i = 0; i < ROM_SIZE; i++)
		cpu.rom[i] = 0;
	for (i = 0; i < OAM_SIZE; i++)
		cpu.oam[i] = 0;

	for (i = 0; i < MEMORY_SIZE; i++)
		cpu.memory[i] = 0;
	reset();
}

/** Soft reset program by reinitialising all registers and RAM memory. */
void reset() {

	cpu.A = 0; cpu.B = 0; cpu.C = 0; cpu.D = 0; cpu.E = 0;
	cpu.H = 0; cpu.L = 0; cpu.F = 0;

	cpu.PC = 0; // Execution starts at address 0
	cpu.SP = 0;

	cpu.M = 0; cpu.T = 0;
	cpu.bInBIOS = 1;
	cpu.bHalt = 0;
	cpu.bStop = 0;
	cpu.bInterrupt = 0;

	int i;
	for (i = 0; i < VRAM_SIZE; i++)
		cpu.vram[i] = 0;
	for (i = 0; i < ERAM_SIZE; i++)
		cpu.eram[i] = 0;
	for (i = 0; i < WRAM_SIZE; i++)
		cpu.wram[i] = 0;
	for (i = 0; i < ZRAM_SIZE; i++)
		cpu.zram[i] = 0;
}

/** Loads ROM memory by initialising it with a ROM file.
 * @param filename ROM file name.
 * @return Error code: 1 if OK, 0 if error occurred. */
Uint8 loadROM(char *filename) {

	FILE *f = NULL;
	f = fopen(filename,"rb"); // Binary file

	if (f != NULL) {
		fread(&cpu.memory[0], sizeof(Uint8) * ROM_SIZE, 1, f);
		fclose(f);
		return 1;

	} else {
		fprintf(stderr, "Problem opening the ROM file!");
		return 0;
	}
}

/************************************************************************************
 *                              UPDATE FUNCTION
 ************************************************************************************/
/** CPU update function. */
void updateCPU() {

	// Execute next instruction ...
//	(opcodes[readByte(cpu.PC++)])(&cpu.B, &cpu.C);
//	(opcodes[readByte(++cpu.PC)])(); // No parameter: the opcode determines the parameter to use

	cpu.M += cpu.m;
	cpu.T += cpu.t;

	clockStep();
}

/************************************************************************************
 *                               I/O FUNCTIONS
 ************************************************************************************/
/** Reads a byte (8-bit) from memory.
 * @param addr Reading address value.
 * @return The 8-bit unsigned int read from memory. */
Uint8 readByte(Uint16 addr) {

	switch (addr & 0xF000) {

	// BIOS (256Byte)/ROM0
	case 0x0000:
		if (cpu.bInBIOS) {
			if (addr < 0x0100)
				return cpu.bios[addr];
			else if (cpu.PC == 0x0100)
				cpu.bInBIOS = 0;
		}
		return cpu.rom[addr];

	// ROM0
	case 0x1000:
	case 0x2000:
	case 0x3000:
		return cpu.rom[addr];

	// ROM1 (unbanked) (16kB)
	case 0x4000:
	case 0x5000:
	case 0x6000:
	case 0x7000:
		return cpu.rom[addr];

	// Graphics: VRAM (8kB)
	case 0x8000:
	case 0x9000:
		return cpu.vram[addr & 0x1FFF];

	// External RAM (8kB)
	case 0xA000:
	case 0xB000:
		return cpu.eram[addr & 0x1FFF];

	// Working RAM (8kB)
	case 0xC000:
	case 0xD000:
		return cpu.wram[addr & 0x1FFF];

	// Working RAM Shadow
	case 0xE000:
		return cpu.wram[addr & 0x1FFF];

	// Working RAM Shadow, I/O, Zero Page RAM
	case 0xF000:
		// Working RAM Shadow
		if ((addr & 0x0F00) < 0x0E00)
			return cpu.wram[addr & 0x1FFF];

		switch (addr & 0x0F00) {

		// Graphics: object attribute memory
		// OAM is 160 bytes, remaining bytes read as 0
		case 0x0E00:
			if (addr < 0xFEA0)
				return cpu.oam[addr & 0x00FF];
			else
				return 0;

		// Zero-page memory
		case 0x0F00:
			if (addr >= 0xFF80)
				return cpu.zram[addr & 0x007F];
			else
				// I/O control handling
				// Currently unhandled
				return 0;
		}
	}

	return 0;
}

/** Reads a word (16-bit) from memory.
 * @param addr Reading address value.
 * @return The 16-bit unsigned int read from memory. */
Uint16 readWord(Uint16 addr) {
	return readByte(addr) + (readByte(addr+1) << 8);
}

/** Writes a byte (8-bit) into memory.
 * @param addr Writing address value.
 * @param val 8-bit unsigned int written value. */
void writeByte(Uint16 addr, Uint8 val) {

	switch (addr & 0xF000) {

	// ROM Bank 0
	case 0x0000: case 0x1000: case 0x2000: case 0x3000:
		break;

	// ROM Bank 1
	case 0x4000: case 0x5000: case 0x6000: case 0x7000:
		break;

	// VRAM
	case 0x8000: case 0x9000:
		cpu.vram[addr & 0x1FFF] = val;
//		cpu.updateTile(addr & 0x1FFF, val); ==================================================================<<<<<<
		break;

	// External RAM
	case 0xA000: case 0xB000:
		cpu.eram[addr & 0x1FFF] = val;
		break;

	// Work RAM and echo
	case 0xC000: case 0xD000: case 0xE000:
		cpu.wram[addr & 0x1FFF] = val;
		break;

	// Everything else
	case 0xF000:
		if ((addr & 0x0F00) < 0x0E00)
			cpu.wram[addr & 0x1FFF] = val;
		else {
			switch (addr & 0x0F00) {

			// OAM
			case 0x0E00:
				if ((addr & 0x00FF) < 0x00A0) {
					cpu.oam[addr & 0x00FF] = val;
//					cpu.updateOAM(addr, val); ==================================================================<<<<<<<
				}
				break;

			// Zero-page RAM, I/O
			case 0x0F00:
				if (addr >= 0xFF80)
					cpu.zram[addr & 0x007F] = val;
				break;
			}
		}
		break;
	}
}

/** Writes a word (16-bit) into memory.
 * @param addr Writing address value.
 * @param val 16-bit unsigned int written value. */
void writeWord(Uint16 addr, Uint16 val) {
	writeByte(addr, val & 0x00FF);
	writeByte(addr+1, val >> 8);
}

/************************************************************************************
 *                                INFORMATION
 ************************************************************************************/
/** Prints game information read from ROM header. */
void printGameInfo() {

	Uint16 addr;
	Uint8 val;

//	cpu.B = 21;
//	cpu.C = 43;
//	(opcodes[3])(&cpu.B, &cpu.C);

	// Game title ...
	printf(" # GAME: ");
	for (addr = 0x134; addr < 0x142; addr++)
		printf("%c", cpu.memory[addr]);
	printf("\n");

	// GB type ...
	val = cpu.memory[0x143];
	if (val == 0x80)
		printf(" # Color GB (0x%x)\n", val);
	else
		printf(" # Not Color GB (0x%x)\n", val);

	// Cartridge type ...
	val = cpu.memory[0x147];
	printf(" # TYPE: ");
	switch (val) {
	case 0x0: printf("ROM ONLY"); break;
	case 0x1: printf("ROM+MBC1"); break;
	case 0x2: printf("ROM+MBC1+RAM"); break;
	case 0x3: printf("ROM+MBC1+RAM+BATTERY"); break;
	case 0x5: printf("ROM+MBC2"); break;
	case 0x6: printf("ROM+MBC2+BATTERY"); break;
	case 0x8: printf("ROM+RAM"); break;
	case 0x9: printf("ROM+RAM+BATTERY"); break;
	case 0xB: printf("ROM+MMM01"); break;
	case 0xC: printf("ROM+MMM01+SRAM"); break;
	case 0xD: printf("ROM+MMM01+SRAM+BATTERY"); break;
	case 0xF: printf("ROM+MBC3+TIMER+BATTERY"); break;
	case 0x10: printf("ROM+MBC3+TIMER+RAM+BATTERY"); break;
	case 0x11: printf("ROM+MBC3"); break;
	case 0x12: printf("ROM+MBC3+RAM"); break;
	case 0x13: printf("ROM+MBC3+RAM+BATTERY"); break;
	case 0x19: printf("ROM+MBC5"); break;
	case 0x1A: printf("ROM+MBC5+RAM"); break;
	case 0x1B: printf("ROM+MBC5+RAM+BATTERY"); break;
	case 0x1C: printf("ROM+MBC5+RUMBLE"); break;
	case 0x1D: printf("ROM+MBC5+RUMBLE+SRAM"); break;
	case 0x1E: printf("ROM+MBC5+RUMBLE+SRAM+BATTERY"); break;
	case 0xFC: printf("Pocket Camera"); break;
	case 0xFD: printf("Bandai TAMA5"); break;
	case 0xFE: printf("Hudson HuC3"); break;
	case 0xFF: printf("Hudson HuC1+RAM+BATTERY"); break;
	default: printf("UNKNOWN!");
	}
	printf("\n");

	// ROM size ...
	val = cpu.memory[0x148];
	printf(" # ROM SIZE: ");
	switch (val) {
	case 0x0: printf("32KByte = no ROM banking"); break;
	case 0x1: printf("64KByte = 4 banks"); break;
	case 0x2: printf("128KByte = 8 banks"); break;
	case 0x3: printf("256KByte = 16 banks"); break;
	case 0x4: printf("512KByte = 32 banks"); break;
	case 0x5: printf("1MByte = 64 banks (only 63 banks used by MBC1)"); break;
	case 0x6: printf("2MByte = 128 banks (only 125 banks used by MBC1)"); break;
	case 0x7: printf("4MByte = 256 banks"); break;
	case 0x52: printf("1.1MByte = 72 banks"); break;
	case 0x53: printf("1.2MByte = 80 banks"); break;
	case 0x54: printf("1.5MByte = 96 banks"); break;
	default: printf("UNKNOWN!");
	}
	printf("\n");

	// RAM size ...
	val = cpu.memory[0x149];
	printf(" # RAM SIZE: ");
	switch (val) {
	case 0x0: printf("None"); break;
	case 0x1: printf("2KByte = 1 bank"); break;
	case 0x2: printf("8KByte = 1 bank"); break;
	case 0x3: printf("32KByte = 4 banks (of 8KBytes each)"); break;
	case 0x4: printf("128KByte = 16 banks"); break;
	default: printf("UNKNOWN!");
	}
	printf("\n");

	// Destination code ...
	val = cpu.memory[0x014A];
	printf(" # Destination code: ");
	switch (val) {
    case 0x0: printf("Japanese"); break;
	case 0x1: printf("Non-Japanese"); break;
	default: printf("UNKNOWN!");
	}
	printf("\n");

	// Mask ROM Version number
	printf(" # Mask ROM Version number: 0x%x\n", cpu.memory[0x14C]);

	// Header Checksum
	printf(" # Header Checksum: 0x%x\n", cpu.memory[0x14D]);
	val = 0; // Calculated Header Checksum
	for (addr = 0x134; addr <= 0x14C; addr++)
		val = val - cpu.memory[addr] - 1;
	printf(" # Calculated Header Checksum: 0x%x", val);
	if (val == cpu.memory[0x14D])
		printf(" (OK!)\n");
	else
		printf(" (Error!)\n");
}

