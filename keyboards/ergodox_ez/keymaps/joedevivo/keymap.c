#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define TAPPING_TOGGLE 1

//One Shot Modifiers
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)

#define XXXXXX KC_NO
#define ______ KC_TRANSPARENT

// Layers
enum {
  _QWERTY,
  _RAISE,
  _MOVE
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

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
 *                                        |⌘/Esc| Alt   |       | Ctrl | ⌘    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Backsp| Del  |------|       |------|  Enter |Space |
 *                                 |ace   |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_QWERTY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,    KC_1,        KC_2,    KC_3,    KC_4,   KC_5,   XXXXXX,
        KC_TAB,    KC_Q,        KC_W,    KC_E,    KC_R,   KC_T,   XXXXXX,
        OSM_LCTL,  KC_A,        KC_S,    KC_D,    KC_F,   KC_G,
        OSM_LSFT,  ALT_T(KC_Z), KC_X,    KC_C,    KC_V,   KC_B,   XXXXXX,
        XXXXXX,    KC_GRV,      KC_MEH,  KC_LEFT, KC_RGHT,
                                                    LGUI_T(KC_ESC), OSM_LALT,
                                                                     KC_HOME,
                                                KC_BSPACE, KC_DELETE, KC_END,
        // right hand
             XXXXXX,  KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             XXXXXX,  KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                      KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             XXXXXX,  KC_N,   KC_M,  KC_COMM,KC_DOT, ALT_T(KC_SLSH),   OSM_LSFT,
                              KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          TT(_RAISE),
             KC_LCTL, KC_LGUI,
             KC_PGUP,
             KC_PGDOWN, KC_ENTER, KC_SPACE
    ),
/* RISE_UP!
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| EPRM |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[_RAISE] = KEYMAP(
       // left hand
       VRSN,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXX,
       XXXXXX,      KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, XXXXXX,
       XXXXXX,      KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       XXXXXX,      KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, XXXXXX,
       TO(_QWERTY), XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,
                                       RGB_MOD,   EPRM,
                                                XXXXXX,
                                RGB_VAD,RGB_VAI,XXXXXX,
       // right hand
       XXXXXX, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       XXXXXX, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
               KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, XXXXXX,
       XXXXXX, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, XXXXXX,
                         XXXXXX,KC_DOT,  KC_0,    KC_EQL,  TO(_MOVE),
       RGB_TOG, RGB_SLD,
       XXXXXX,
       XXXXXX, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_MOVE] = KEYMAP(
       XXXXXX,     XXXXXX, XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,
       XXXXXX,     XXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXX, XXXXXX,
       XXXXXX,     XXXXXX, KC_MS_L, KC_BTN3, KC_MS_R, XXXXXX,
       XXXXXX,     XXXXXX, XXXXXX,  KC_MS_D, XXXXXX,  XXXXXX, XXXXXX,
       TO(_RAISE), XXXXXX, XXXXXX,  XXXXXXX, XXXXXX,
                                            XXXXXX, XXXXXX,
                                                    XXXXXX,
                                    XXXXXX, XXXXXX, XXXXXX,
    // right hand
       XXXXXX,  XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,
       XXXXXX,  XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,
                XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, KC_MPLY,
       XXXXXX,  XXXXXX, XXXXXX, KC_MPRV, KC_MNXT, XXXXXX, XXXXXX,
                       KC_VOLU, KC_VOLD, KC_MUTE, XXXXXX, XXXXXX,
       XXXXXX, XXXXXX,
       XXXXXX,
       XXXXXX, XXXXXX, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    //[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
