#include QMK_KEYBOARD_H
#include "joedevivo.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ergodox_pretty(
  KC_F18,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_GRV,    KC_BSLS, KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    X,
  X,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_TAB,    KC_QUOT, KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    X,
  X,       KC_A,    KC_S,    MOUSED,  ARROWF,  KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, X,
  X,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, CTL_ESC,   KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, X,
  LOWER,   LOWER,   KC_LALT, KC_LGUI, KC_LAPO,                                    KC_RAPC, KC_MEH,  SPCMAC, RAISE,   RAISE,
                                             KC_LALT, KC_LGUI,  KC_MEH, SPCMAC,
                                                            X,  X,
                                    KC_BSPC, KC_LCPO, KC_LSPO,  KC_RSPC, TD(MEH_RCBR), KC_SPACE
/*
  KC_LEFT, KC_RGHT, KC_LALT, KC_LGUI, LOWER,                                      RAISE,   KC_MEH,  SPCMAC,  KC_DOWN, KC_UP,
                                             KC_LALT, KC_LGUI,  KC_MEH, SPCMAC,
                                                            X,  X,
                                       KC_BSPC, KC_DEL, LOWER,  RAISE, KC_ENT, KC_SPC
*/
),
[_LOWER] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, X, X, _______, _______, _______,  _______, _______, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD, X, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  X, X, KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
  _______, _______, _______, _______, _______,                         _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY,
     _, _, _, _,
        _, _,
  _, _, _, _, _, _
),
[_RAISE] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, X, X, _______, _______, _______,  _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV, X, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  X, X, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______,                         _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
     _, _, _, _,
        _, _,
  _, _, _, _, _, _
),
[_MOUSE] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, X, X, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, X, X, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
  _______, _______, _______, _______, _______, _______,       _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  _______, _______, _______, _______, _______, _______, X, X, _______, _______, _______, _______, _______, _______,
  KC_WH_L, KC_WH_R, _______, _______, _______,                         _______, _______, _______, KC_WH_D, KC_WH_U,
     _, _, _, _,
        _, _,
  _, _, _, _, _, _
),
[_ARROW] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, X, X, _______, _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, X, X, _______, KC_PGUP, KC_UP,   KC_HOME, _______, _______,
  _______, _______, _______, _______, _______, _______,       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, X, X, _______, KC_PGDN, _______, KC_END,  _______, _______,
  KC_WH_L, KC_WH_R, _______, _______, _______,                         _______, _______, _______, KC_WH_D, KC_WH_U,
     _, _, _, _,
        _, _,
  _, _, _, _, _, _
),
[_ADJUST] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, X, X, _______, _______, _______,  _______, _______, _______,
  BACKLIT, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, X, X, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,       AG_SWAP, QWERTY,  _______,  _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   X, X, MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
  _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______,
     _, _, _, _,
        _, _,
  _, _, _, _, _, _
)
};

enum custom_keycodes {
  RGB_SLD = NEW_SAFE_RANGE,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_keymap(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_keymap(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
