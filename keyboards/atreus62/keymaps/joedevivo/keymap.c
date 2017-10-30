#include <stdarg.h>
#include "atreus62.h"
#include "quantum.h"
#include "action_layer.h"
#include "action_macro.h"
#include "action_util.h"
#include "version.h"

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)

// Layers
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

//Macros
enum {
  KF_1 = 0, // 1, F1
  KF_2, // ...
  KF_3,
  KF_4,
  KF_5,
  KF_6,
  KF_7,
  KF_8,
  KF_9,
  KF_10,
  KF_ESC,
  KF_12
};
/*
// Tapdance
enum {
  TD_FUN = 0,
  TD_EQ
};
*/
//State and timers
uint16_t kf_timers[12];

// Fillers to make layering more clear
#define _       KC_TRNS
#define __      KC_TRNS
#define ___     KC_TRNS
#define ____    KC_TRNS
#define _____   KC_TRNS
#define ______  KC_TRNS
#define _______ KC_TRNS

#define X       KC_NO
#define XX      KC_NO
#define XXX     KC_NO
#define XXXX    KC_NO
#define XXXXX   KC_NO
#define XXXXXX  KC_NO
#define XXXXXXX KC_NO
#define NO_KEY  KC_NO

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // Start here
  EPRM,
  VRSN,
};

// Cadet Lite (Left):
#define CDTL1 MT(MOD_HYPR, KC_GRV)
#define CDTL2 MT(MOD_LALT, KC_ESC)
#define CDTL3 MT(MOD_LCTL, KC_LEFT)
#define CDTL4 MT(MOD_LGUI, KC_RIGHT)

