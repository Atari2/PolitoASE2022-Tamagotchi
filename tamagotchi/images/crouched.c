#include <stdint.h>
const uint16_t crouchedMatrix[24][16] = {
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBDE, 0xFBDF, 0xFBDF, 0xFBDF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0xFBDE, 0x4000, 0x4800, 0x5000, 0x5001, 0x4801, 0xFBBE, 0xFBDF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0x3021, 0xA1AC, 0xFAF6, 0xC16C, 0xC16D, 0xC16E, 0x5001, 0x4002, 0xFBDF, 0xFBFF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFF, 0x2841, 0xFBDC, 0xF337, 0xCA51, 0x90E8, 0xA0C9, 0xD14F, 0xC94E, 0x5002, 0xFBDF, 0xFBFF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0x0800, 0x0800, 0x0800, 0x1000, 0x1800, 0x2800, 0x98CA, 0xA0AA, 0xD14F, 0x98CA, 0x4002, 0xFBDF, 0xFBFF, 0xFBFF },
	{0xFBFF, 0x0000, 0x0000, 0x0000, 0x0800, 0x1000, 0x1800, 0x1800, 0x2000, 0x2800, 0x88EA, 0x88EA, 0x88E9, 0x3821, 0xFBFF, 0xFBFF },
	{0xFBFF, 0xFBFF, 0xFBFE, 0xFBFE, 0xAA51, 0x1800, 0xB231, 0x1800, 0xB231, 0x1800, 0x2000, 0x2800, 0xFB18, 0x4000, 0xFBDE, 0xFBFF },
	{0xFBFE, 0xFBFD, 0x7168, 0x7967, 0xF358, 0x1000, 0xF359, 0x1800, 0xFB38, 0xBA30, 0x1800, 0xFB39, 0x8927, 0xFB36, 0x3020, 0xFBDE },
	{0xFBFD, 0x7169, 0xFB56, 0xFB36, 0xFB37, 0xF358, 0xF358, 0xF358, 0xFB38, 0x2000, 0x1800, 0xF358, 0x8147, 0xBA2F, 0x3021, 0xFBDF },
	{0xFBFD, 0x7169, 0xBA2F, 0xC20F, 0xC20F, 0xBA30, 0xB231, 0x1800, 0xFB38, 0xFB38, 0x2800, 0xBA30, 0xB231, 0x1000, 0x2044, 0xFBFF },
	{0xFBFD, 0xFBFC, 0x2000, 0x2800, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0xC211, 0xBA32, 0x1000, 0x0000, 0x69B0, 0x69B1, 0x28CA },
	{0xFBFB, 0xFBFB, 0x7966, 0x8946, 0x9126, 0xA107, 0xD14D, 0xD14E, 0x98C9, 0x4003, 0x71B1, 0x59D2, 0x51F2, 0x51F2, 0x51D4, 0x18ED },
	{0x7167, 0x7167, 0x7167, 0xFBBA, 0x4800, 0xC16B, 0xD94D, 0xB0A9, 0x98C9, 0x3803, 0x28CA, 0x10EC, 0x41F3, 0x41F3, 0x49D4, 0x10ED },
	{0x7167, 0xFBDB, 0xFBDC, 0xFBDD, 0x4800, 0x98E8, 0x98E9, 0x5001, 0x4000, 0x81AC, 0x69CE, 0x51F1, 0x41F2, 0x41F3, 0x51D4, 0x18ED },
	{0x7168, 0xFBDB, 0xFBDD, 0xFBDD, 0x3801, 0x4800, 0x4001, 0x2000, 0x7948, 0x6968, 0x598A, 0x0001, 0x51F1, 0x49F3, 0x18EB, 0xEBFF },
	{0xFBFD, 0x6969, 0x6968, 0x7168, 0x1000, 0xEB37, 0x1000, 0xEB57, 0x7167, 0x7168, 0x6169, 0x0000, 0x20CA, 0x20CA, 0xF3FF, 0xFBFF },
	{0xFBFD, 0xFBFD, 0xFBFC, 0xFBFB, 0x0800, 0x0800, 0x0800, 0x0800, 0x1000, 0x1000, 0x0800, 0x0000, 0xFBFF, 0xF3FF, 0xFBFF, 0xFBFF },
};
