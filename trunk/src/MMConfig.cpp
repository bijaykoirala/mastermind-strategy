#include "MMConfig.h"

// 1 peg:  0a0b 1a0b
// 2 pegs: 0a1b 0a2b 2a0b
// 3 pegs: 0a3b 1a1b 1a2b 3a0b
// 4 pegs: 0a4b 1a3b 2a1b 2a2b 4a0b
// 5 pegs: 0a5b 1a4b 2a3b 3a1b 3a2b 5a0b
// 6 pegs: 0a6b 1a5b 2a4b 3a3b 4a1b 4a2b 6a0b

const unsigned char feedback_count[MM_MAX_PEGS+1] = {
	0, 2, 5, 9, 14, 20, 27
};

// Mapping from ordinal feedback to nAnB
const unsigned char feedback_map[256] = {
	0x00, 0x10, 0x01, 0x02, 0x20, 0x03, 0x11, 0x12,
	0x30, 0x04, 0x13, 0x21, 0x22, 0x40, 0x05, 0x14,
	0x23, 0x31, 0x32, 0x50, 0x06, 0x15, 0x24, 0x33,
	0x41, 0x42, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
};

// Reorder:
// 1 peg:  0a0b 1a0b
// 2 pegs: 0a1b 0a2b 2a0b
// 3 pegs: 0a3b 1a1b 1a2b 3a0b
// 4 pegs: 0a4b 1a3b 2a1b 2a2b 4a0b
// 5 pegs: 0a5b 1a4b 2a3b 3a1b 3a2b 5a0b
// 6 pegs: 0a6b 1a5b 2a4b 3a3b 4a1b 4a2b 6a0b
//
// 0a0b
// 1a0b 0a1b
// 0a2b 2a0b
//

// Mapping from nAnB to ordinal feedback
const unsigned char feedback_revmap[256] = {
	   0,   2,   3, 5, 9,14,20,0xff,                 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	   1,   6,   7,10,15,21,0xff,0xff,               0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	   4,  11,  12,16,22,0xff,0xff,0xff,             0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	   8,  17,  18,23,0xff,0xff,0xff,0xff,           0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	  13,  24,  25,0xff,0xff,0xff,0xff,0xff,         0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	  19,0xff,0xff,0xff,0xff,0xff,0xff,0xff,     0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	  26,0xff,0xff,0xff,0xff,0xff,0xff,0xff,     0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,   0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
};