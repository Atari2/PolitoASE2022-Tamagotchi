#include <stdint.h>
const uint16_t running6Matrix[24][24] = {
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFDF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x2861, 0x3041, 0x3861, 0x3842, 0x3042, 0xFFBF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x2082, 0x938E, 0xF618, 0xA34D, 0xAB2D, 0xAB2E, 0x4042, 0x3042, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x20A2, 0xFF5C, 0xF659, 0xCCB2, 0x8209, 0x89E9, 0xB30E, 0xAB2E, 0x3842, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x0000, 0x0800, 0x1000, 0x1800, 0x2800, 0x3000, 0x8A09, 0x89E9, 0xB30E, 0x820A, 0x3062, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x0000, 0x0000, 0x0800, 0x1000, 0x1800, 0x1800, 0x2000, 0x3000, 0x3800, 0x8209, 0x7A29, 0x7249, 0x2862, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFDF, 0xFFFE, 0xA4B2, 0x1800, 0xAC91, 0x2000, 0xB471, 0x2800, 0x3000, 0x3000, 0xFE38, 0x3061, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x6AC9, 0x72C9, 0xEE99, 0x1800, 0xEE99, 0x2000, 0xF679, 0xB471, 0x2000, 0xFE79, 0x8289, 0xF678, 0x2081, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x62CA, 0xEE99, 0xF698, 0xF699, 0xF699, 0xF699, 0xF699, 0xF699, 0x2800, 0x2800, 0xFE79, 0x7A89, 0xB470, 0x2081, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0x6AEB, 0xAC91, 0xB471, 0xB471, 0xB471, 0xAC71, 0x2000, 0xF679, 0xFE78, 0x3000, 0xFE58, 0xB471, 0x1800, 0x20A2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0x1800, 0x2000, 0x1800, 0x1800, 0x2000, 0x2000, 0x2800, 0xFE78, 0xBC4F, 0xBC4F, 0x2000, 0x1800, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x0800, 0x0800, 0x1000, 0x1800, 0xB470, 0xBC4F, 0xC44E, 0x8A67, 0x8287, 0x7AA8, 0x72C8, 0x6AE9, 0x6AE9, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x39A6, 0x6ACB, 0x72CA, 0x7AA9, 0x8288, 0xA34C, 0x8288, 0xFF3A, 0xFF7A, 0xFF7B, 0x6AE9, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x29C7, 0xB618, 0xBDF7, 0x736D, 0x7B4D, 0x938E, 0x9B6D, 0x8289, 0xFF3B, 0xFF9C, 0x62EA, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x29C7, 0xE7DF, 0xAE38, 0xE7DF, 0xEFDF, 0x6B6F, 0x736E, 0x6A6A, 0x6A6A, 0x6ACA, 0x62CA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x29C7, 0xDFDF, 0xA639, 0xDFFF, 0xE7DF, 0x5BB0, 0x6390, 0x6B6F, 0x736F, 0x3186, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0x29C7, 0xAE18, 0xA639, 0x5BCF, 0x5BCF, 0x5BB0, 0x5BB0, 0x6390, 0x6B8F, 0x31A7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x29C7, 0x63AF, 0x29C7, 0x63AE, 0x63AE, 0x63AE, 0x6B8F, 0x29A7, 0x31A7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0041, 0x5B0C, 0x0000, 0x5B0B, 0x5B0B, 0x5B0C, 0x5B0C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xD6BA, 0x0000, 0xDEBA, 0x62EB, 0x630B, 0x62EB, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0800, 0x0800, 0x0820, 0x0820, 0x0800, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
};
