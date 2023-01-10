#include <stdint.h>
const uint16_t eatingpizzaMatrix[24][24] = {
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20A1, 0x2081, 0x2882, 0x2882, 0x2882, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x2082, 0x8BAE, 0xEE38, 0x9B6E, 0xA34E, 0xA34E, 0x3842, 0x3042, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x2082, 0xFF5C, 0xF659, 0xCCB2, 0x8229, 0x8209, 0xAB2E, 0xA34F, 0x3062, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x0800, 0x0800, 0x1000, 0x1800, 0x2800, 0x3000, 0x8229, 0x8209, 0xA32E, 0x7A2A, 0x3062, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x0000, 0x0800, 0x0800, 0x1000, 0x1800, 0x2000, 0x2800, 0x3000, 0x3800, 0x8229, 0x7A29, 0x724A, 0x2882, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xAC92, 0x1800, 0xAC71, 0x2000, 0xB451, 0x2800, 0x3000, 0x3000, 0xF659, 0x2861, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x6AEA, 0x6ACA, 0xEEB9, 0x1800, 0xF699, 0x2000, 0xF679, 0xB451, 0x2800, 0xFE79, 0x7AAA, 0xEE79, 0x20A2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x6AEA, 0xEEB9, 0xF698, 0xF699, 0xF699, 0xF699, 0xF679, 0xF679, 0x2800, 0x2800, 0xF679, 0x7A89, 0xAC91, 0x20A2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFD, 0x6AE9, 0xAC8F, 0xB48F, 0xB470, 0xB470, 0xB471, 0x2000, 0xF679, 0xF679, 0x2800, 0xF679, 0xB471, 0x1800, 0x20A2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFBA, 0xC591, 0xC572, 0x2840, 0x2800, 0x2800, 0x2800, 0x2800, 0x2800, 0xFE78, 0xBC50, 0xB470, 0x1800, 0x1000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xC590, 0xFF78, 0x49A2, 0xFF19, 0xFEF9, 0x5964, 0xFEDA, 0xFE58, 0xFE58, 0xFE58, 0x7A89, 0x72AA, 0x1800, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xC590, 0xFF78, 0xFF59, 0x72C7, 0x5963, 0xFEB9, 0xC430, 0xCC30, 0xC430, 0xBC50, 0x2800, 0xEE9A, 0x2082, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x72E6, 0x72E7, 0x72E7, 0xFF5A, 0x3860, 0x4040, 0x5021, 0x5041, 0x4841, 0x3000, 0x1800, 0x0800, 0x18A3, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x6AE7, 0xFF9A, 0xFFBB, 0xFF5B, 0x3840, 0xAB4D, 0xB32D, 0xAB0E, 0xA32E, 0x3042, 0x7B4E, 0x736F, 0x3187, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0x62E9, 0xFFBC, 0xFFBD, 0xFF5C, 0x3041, 0x7A29, 0x820A, 0x820A, 0x722A, 0x2863, 0x736F, 0x6B6F, 0x31A7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFE, 0x62EA, 0x62EB, 0x6ACB, 0x2882, 0x3062, 0x3043, 0x3043, 0x2063, 0x736F, 0x6B90, 0x638F, 0x29A8, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x3986, 0xC5B7, 0xCDB7, 0x7B4E, 0x7B4E, 0x736F, 0x6B6F, 0x6390, 0x638F, 0x29A7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x39A6, 0x736E, 0x3987, 0x736E, 0x736E, 0x6B8E, 0x6B8F, 0x29A7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x62EC, 0x0000, 0x62EC, 0x5AEB, 0x5B0C, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xD6BA, 0x0000, 0xDEBA, 0x62EB, 0x62EB, 0x62EB, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0020, 0x0800, 0x0800, 0x0800, 0x0820, 0x0800, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
};
