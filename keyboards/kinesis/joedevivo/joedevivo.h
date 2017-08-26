#ifndef KINESIS_JOEDEVIVO_H
#define KINESIS_JOEDEVIVO_H

#include "quantum.h"

void ergodox_board_led_on(void);
void ergodox_right_led_1_on(void);
void ergodox_right_led_2_on(void);
void ergodox_right_led_3_on(void);

inline void ergodox_right_led_on(uint8_t led) {
    switch (led) {
    case 0:
        ergodox_right_led_1_on();
        break;
    case 1:
        ergodox_right_led_2_on();
        break;
    case 2:
        ergodox_right_led_3_on();
        break;
    }
}

void ergodox_board_led_off(void);
void ergodox_right_led_1_off(void);
void ergodox_right_led_2_off(void);
void ergodox_right_led_3_off(void);
inline void ergodox_right_led_off(uint8_t led) {
    switch (led) {
    case 0:
        ergodox_right_led_1_off();
        break;
    case 1:
        ergodox_right_led_2_off();
        break;
    case 2:
        ergodox_right_led_3_off();
        break;
    }
}

inline void ergodox_led_all_on(void)
{
    ergodox_board_led_on();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
}

inline void ergodox_led_all_off(void)
{
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

void ergodox_right_led_1_set(uint8_t n);
void ergodox_right_led_2_set(uint8_t n);
void ergodox_right_led_3_set(uint8_t n);

inline void ergodox_right_led_set(uint8_t led, uint8_t n){
    switch (led) {
    case 0:
        ergodox_right_led_1_set(n);
        break;
    case 1:
        ergodox_right_led_2_set(n);
        break;
    case 2:
        ergodox_right_led_3_set(n);
        break;
    }
}

inline void ergodox_led_all_set(uint8_t n) {
    ergodox_right_led_1_set(n);
    ergodox_right_led_2_set(n);
    ergodox_right_led_3_set(n);
}

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments as on the physical keyboard
// The second converts the arguments into the 2-D scanned array

#define KEYMAP(                           \
    kC0,kD0,kE0,kC1,kD1,kE1,kC2,kD2,kE2,  \
    k00,k10,k20,k30,k40,k50,              \
    k01,k11,k21,k31,k41,k51,              \
    k02,k12,k22,k32,k42,k52,              \
    k03,k13,k23,k33,k43,k53,              \
        k14,k24,k34,k54,                  \
                        k56,k55,          \
                            k35,          \
                    k36,k46,k25,          \
    kC3,kD3,kE3,kC4,kD4,kE4,kC5,kE5,kD5,  \
        k60,k70,k80,k90,kA0,kB0,          \
        k61,k71,k81,k91,kA1,kB1,          \
        k62,k72,k82,k92,kA2,kB2,          \
        k63,k73,k83,k93,kA3,kB3,          \
            k64,k84,k94,kA4,              \
    k96,k85,                              \
    k86,                                  \
    k66,k75,k65                           \
) {                                       \
        { k00,    k01,    k02,    k03,    kE0,    kE1,    kE2 }, \
        { k10,    k11,    k12,    k13,    k14,    KC_NO,  KC_NO }, \
        { k20,    k21,    k22,    k23,    k24,    k25,    KC_NO }, \
        { k30,    k31,    k32,    k33,    k34,    k35,    k36   }, \
        { k40,    k41,    k42,    k43,    KC_NO,  KC_NO,  k46   }, \
        { k50,    k51,    k52,    k53,    k54,    k55,    k56   }, \
        { k60,    k61,    k62,    k63,    k64,    k65,    k66   }, \
        { k70,    k71,    k72,    k73,    KC_NO,  k75,    KC_NO }, \
        { k80,    k81,    k82,    k83,    k84,    k85,    k86   }, \
        { k90,    k91,    k92,    k93,    k94,    KC_NO,  k96   }, \
        { kA0,    kA1,    kA2,    kA3,    kA4,    KC_NO,  KC_NO }, \
        { kB0,    kB1,    kB2,    kB3,    kE3,    kE4,    kE5 }, \
        { kC0,    kC1,    kC2,    kC3,    kC4,    kC5,    KC_NO }, \
        { kD0,    kD1,    kD2,    kD3,    kD4,    kD5,    KC_NO }, \
}

/*
This is the Stapelberg matrix as published at
https://github.com/stapelberg/kinesis-firmware/blob/master/kb_kinesis/config.kspec
Along with the pins for each row and column
                  14   7   8   6  20  21   5
                 PD1 PD2 PD3 PD4 PD5 PD6 PD7
                 kx0 kx1 kx2 kx3 kx4 kx5 kx6
19 PB2  k0x Row: EQL TAB CAP LSH F2  F5  F8
18 PB3  k1x Row: 1   Q   A   Z   BQ  --  --
32 PB18 k2x Row: 2   W   S   X   INS END --
25 PB19 k3x Row: 3   E   D   C   LFT HOM BAK
15 PC0  k4x Row: 4   R   F   V   --  --  DEL
27 PC9  k5x Row: 5   T   G   B   RT  LAL LCT
29 PC10 k6x Row: 6   Y   H   N   UP  SPC PGD
30 PC11 k7x Row: 7   U   J   M   --  RET --
2  PD0  k8x Row: 8   I   K   COM DWN RCT PGU
3  PA12 k9x Row: 9   O   L   PER LBR --  RAL
4  PA13 kAx Row: 0   P   SEM SLA RBR --  --
33 PA4  kBx Row: MIN BSL APO RSH F11 SLK KEY
26 PE1  kCx Row: ESC F3  F6  F9  F12 PAU --
31 PE0  kDx Row: F1  F4  F7  F10 PRT PRG --

*/



#endif
