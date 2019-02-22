#pragma once

#include "dactyl_manuform.h"
#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define LAYOUT_4x6( \
  L11, L12, L13, L14, L15, L16,                     R12, R13, R14, R15, R16, R17, \
  L21, L22, L23, L24, L25, L26,                     R22, R23, R24, R25, R26, R27, \
  L31, L32, L33, L34, L35, L36,                     R32, R33, R34, R35, R36, R37, \
            L43, L44, L45, L46, L17, L27, R21, R11, R42, R43, R44, R45,           \
                                L37, L47, R41, R31                                \
	) \
	{ \
   { L11,   L12,   L13, L14, L15, L16, L17}, \
   { L21,   L22,   L23, L24, L25, L26, L27}, \
   { L31,   L32,   L33, L34, L35, L36, L37}, \
   { KC_NO, KC_NO, L43, L44, L45, L46, L47}, \
   { R11,   R12,   R13, R14, R15, R16, R17}, \
   { R21,   R22,   R23, R24, R25, R26, R27}, \
   { R31,   R32,   R33, R34, R35, R36, R37}, \
   { R41,   R42,   R43, R44, R45, KC_NO, KC_NO}  \
	}
