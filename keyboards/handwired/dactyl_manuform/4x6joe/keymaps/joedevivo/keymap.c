#include QMK_KEYBOARD_H
#include "4x6joe.h"
#include "joedevivo.h"
extern keymap_config_t keymap_config;
extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_4x6( \
    KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,  KC_T,                                      KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS, \
    CTL_ESC, KC_A, KC_S,    MOUSED,  ARROWF,KC_G,                                      KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,  KC_B,                                      KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                   KC_LEFT, KC_RIGHT,LOWER, KC_BSPC, KC_DEL, KC_LGUI, KC_MEH, KC_ENT, KC_SPC, RAISE, KC_DOWN, KC_UP, \
                                                     KC_MEH, KC_LALT, KC_RALT, KC_RCTL \
   ),
  [_LOWER] = LAYOUT_4x6( \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,              KC_F12,  _______, _______, KC_HOME, KC_END,  _______, \
                      KC_VOLD, KC_VOLU, _______, _______, _, _, _, _, _______, _______, KC_MNXT, KC_MPLY, \
                                                          _, _, _, _ \
  ),
  [_RAISE] = LAYOUT_4x6( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,              KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______, \
                      KC_VOLD, KC_VOLU, _______, _______, _, _, _, _, _______, _______, KC_MNXT, KC_MPLY, \
                                                          _, _, _, _ \
  ),
  [_MOUSE] = LAYOUT_4x6( \
    _______, _______, _______, _______, _______, _______,                   _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN2, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_PGDN, KC_PGUP, _______, \
                      KC_VOLD, KC_VOLU, _______, _______, _, _, _, _, _______, _______, KC_MNXT, KC_MPLY, \
                                                          _, _, _, _ \
  ),
  [_ARROW] = LAYOUT_4x6( \
    _______, _______, _______, _______, _______, _______,                   _______, KC_PGUP, KC_UP,   KC_HOME, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, KC_PGDN, _______, KC_END,  _______, _______, \
                      KC_VOLD, KC_VOLU, _______, _______, _, _, _, _, _______, _______, KC_MNXT, KC_MPLY, \
                                                          _, _, _, _ \
  ),
  [_ADJUST] = LAYOUT_4x6( \
    _______, RESET,   RGBRST,  _______, _______, _______,             _______, _______, _______, _______, _______, KC_DEL, \
    _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,             AG_SWAP, QWERTY,  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
    _______, _______, _______, _______, _______, _______,             _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, \
                      KC_VOLD, KC_VOLU, _______, _______, _, _, _, _, _______, _______, KC_MNXT, KC_MPLY, \
                                                          _, _, _, _ \
  )
};

void matrix_init_keymap(void) { // Runs boot tasks for keyboard
};

void matrix_scan_keymap(void) {  // runs frequently to update info
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
