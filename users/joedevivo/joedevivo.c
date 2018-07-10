#include "joedevivo.h"

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

// Call user matrix init, then
// call the keymap's init function
void matrix_init_user(void) {
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

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
#ifdef RGBLIGHT_ENABLE
    rgblight_mode(RGB_current_mode);
#endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
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
    case LOWER:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
#ifdef RGBLIGHT_ENABLE
          rgblight_mode(16);
#endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
#endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
#ifdef RGBLIGHT_ENABLE
          rgblight_mode(16);
#endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
#endif
        TOG_STATUS = false;
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
  _delay_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}

void shutdown_user()
{
  PLAY_SONG(tone_goodbye);
  _delay_ms(150);
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
