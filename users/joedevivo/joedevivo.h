#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#include "version.h"

#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

#define TAPPING_TERM 150

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum userspace_custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  VRSN,
  EPRM,
  NEW_SAFE_RANGE
};

enum tap_dance_declarations {
  TD_SPC_ENT = 0,
  TD_SHIFT_ENT
};

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

// For Readability
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
//#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define SFT_ENT TD(TD_SHIFT_ENT)
#define SPC_ENT TD(TD_SPC_ENT)

//One Shot Modifiers
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)

// 4-way thumbkins!
#define LTHUMBI LT(_LOWER,  KC_BSPC)
#define LTHUMBO LT(_ADJUST, KC_DEL)
#define RTHUMBO KC_ENT
#define RTHUMBI LT(_RAISE,  KC_SPC)

#endif
