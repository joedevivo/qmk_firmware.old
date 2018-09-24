#include "joedevivo.h"
#include "wait.h"
extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]  = SONG(QWERTY_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

/*
float tone_my_startup[][2] = SONG(ODE_TO_JOY);
float tone_my_goodbye[][2] = SONG(ROCK_A_BYE_BABY);

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
*/

#endif /* AUDIO_ENABLE */

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__ ((weak))
void matrix_init_keymap(void) {}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool music_mask_keymap(uint16_t keycode) {
  return true;
}

bool music_mask_user(uint16_t keycode) {
  return music_mask_keymap(keycode);
}

// Call user matrix init, then
// call the keymap's init function
void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
  layer_on(_QWERTY);
#ifdef AUDIO_ENABLE
  startup_user();
#endif
  matrix_init_keymap();
}

// No global matrix scan code, so just run keymap's matix
// scan function
void matrix_scan_user(void) {
  matrix_scan_keymap();
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _RAISE:
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(34);
#endif
      break;
    case _LOWER:
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(34);
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
      #rgblight_setrgb (0x00,  0xFF, 0xFF);
#endif
      break;
    }
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
#ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(tone_qwerty);
#endif
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
#ifdef RGBLIGHT_ENABLE
    case RGB_MOD:
      if (record->event.pressed) {
        rgblight_mode(RGB_current_mode);
        rgblight_step();
        RGB_current_mode = rgblight_config.mode;
      }
      return false;
      break;
#endif
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
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

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SPC_ENT]    = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [TD_SHIFT_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_ENT)
};


#ifdef AUDIO_ENABLE
void startup_user()
{
  wait_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}

void shutdown_user()
{
  PLAY_SONG(tone_goodbye);
  wait_ms(150);
  stop_all_notes();
}

void music_on_user(void)
{
  music_scale_user();
}

void music_scale_user(void)
{
  PLAY_SONG(music_scale);
}
#endif
