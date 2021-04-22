#ifndef MEMORY
#define MEMORY

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

/* Memory: 65536 bytes */
uint16_t memory[UINT16_MAX];

/* registers
	R0 - R7: general purpose
	PC: program counter
	COND: condition flags
*/

enum {
	R_R0 = 0,
	R_R1,
	R_R2,
	R_R3,
	R_R4,
	R_R5,
	R_R6,
	R_R7,
	R_PC,
	R_COND,
	R_COUNT
};

uint16_t registers[R_COUNT];

// memory mapped registers
enum {
	MR_KBSR = 0xFE00, // status
	MR_KBDR = 0xFE02 // data
};

// condition flags
enum {
	FL_POS = 1 << 0,
	FL_ZRO = 1 << 1,
	FL_NEG = 1 << 2
};

uint16_t check_key() {
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	return select(1, &readfds, NULL, NULL, &timeout) != 0;
}

void update_flags(uint16_t r) {
  if (registers[r] == 0) {
      registers[R_COND] = FL_ZRO;
  } else if (registers[r] >> 15) {
	/* a 1 in the left-most bit indicates negative */
      registers[R_COND] = FL_NEG;
  } else{
      registers[R_COND] = FL_POS;
  }
}

void mem_write(uint16_t address, uint16_t val) {
	memory[address] = val;
}

uint16_t mem_read(uint16_t address) {
	if (address == MR_KBSR) {
		if (check_key()) {
			memory[MR_KBSR] = (1 << 15);
			memory[MR_KBDR] = getchar();
		} else {
			memory[MR_KBSR] = 0;
		}
	}

	return memory[address];
}

#endif
