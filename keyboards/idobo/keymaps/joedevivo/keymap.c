#include QMK_KEYBOARD_H
#include "joedevivo.h"
#include "muse.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x15(
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _,_,_,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _,_,_,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  CTL_ESC, KC_A,    KC_S,    MOUSED,  ARROWF,  KC_G,    _,_,_,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _,_,_,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LEFT, KC_RGHT, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_DEL,_,KC_ENT, KC_SPC,  RAISE,   KC_MEH,  SPCMAC,  KC_DOWN, KC_UP
),

[_LOWER] = LAYOUT_ortho_5x15(
  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _,_,_, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _,_,_, KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _,_,_, KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _,_,_, KC_ENT,  _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_ortho_5x15(
  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _,_,_, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _,_,_, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _,_,_, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, KC_DEL,  _,_,_, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_MOUSE] = LAYOUT_ortho_5x15(
  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
  _______, _______, _______, _______, _______, _______, _,_,_, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
  _______, _______, _______, _______, _______, _______, _,_,_, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  _______, _______, _______, _______, _______, _______, _,_,_, _______, _______, _______, _______, _______, _______,
  KC_WH_L, KC_WH_R, _______, _______, _______, _______, _,_,_, _______, _______, _______, _______, KC_WH_D, KC_WH_U
),

[_ARROW] = LAYOUT_ortho_5x15(
  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
  _______, _______, _______, _______, _______, _______, _,_,_, _______, KC_PGUP, KC_UP,   KC_HOME, _______, _______,
  _______, _______, _______, _______, _______, _______, _,_,_, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _,_,_, _______, KC_PGDN, _______, KC_END,  _______, _______,
  KC_WH_L, KC_WH_R, _______, _______, _______, _______, _,_,_, _______, _______, _______, _______, KC_WH_D, KC_WH_U
),

[_ADJUST] = LAYOUT_ortho_5x15(
  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
  BACKLIT, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, _,_,_, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, _,_,_, AG_SWAP, QWERTY,  _______,  _______, _______,  _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   _,_,_, MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _,_,_, _______, _______, _______,  _______, _______, _______
)
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
        //  PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
        //  PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_keymap(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_keymap(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

