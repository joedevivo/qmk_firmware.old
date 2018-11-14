#include "atreus62.h"
#include "joedevivo.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = { /* qwerty */
    { KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
    { KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS },
    { CTL_ESC,  KC_A,    KC_S,    MOUSED,  KC_F,    KC_G,    XXXXXXX,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
    { KC_LSFT,  ALT_T(KC_Z),KC_X, KC_C,    KC_V,    KC_B,    KC_DEL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
    { KC_LEFT,  KC_RIGHT,KC_LALT, KC_LGUI, LOWER, KC_BSPC,   KC_ENT,   KC_SPC,  RAISE,   KC_MEH,  SPCMAC,  KC_DOWN, KC_UP   }
  },

  [_LOWER] = {
    { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    _______ },
    { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   KC_BSPC },
    { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,   KC_PIPE },
    { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU,   KC_MPLY }
  },

  [_RAISE] = {
    { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ },
    { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
    { _______, KC_PGUP, KC_HOME, KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
    { _______, KC_PGDN, KC_END,  KC_F9,   KC_F10,  KC_F11,  XXXXXXX, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
  },

  [_MOUSE] = {
    { _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, XXXXXXX, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______ },
    { _______, _______, _______, _______, _______, _______, XXXXXXX, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R }
  },

  [_ADJUST] = {
    { _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
    { _______, RESET,   _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, KC_DEL  },
    { _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, XXXXXXX, AG_SWAP, QWERTY,  _______, _______, _______, _______ },
    { _______, _______, VRSN,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
  }
};

void matrix_init_keymap(void) { // Runs boot tasks for keyboard
};

void matrix_scan_keymap(void) {  // runs frequently to update info
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