// Cadet Lite (Right):
#define CDTR1 MT(MOD_RGUI, KC_UP)
#define CDTR2 MT(MOD_RCTL, KC_DOWN)
#define CDTR3 MT(MOD_RALT, KC_LBRC)
#define CDTR4 MT(MOD_MEH, KC_RBRC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 *                      ,------.                                           ,------.
 *               ,------|   3  |------.                             ,------|   8  |------.
 * ,-------------|   2  |------|   4  |------.               ,------|   7  |------|   9  |------------.
 * | =/+  |   1  |------+   E  +------|   5  |               |   6  |------+   I  +------|   0  |  -   |
 * |------+------+   W  |------|   R  +------+               +------+   U  |------|   O  +------+------|
 * | Tab  |   Q  |------+   D  +------|   T  |               |   Y  |------+   +  +------|   P  | Del  |
 * |------+------+   S  |------|   F  +------+               +------+   J  |------|   {  +------+------|
 * | Ctrl |   A  |------+   C  +------|   G  |               |   H  |------+   ,  +------|   ;  |  |   |
 * |------+------+   X  |------|   V  +------+------. .------+------+   M  |------|   .  +------+------|
 * | Shift|   Z  |------+Ctrl/←+------|   B  |   D  | |  E   |   N  |------+Ctrl/↓+------|   ?  |Shift |
 * |------+------+AltEsc|------|CMD/→ +------|   e  | |  n   |------+ CMD/↑|------|Alt/[ +------+------|
 * | Lower| Hyp/'|------'      `------| Bksp |   l  | |  t   |Space |-------      -------| Hyp/] |Raise |
 * `-------------'                    `-------------' `-------------'                    `-------------'
 */

  [_QWERTY] = {
    {KC_EQL,     KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    NO_KEY,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS},
    {KC_TAB,     KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    NO_KEY,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS},
    {OSM_LCTL,   KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    NO_KEY,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {OSM_LSFT,   ALT_T(KC_Z),KC_X,    KC_C,    KC_V,    KC_B,    KC_DELT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
    {TT(_LOWER), CDTL1,      CDTL2,   CDTL3,   CDTL4,   KC_BSPC, KC_ENT,  KC_SPC,  CDTR1,   CDTR2,   CDTR3,   CDTR4,   TT(_RAISE)}
  },
  /* Lower
   *                      ,------.                                           ,------.
   *               ,------|  F3  |------.                             ,------|  F8  |------.
   * ,-------------|  F2  |------|  F4  |------.               ,------|  F7  |------|  F9  |------------.
   * | Esc  |  F1  |------+   ↑  +------|  F5  |               |  F6  |------+   ↑  +------| F10  |      |
   * |------+------+ LClk |------| RClk +------+               +------+      |------|      +------+------|
   * |      |      |------+ MClk +------|  F11 |               |  F12 |------+   ↓  +------|      |      |
   * |------+------+   ←  |------|   →  +------+               +------+   ←  |------|   →  +------+------|
   * |      |      |------+   ↓  +------|      |               |      |------+      +------|      |      |
   * |------+------+      |------|      +------+------. .------+------+      |------|      +------+------|
   * |      |      |------+      +------|      |      | |      |      |------+      +------|      |      |
   * |------+------+      |------|      +------|      | |      |------+      |------|      +------+------|
   * | VRSN |      |------'      `------|      |      | |      |      |-------      -------|      |      |
   * `-------------'                    `-------------' `-------------'                    `-------------'
   */
  [_LOWER] = {
    {KC_ESC, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,  NO_KEY, KC_F6,  KC_F7,   KC_F8,   KC_F9,    KC_F10, X},
    {XXXXXX, XXXXX, KC_BTN1, KC_MS_U, KC_BTN2, KC_F11, NO_KEY, KC_F12, XXXXXXX, KC_UP,   XXXXX,    X,      X},
    {XXXXXX, XXXXX, KC_MS_L, KC_BTN3, KC_MS_R, XXXXXX, NO_KEY, XXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, X,      X},
    {XXXXXX, XXXXX, XXXXXXX, KC_MS_D, XXXXXXX, XXXXXX, XXXXXX, X, X, X, X, X, X},
    {VRSN,   XXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXX, XXXXXX, X, X, X, X, X, TT(_QWERTY)}
  },

  // Old Macro Qwerty
  //[_QWERTY] = {
  // { M(KF_ESC),M(KF_1)  ,M(KF_2)  ,M(KF_3)  ,M(KF_4) ,M(KF_5)  ,KC_NO   ,M(KF_6) ,M(KF_7) ,M(KF_8) ,M(KF_9) ,M(KF_10) ,KC_MINS },
  // { KC_TAB   ,KC_Q     ,KC_W     ,KC_E     ,KC_R    ,KC_T     ,KC_NO   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P     ,KC_RBRC },
  // { OSM_LCTL ,KC_A     ,KC_S     ,KC_D     ,KC_F    ,KC_G     ,KC_NO   ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN  ,KC_QUOT },
  // { OSM_LSFT ,KC_Z     ,KC_X     ,KC_C     ,KC_V    ,KC_B     ,KC_DELT ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH  ,KC_LBRC },
  // { MO(NAV)  ,OSM_LCTL ,OSM_LALT ,KC_LGUI  ,MO(SYM) ,KC_BSPC  ,KC_ENT  ,KC_SPC  ,MO(SYM) ,KC_LEAD ,KC_LALT ,KC_LCTRL ,KC_HYP }
  //},

  /* Raise
   *                      ,------.                                           ,------.
   *               ,------|  F3  |------.                             ,------|      |------.
   * ,-------------|  F2  |------|  F4  |------.               ,------|      |------|      |------------.
   * | Esc  |  F1  |------+   8  +------|  F5  |               |      |------+   8  +------|      |      |
   * |------+------+   7  |------|   9  +------+               +------+   7︎  |------|   9  +------+-----|
   * |      |      |------+   5  +------|      |               |      |------+   5  +------|      |      |
   * |------+------+   4  |------|   6  +------+               +------+   4  |------|   6  +------+------|
   * |      |      |------+   2  +------|      |               |      |------+   2  +------|      |      |
   * |------+------+   1  |------|   3  +------+------. .------+------+   1  |------|   3  +------+------|
   * |      |      |------+      +------|      |   D  | |  E   |      |------+      +------|      |      |
   * |------+------+      |------|   0  +------|   e  | |  n   |------+      |------|   0  +------+------|
   * | Lower|      |------'      `------| Bksp |   l  | |  t   |      |-------      -------|      |Raise |
   * `-------------'                    `-------------' `-------------'                    `-------------'
   */
  [_RAISE] = {
    {X,           KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, NO_KEY, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, X},
    {X,           X,     X,     X,     X,     X,     NO_KEY, X,     KC_7 , KC_8 , KC_9 , X,      X},
    {X,           X,     X,     X,     X,     X,     NO_KEY, X,     KC_4 , KC_5 , KC_6 , X,      X},
    {X,           X,     X,     X,     X,     X,     KC_NO,  X,     KC_1 , KC_2 , KC_3 , X,      X},
    {TT(_QWERTY), X,     X,     X,     X,     X,     KC_NO,  X,     X,     X,     KC_0,  X,      TT(_ADJUST)}
/*
    {TO(_QWERTY),      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______},
    {______,      KC_F11,  KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_UP,   _______,  _______, _______},
    {______,      _______, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX, KC_F6,   KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______},
    {______,      _______, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, _______, KC_F12,  KC_NUHS, _______, _______,  _______, _______},
    {TO(_QWERTY), _______, _______, _______, KC_P0,   _______, _______, _______, _______, _______, _______,  _______, TO(_ADJUST)}

*/
  },
/* Adjust (Lower + Raise)
 *                      ,------.                                           ,------.
 *               ,------|      |------.                             ,------|      |------.
 * ,-------------|      |------|      |------.               ,------|      |------|      |------------.
 * | Reset|      |------+      +------|      |               |      |------+      +------|      | VRSN |
 * |------+------+      |------|      +------+               +------+      |------|      +------+------|
 * | EPRM |      |------+      +------|      |               |      |------+      +------|      | Del  |
 * |------+------+      |------|      +------+               +------+      |------|      +------+------|
 * |      |      |------+      +------|      |               |      |------+      +------|      |      |
 * |------+------+      |------|      +------+------. .------+------+      |------|      +------+------|
 * |      |      |------+      +------|      |      | |      |      |------+      +------|      |      |
 * |------+------+      |------|      +------|      | |      |------+ Lead |------|      +------+------|
 * | Lower|      |------'      `------|      |      | |      |      |-------      -------|      | VRSN |
 * `-------------'                    `-------------' `-------------'                    `-------------'
 */
  [_ADJUST] = {
    {RESET,       X, X, X, X, X, KC_NO, X, X, X, X, X, VRSN},
    {EPRM,        X, X, X, X, X, KC_NO, X, X, X, X, X, X},
    {X,           X, X, X, X, X, KC_NO, X, X, X, X, X, X},
    {X,           X, X, X, X, X, KC_NO, X, X, X, X, X, X},
    {TT(_RAISE),  X, X, X, X, X, KC_NO, X, X, X, X, X, VRSN}
  }
};
/*
#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

static void m_tapn (uint8_t code, ...) {
  uint8_t kc = code;
  va_list ap;

  va_start(ap, code);
  do {
    register_code(kc);
    unregister_code(kc);
    wait_ms(50);
    kc = va_arg(ap, int);
  } while (kc != 0);
  va_end(ap);
}
*/
static void m_handle_kf (keyrecord_t *record, uint8_t id) {
  uint8_t code = id - KF_1;

  if (record->event.pressed) {
    kf_timers[code] = timer_read ();
  } else {
    uint8_t kc_base = KC_1;
    uint8_t long_press = (kf_timers[code] && timer_elapsed (kf_timers[code]) > TAPPING_TERM);

    kf_timers[code] = 0;

    switch(id){
      case KF_1 ... KF_10:
        code += kc_base;
        if (long_press) {
          register_code (KC_LSFT);
        }
        register_code (code);
        unregister_code (code);
        if (long_press) {
          unregister_code (KC_LSFT);
        }
        break;
      case KF_ESC:
        code = long_press ? KC_ESC : KC_GRV;
        register_code (code);
        unregister_code (code);
        break;
      }
  }
}

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case KF_1 ... KF_ESC:
      m_handle_kf(record, id);
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
    /*
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
      */
  }
  return true;
}

/*
// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool queue = true;

  //Cancel one-shot mods.
  switch (keycode) {
    case KC_ESC:
      if (record->event.pressed && get_oneshot_mods() && !has_oneshot_mods_timed_out()) {
        clear_oneshot_mods();
        queue = false;
      }
      break;
  }
  return queue;
}
*/
/*
// TAP DANCE SETTINGS
void dance_eq (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1: // ===
      //register_code(KC_LSHIFT);
      m_tapn(KC_EQL, KC_EQL, KC_EQL, 0);
      //unregister_code(KC_LSHIFT);
      break;
    case 2:
      register_code(KC_LSHIFT);
      m_tapn(KC_1, KC_0, KC_0, 0);
      unregister_code(KC_LSHIFT);
      break;
    default:
      reset_tap_dance(state);
  }
}

void dance_fun (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1: // =>
      register_code(KC_LSHIFT);
      m_tapn(KC_0, KC_LABK, 0);
      unregister_code(KC_LSHIFT);
      break;
    case 2: // () => {}
      register_code(KC_LSHIFT);
      m_tapn(KC_8, KC_9, KC_SPC, KC_0, KC_LABK, KC_SPC, 0);
      unregister_code(KC_LSHIFT);
      register_code(KC_RALT);
      m_tapn(KC_7, 0);
      unregister_code(KC_RALT);
      TAP_ONCE(KC_ENT);
      break;
    default:
      reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_FUN] = ACTION_TAP_DANCE_FN (dance_fun)
 ,[TD_EQ] = ACTION_TAP_DANCE_FN (dance_eq)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  //set_unicode_input_mode(UC_WINC);
};
*/
// Leader Key
LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_J){
      SEND_STRING("joedevivo");
    }
  }
}

void matrix_init_user(void) {
  startup_user();
}

void startup_user(void) {
  layer_on(_QWERTY);
}
