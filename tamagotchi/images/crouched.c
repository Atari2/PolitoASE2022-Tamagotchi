#include <stdint.h>
const uint16_t crouchedMatrix[24][24] = {
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFBE, 0xFF9E, 0xFF9E, 0xFF9E, 0xFF9F, 0xFFBF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFDF, 0xFF9D, 0x3040, 0x3820, 0x4821, 0x4821, 0x3821, 0xFF3E, 0xFF9E, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFDF, 0x2881, 0x9B6D, 0xFDF7, 0xB32D, 0xB30D, 0xB30E, 0x4822, 0x3822, 0xFF5E, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFDF, 0x2082, 0xFF7C, 0xF658, 0xCCB2, 0x8A09, 0x91C9, 0xC2EF, 0xBAEE, 0x4802, 0xFF5E, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x0800, 0x0800, 0x1000, 0x1800, 0x2000, 0x3000, 0x89E9, 0x91CA, 0xBACE, 0x89EA, 0x3842, 0xFF9E, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x0000, 0x0000, 0x0800, 0x1000, 0x1000, 0x1800, 0x2000, 0x2800, 0x3800, 0x820A, 0x820A, 0x7A29, 0x3061, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFE, 0xFFDE, 0xFFDD, 0xA491, 0x1800, 0xAC91, 0x1800, 0xB471, 0x2000, 0x2800, 0x3000, 0xFE18, 0x3841, 0xFF9E, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFE, 0xFFDD, 0x72C9, 0x72C9, 0xF699, 0x1800, 0xF699, 0x1800, 0xF679, 0xB471, 0x2000, 0xFE79, 0x8288, 0xFE58, 0x2881, 0xFFBE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFD, 0x6AE9, 0xF697, 0xF697, 0xF698, 0xF699, 0xF699, 0xF699, 0xFE79, 0x2800, 0x2000, 0xF699, 0x7AA9, 0xB470, 0x2882, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFD, 0x6AE9, 0xB470, 0xBC50, 0xBC50, 0xBC50, 0xB471, 0x2000, 0xFE79, 0xFE58, 0x2800, 0xB471, 0xAC91, 0x1000, 0x1884, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFDC, 0xFFBC, 0x2000, 0x3000, 0x3800, 0x3800, 0x3800, 0x3800, 0x3800, 0xBC51, 0xB472, 0x1001, 0x0001, 0x6B6F, 0x6B91, 0x29A9, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFDB, 0xFFBB, 0x7AC7, 0x82A7, 0x9268, 0x9A28, 0xC2CD, 0xC2CE, 0x91C9, 0x3823, 0x7B30, 0x6B71, 0x5BB1, 0x5BB2, 0x5BB3, 0x21AA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x6AE8, 0x6AE7, 0x72C7, 0xFF3A, 0x4820, 0xBAEC, 0xC2CD, 0x99A9, 0x91E9, 0x3823, 0x3968, 0x21AA, 0x53D2, 0x4BD3, 0x53B3, 0x19AB, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x6AE8, 0xFF9B, 0xFFBC, 0xFF7C, 0x4020, 0x8A08, 0x89E9, 0x4801, 0x3820, 0x8B2C, 0x736E, 0x63B0, 0x53D2, 0x4BD2, 0x53B3, 0x21CA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x6AE8, 0xFFBB, 0xFFBC, 0xFF9C, 0x3841, 0x3821, 0x3821, 0x2800, 0x7AA9, 0x72C9, 0x62EB, 0x0042, 0x53B1, 0x53B2, 0x21CA, 0xEFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFDC, 0x62E9, 0x6AE9, 0x6AE9, 0x1800, 0xEE79, 0x1800, 0xEE79, 0x72C9, 0x6ACA, 0x62EB, 0x0000, 0x29C8, 0x21C8, 0xF7FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFD, 0xFFFC, 0xFFDC, 0xFFBC, 0x0800, 0x0800, 0x0800, 0x0800, 0x1000, 0x1000, 0x0800, 0x0000, 0xF7FF, 0xF7FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
};
