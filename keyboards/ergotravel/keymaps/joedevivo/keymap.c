﻿#include QMK_KEYBOARD_H

#include "joedevivo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------.  ,------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | PGUP |  | PGDN |   Y  |   U  |   I  |   O  |   P  | \    |
 * |------+------+------+------+------+-------------|  |-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |CtlEsc|  | Meh  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | Del  |  | Ent  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * |Adjust| Meh  | Alt  | Cmd  |    Lower    | Bksp |  | Space|    Raise    | Left | Up   |Down  |Right |
 * `------------------------------------------------'  `------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP, SPCMCS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTL_ESC, KC_A,    KC_S,    MOUSED,  KC_F,    KC_G,    KC_TAB,  KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, ALT_T(KC_Z),KC_X, KC_C,    KC_V,    KC_B,    KC_DEL,  KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  ADJUST,  KC_MEH,  KC_LALT, KC_LGUI, LOWER,   KC_BSPC,                   KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),
/* Lower
 * ,------------------------------------------------.  ,------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | HOME |  | END  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------|  |-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |CtlEsc|  | Meh  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | Del  |  | Ent  |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Bksp |  | Space|      |      | Next | Vol- | Vol+ | Play |
 * `------------------------------------------------'  `------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME, KC_END, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, ______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, ______, KC_F12,S(KC_NUHS),S(KC_NUBS),_____, _______, KC_ENT, \
  _______, _______, _______, _______, _______, _______,                  _______,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,------------------------------------------------.  ,------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | PGUP |  | PGDN |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------|  |-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |CtlEsc|  | Meh  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | Del  |  | Ent  |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Bksp |  | Space|      |      | Next | Vol- | Vol+ | Play |
 * `------------------------------------------------'  `------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, ______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, ______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, ______, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, KC_ENT, \
  _______, _______, _______, _______, _______, ______,                   _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_MOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, ______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, DEBUG,   \
  _______, _______, _______, _______, _______, _______, _______, ______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, ______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                  _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R  \
),

/* Adjust (Lower + Raise)
 * ,------------------------------------------------.  ,------------------------------------------------.
 * | Reset| RTOGG|      |      |      |      | PGUP |  | PGDN |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------|  |-------------+------+------+------+------+------|
 * | VRSN |      |      |Aud on|Audoff|AGnorm|CtlEsc|  | Meh  |AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Del  |  | Ent  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
 * |      |      |      |      |             | Bksp |  | Space|             |      |      |      |      |
 * `------------------------------------------------'  `------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, ______, _______, _______, _______, _______, _______, _______, \
  VRSN,    RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, ______, _______, _______, _______, _______, _______, _______, \
  BL_STEP, BL_TOGG, VRSN,    _______, _______, _______, _______, ______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______  \
)
};


void matrix_init_keymap(void) { // Runs boot tasks for keyboard
  print("matrix_init_keymap");
};

void matrix_scan_keymap(void) {  // runs frequently to update info
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {}
