#include "iris.h"
#include "joedevivo.h"
#include "action_layer.h"
#include "action_tapping.h"
#include "eeconfig.h"
#include "version.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y, KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTL_ESC, KC_A,   KC_S,    MOUSED,  KC_F,    KC_G,                    KC_H, KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, ALT_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                    KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LEFT, KC_RIGHT,KC_LALT,KC_LGUI, KC_NO,   KC_NO,  KC_DEL, KC_ENT, KC_NO, KC_NO,  KC_MEH,  SPCMAC,  KC_DOWN, KC_UP,   \
                                     KC_LGUI, LOWER, KC_BSPC, KC_SPC, RAISE, KC_MEH \
  ),

  [_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, \
                                      _______, _______, _______, _______, _______, _______ \
  ),

  [_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, \
                                      _______, _______, _______, _______, _______, _______ \
  ),
  [_MOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_RGHT, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, \
                                      _______, _______, _______, _______, _______, _______ \
  ),

  [_ADJUST] =  LAYOUT( \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______,                   _______, _______, _______, _______, _______, _______, \
  VRSN,    RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,                   _______, _______,  _______, _______, _______, _______, \
  BL_STEP, _______, VRSN,    _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                      _______, _______, _______, _______, _______, _______ \
  )
  };

void matrix_init_keymap(void) { // Runs boot tasks for keyboard
};

void matrix_scan_keymap(void) {  // runs frequently to update info
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

uint32_t layer_state_set_keymap(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

