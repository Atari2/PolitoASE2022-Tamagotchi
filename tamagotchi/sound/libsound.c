#include "libsound.h"
#include "../timer/timer.h"
#include "LPC17xx.h"

extern uint32_t volume;
static uint8_t current_tick = 0;
const float sound_timer = 50 ms;		// start up checking for sounds every 50 ms

static const uint16_t SinTable[45] =                                       
{
	512, 583, 653, 719, 783, 840, 891, 935, 971, 
	998, 1015, 1023, 1020, 1008, 985, 954, 914, 866, 
	811, 751, 686, 618, 547, 475, 404, 337, 271, 
	211, 156, 108, 68, 37, 14, 2, 0, 7, 
	24, 51, 87, 131, 182, 241, 303, 370, 440
};

static uint32_t note_to_k(uint32_t hz) {
	return 25000000 / (hz * ARRAY_SIZE(SinTable));
}

// returns milliseconds
static float note_len_from_sound(uint8_t bpm, NoteLen note_len) {
	const float quarter_note_duration = 1000.0f / ((float)bpm / 60.0f);
	switch (note_len) {
		case L_1:
			return quarter_note_duration * 4;
		case L_2:
			return quarter_note_duration * 2;
		case L_4:
			return quarter_note_duration;
		case L_8:
			return quarter_note_duration / 2;
		case L_16:
			return quarter_note_duration / 4;
		case L_32:
			return quarter_note_duration / 8;
		case L_64:
			return quarter_note_duration / 16;
		default:
			return quarter_note_duration;
	}
}

static void set_dacr_value(uint16_t v) {
	uint32_t v_volume = ((uint32_t)v * volume) / 100u;								// adjust according to current volume
	uint32_t sv = v_volume & 0x3ff;					// select 10 lowest bits;				
	LPC_DAC->DACR = (sv << 6);  		  // shift by 6 because DACR uses bits 6..15 for the value, rest is reserved
}

void init_sound_system(void) {
	init_timer(Timer2, sound_timer, SCALE(1), 2);
	enable_timer(Timer2);
}

void next_sound_tick(void) {
	set_dacr_value(SinTable[current_tick++]);
	if (current_tick == ARRAY_SIZE(SinTable)) {
		current_tick = 0;
	}
}
void play_note(uint8_t bpm, const Note* note) {
	reset_timer(Timer2);
	init_timer(Timer2, note_len_from_sound(bpm, note->length), SCALE(1), 2);
	if (note->freq != N_None) {
		reset_timer(Timer3);
		init_timer_k(Timer3, note_to_k(note->freq), SCALE(1), 1);
		enable_timer(Timer3);
	}
	enable_timer(Timer2);
}
_Bool play_sound(const Sound* s) {
	static int cur_note = 0;
	current_tick = 0;
	if (s->length > 0) {
		if (cur_note > 0) {
			disable_timer(Timer3);
			reset_timer(Timer3);
		}
		if (cur_note == s->length) {
			// at end of sound			
			cur_note = 0;
			reset_timer(Timer2);
			init_timer(Timer2, sound_timer, SCALE(1), 2);
			enable_timer(Timer2);
			return 1;
		} else {
			play_note(s->bpm, &s->notes[cur_note]);
			cur_note++;
			return 0;
		}
	} else {
		return 1;
	}
}
