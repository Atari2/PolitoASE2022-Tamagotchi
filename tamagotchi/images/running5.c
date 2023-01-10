#include <stdint.h>
const uint16_t running5Matrix[24][24] = {
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFDF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x2861, 0x3041, 0x3861, 0x3842, 0x3042, 0xFFBF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x2082, 0x938E, 0xF618, 0xA34D, 0xAB2D, 0xAB2E, 0x4042, 0x3042, 0xFFBF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x20A2, 0xFF5C, 0xF659, 0xCCB2, 0x8209, 0x89E9, 0xB30E, 0xAB2E, 0x3842, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x0000, 0x0800, 0x1000, 0x1800, 0x2800, 0x3000, 0x8A09, 0x89E9, 0xB30E, 0x820A, 0x3062, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x0000, 0x0000, 0x0800, 0x1000, 0x1800, 0x1800, 0x2000, 0x3000, 0x3800, 0x8229, 0x7A29, 0x7249, 0x2862, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFDF, 0xFFFE, 0xA4B1, 0x1800, 0xAC91, 0x2000, 0xB471, 0x2800, 0x3000, 0x3000, 0xFE38, 0x3061, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x6AC9, 0x72C9, 0xEE99, 0x1800, 0xEE99, 0x2000, 0xF679, 0xB471, 0x2000, 0xFE79, 0x8289, 0xF678, 0x2081, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x62CA, 0xEE99, 0xF698, 0xF6B9, 0xF699, 0xF699, 0xF699, 0xF699, 0x2800, 0x2800, 0xFE79, 0x7A89, 0xB470, 0x2081, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x6AEB, 0xAC91, 0xB471, 0xB471, 0xB471, 0xAC71, 0x2000, 0xF679, 0xFE78, 0x3000, 0xFE58, 0xB470, 0x1800, 0x2082, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x1800, 0x2000, 0x1800, 0x1800, 0x2000, 0x2000, 0x2800, 0xFE78, 0xBC4F, 0xBC50, 0x2000, 0x1800, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x0800, 0x0800, 0x1000, 0x1800, 0xB470, 0xBC4F, 0xC44F, 0x8A67, 0x8288, 0x7AA8, 0x72C9, 0x6AE9, 0x6AE9, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x39A6, 0x6ACB, 0x72CA, 0x7A89, 0x8288, 0xA36C, 0x8288, 0xFF3A, 0xFF7B, 0xFF7B, 0x6AEA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x29C7, 0xB618, 0xBDF7, 0x736D, 0x7B4D, 0x938E, 0x9B6D, 0x7A89, 0xFF5B, 0xFF9C, 0x62EA, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x0000, 0x0000, 0x31C7, 0xE7DF, 0xAE19, 0xE7DF, 0xEFDF, 0x6B6F, 0x736F, 0x6A6A, 0x6A69, 0x6AC9, 0x1000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x0000, 0x0000, 0xD6BA, 0x0020, 0xEFDF, 0xAE19, 0xDFFF, 0xDFDF, 0x5BB1, 0x6390, 0x6B8F, 0x736D, 0x6AE9, 0x6AE9, 0x0800, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x0000, 0x0000, 0x62EB, 0x0020, 0x29C7, 0xAE19, 0x5BB0, 0x5BD1, 0x53B2, 0x5BB1, 0x63B0, 0x6B8E, 0x62EA, 0x6AE9, 0x0800, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x0000, 0x0800, 0x62EB, 0x0021, 0x29C8, 0x5BB1, 0x5BB2, 0x53B2, 0x5BB2, 0x29A8, 0x31A7, 0x3985, 0x62EA, 0x0800, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x0000, 0x0800, 0x62EB, 0x0000, 0xFFFF, 0x21A9, 0x21CA, 0x21CA, 0x21C9, 0xF7FF, 0x0000, 0xDEB9, 0x62EA, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
};
