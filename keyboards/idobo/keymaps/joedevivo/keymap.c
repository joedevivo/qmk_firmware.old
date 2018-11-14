/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "joedevivo.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT_ortho_5x15( \
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_ESC, KC_HOME,  KC_TILD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_LBRC, KC_END,  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_SPC, KC_HYPR,  KC_SPC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_TAB, KC_CAPS,  KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
    KC_LEFT, KC_RIGHT,KC_LALT, KC_LGUI, MO(_LOWER),KC_BSPC,  KC_DEL, KC_SPC,   KC_ENT,  KC_SPC,  MO(_RAISE), KC_MEH,  SPCMAC,  KC_UP, KC_DOWN
  ),
  [_LOWER] = LAYOUT_ortho_5x15( \
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC, KC_HOME,  KC_TILD, KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    KC_MINS,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ______, _______,  _______, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ______, _______,  _______, KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  ______, _______,  _______, KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, ______, _______,  _______, KC_ENT, _______,     KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
  ),
  [_RAISE] = LAYOUT_ortho_5x15( \
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC, KC_HOME,  KC_TILD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ______, _______,  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ______, _______,  _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  ______, _______,  _______, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, KC_DEL,  ______, _______,  _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

  ),
  [_MOUSE] = LAYOUT_ortho_5x15( \
    _______, _______, _______, _______, _______, _______, __, __, __, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, __, __, __, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______, __, __, __, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, __, __, __, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, __, __, __, _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R
  ),
  [_ADJUST] = LAYOUT_ortho_5x15( \
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    __, __, __, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, \
    BACKLIT, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, __, __, __, RGB_HUD, RGB_SAI, RGB_SAD , RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, __, __, __, AG_SWAP, QWERTY,  _______ , _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   __, __, __, MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, __, __, __, _______, _______, _______ , _______, _______, _______
  ),

};

uint32_t layer_state_set_keymap(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_keymap(void) {

}

void matrix_scan_keymap(void) {

}

void led_set_keymap(uint8_t usb_led) {

}
