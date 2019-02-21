#include "joedevivo.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}
uint32_t layer_state_set_user (uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
switch (biton32(state)) {
    case _RAISE:
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(26);
#endif
      break;
    case _LOWER:
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(16);
#endif
        break;
    case _ADJUST:
#ifdef RGBLIGHT_ENABLE
      rgblight_setrgb (0x7A,  0x00, 0xFF);
#endif
      break;
    default: //  for any other layers, or the default layer
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(RGB_current_mode);
      rgblight_setrgb (0x00,  0xFF, 0xFF);
#endif
      break;
    }
  return layer_state_set_keymap(state);
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return process_record_keymap(keycode, record);
}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}
void matrix_scan_user(void) {
  matrix_scan_keymap();
}

__attribute__ ((weak))
void matrix_init_keymap(void) {}
void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
  layer_on(_QWERTY);
  matrix_init_keymap();
}


__attribute__ ((weak))
bool music_mask_keymap(uint16_t keycode) {
  return false;
}
bool music_mask_user(uint16_t keycode) {
  return music_mask_keymap(keycode);
}
