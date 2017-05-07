#include <stdarg.h>
#include "atreus62.h"
#include "action_layer.h"
#include "action_macro.h"
#include "action_util.h"
#include "keymap_colemak.h"

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)

#define KC_HYP LSFT(LALT(LCTL(KC_LGUI)))

#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(LSFT(KC_Z))

// Layers
enum {
  BASE = 0,
  NAV,
  SYM
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = {

   { M(KF_ESC),M(KF_1)  ,M(KF_2)  ,M(KF_3)  ,M(KF_4) ,M(KF_5)  ,KC_NO   ,M(KF_6) ,M(KF_7) ,M(KF_8) ,M(KF_9) ,M(KF_10) ,KC_MINS },
   { KC_TAB   ,KC_Q     ,KC_W     ,KC_E     ,KC_R    ,KC_T     ,KC_NO   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P     ,KC_RBRC },
   { OSM_LCTL ,KC_A     ,KC_S     ,KC_D     ,KC_F    ,KC_G     ,KC_NO   ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN  ,KC_QUOT },
   { OSM_LSFT ,KC_Z     ,KC_X     ,KC_C     ,KC_V    ,KC_B     ,KC_DELT ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH  ,KC_LBRC },
   { MO(NAV)  ,OSM_LCTL ,OSM_LALT ,KC_LGUI  ,MO(SYM) ,KC_BSPC  ,KC_ENT  ,KC_SPC  ,MO(SYM) ,KC_LEAD ,KC_LALT ,KC_LCTRL ,KC_HYP }

 },
  [NAV] = {

   { KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS },
   { KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_NO   ,KC_HOME  ,KC_PGDN  ,KC_PGUP  ,KC_END   ,KC_TRNS  ,KC_TRNS },
   { KC_TRNS  ,KC_LSFT  ,KC_LCTL  ,KC_LALT  ,KC_L     ,KC_TRNS  ,KC_NO   ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RIGHT ,KC_TRNS  ,KC_TRNS },
   { KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS },
   { KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_VOLD  ,KC_VOLU }

  },
  [SYM] = {

   { RESET    ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS   ,KC_NO   ,KC_TRNS    ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS },
   { KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_UP    ,KC_TRNS  ,KC_PLUS   ,KC_NO   ,KC_AT      ,KC_DQT   ,KC_QUOT  ,KC_GRV   ,KC_SLSH  ,KC_TRNS },
   { KC_TRNS  ,KC_TRNS  ,KC_LEFT  ,KC_DOWN  ,KC_RGHT  ,KC_MINS   ,KC_NO   ,KC_UNDS    ,KC_CIRC  ,KC_DLR   ,KC_AMPR  ,KC_PIPE  ,KC_TRNS },
   { KC_TRNS  ,KC_TRNS  ,KC_VOLU  ,KC_TRNS  ,KC_TRNS  ,KC_ASTR   ,KC_TRNS ,KC_HASH    ,KC_SCLN  ,KC_COLN  ,KC_QUES  ,KC_BSLS  ,KC_TRNS },
   { KC_TRNS  ,KC_NO    ,KC_VOLD  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS   ,KC_TRNS ,KC_TRNS    ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS }

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
    SEQ_ONE_KEY(CM_J){

      SEND_STRING("y;kgkvlv;");
    }
  }
}
