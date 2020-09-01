#pragma once

#ifdef AUDIO_ENABLE
//  #define AUDIO_CLICKY
  #define STARTUP_SONG SONG(IMPERIAL_MARCH)
  #define GOODBYE_SONG  SONG(SONIC_RING)
  #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                SONG(COLEMAK_SOUND), \
                                SONG(DVORAK_SOUND), \
                                SONG(OVERWATCH_THEME) \
                                  }

  #define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f
  #ifndef __arm__
    #undef  NOTE_REST
    #define NOTE_REST         1.00f
  #endif // !__arm__

#define UNICODE_SONG_OSX SONG(RICK_ROLL)
#define UNICODE_SONG_LNX SONG(RICK_ROLL)
#define UNICODE_SONG_WIN SONG(RICK_ROLL)
#define UNICODE_SONG_BSD SONG(RICK_ROLL)
#define UNICODE_SONG_WINC SONG(RICK_ROLL)

#endif // !AUDIO_ENABLE
// TODO: What's up with tapping_term?

#ifdef TAPPING_TERM
  #undef TAPPING_TERM
#endif // TAPPING_TERM
#if defined(KEYBOARD_ergodox_ez)
  #define TAPPING_TERM 160
#else
  #define TAPPING_TERM 175
#endif

#ifdef RGBLIGHT_ANIMATIONS
  #undef RGBLIGHT_ANIMATIONS
#endif // RGBLIGHT_ANIMATIONS
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_ANIMATIONS
#endif // RGBLIGHT_ENABLE

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define LAPO_KEYS KC_LALT, KC_TRNS, KC_LBRC
#define LCPO_KEYS KC_LGUI, KC_LSFT, KC_LBRC
//#define RCPC_KEYS LSFT(LCTL(KC_LALT)), KC_LSFT, KC_RBRC
#define RAPC_KEYS KC_LCTL, KC_TRNS, KC_RBRC
