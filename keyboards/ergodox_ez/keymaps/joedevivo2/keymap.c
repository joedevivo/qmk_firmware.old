#include "ergodox_ez.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "version.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  EPRM,
  VRSN,
  RGB_SLD
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// For Readability
#define CTL_ESC MT(MOD_LCTL, KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY Base Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |Z/Alt |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Alt | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  `~  |  Meh | Left | Right|                                       |  Up  | Down |   [  |   ]  | Raise|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |⌘/Esc| Alt  |       | Ctrl | ⌘    |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 |Backsp| Del  |------|       |------| Enter |Space |
 *                                 |ace   |      | End  |       | PgDn |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_QWERTY] = KEYMAP(  // layer 0 : default
    // left hand
    // Lightcycle Test -
    KC_EQL, KC_1,        KC_2,    KC_3,    KC_4,    KC_5,   XXXXXXX,
    //XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TAB,   KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,
    CTL_ESC,  KC_A,        KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT,  ALT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,    KC_MEH,
    ADJUST,   KC_MEH,      KC_LALT, KC_LGUI, LOWER,
                                                       KC_LCTL, KC_LALT,
                                                                KC_HOME,
                                          KC_BSPACE, KC_DELETE, KC_LGUI,
    // right hand
    // Lightcycle Test -
        XXXXXXX,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
    //    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        XXXXXXX,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                           RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,
        KC_LCTL, KC_LGUI,
        KC_END,
        KC_LGUI, KC_ENTER, KC_SPACE
    ),

  [_LOWER] = KEYMAP(
    // KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
    _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   KC_BSPC,
             KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,   KC_PIPE,
    _______, KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,
                    KC_MNXT, KC_VOLD, KC_VOLU,   KC_MPLY, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),


  [_RAISE] = KEYMAP(
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
    _______,  XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,
    _______,  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______,
    _______,  _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
             KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
                      KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),

  [_ADJUST] = KEYMAP(
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______,  RESET,   _______, _______, _______, _______, _______,
    _______,  EPRM,    _______, AU_ON,   AU_OFF,  AG_NORM,
    _______,  _______, VRSN,    _______, _______, _______, _______,
    _______,  _______, RGB_MOD, RGB_VAD, RGB_VAI,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______,
             AG_SWAP, QWERTY,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      RGB_HUI, RGB_HUD, RGB_TOG, RGB_SLD, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),
};

const uint16_t PROGMEM fn_actions[] = {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  startup_user();
};

void startup_user(void) {
  layer_on(_QWERTY);
}

void binary_lights(uint8_t number) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (number) {
    case 0:
      break;
    case 1:
      ergodox_right_led_3_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      ergodox_blink_all_leds();
      ergodox_blink_all_leds();
      break;
  }
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    binary_lights(layer);
};
