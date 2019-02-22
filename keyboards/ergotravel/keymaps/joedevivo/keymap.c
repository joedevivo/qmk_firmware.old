#include QMK_KEYBOARD_H
#include "joedevivo.h"
extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_PGUP, SPCMAC, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_BSLS,
    CTL_ESC, KC_A,    KC_S,    MOUSED,  ARROWF,  KC_G, KC_TAB,  KC_MEH, KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_DEL,  KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LEFT, KC_RGHT, KC_LALT, KC_LGUI,     LOWER,     KC_BSPC, KC_SPC,    RAISE,   KC_MEH,  SPCMAC,  KC_DOWN, KC_UP
),

[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _, _, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _, _, KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _, _, KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______,     _______,      _, KC_ENT, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _, _,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _, _,  KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,_, _,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______,     _______, KC_DEL,_,    _______,       KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _,_, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______, _,_, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _,_, _______, _______, _______, _______, _______, _______,
    KC_WH_L, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U
),

[_ARROW] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _,_, _______, KC_PGUP, KC_UP,   KC_HOME, _______, _______,
    _______, _______, _______, _______, _______, _______, _,_, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _,_, _______, KC_PGDN, _______, KC_END,  _______, _______,
    KC_WH_L, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U
),

[_ADJUST] = LAYOUT(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, _,_,  RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, _,_,  AG_SWAP, QWERTY,  _______,  _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   _,_,  MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};
