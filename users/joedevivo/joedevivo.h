#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"

/* Define layer names */
enum userspace_layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FN,
  _MOUSE,
  _ARROW,
  _ADJUST
};

#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif
enum userspace_custom_keycodes {
  QWERTY = PLACEHOLDER_SAFE_RANGE,
  ADJUST,
  VRSN,
  EPRM,
  RGBRST,
  BACKLIT,
  NEW_SAFE_RANGE
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
#define CTL_ESC MT(MOD_RCTL, KC_ESC)
//#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define SFT_ENT TD(TD_SHIFT_ENT)
#define SPC_ENT TD(TD_SPC_ENT)

//One Shot Modifiers
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)

#define SPCMAC LALT(KC_M)
/**
 * 4-way thumbkins!
 *
 * on something like a Planck, I want a grid layout, but with four thumb keys
 * instead of two. I can't add keys, so I double tasked raise & lower
 */
#define LTHUMBI LT(_LOWER,  KC_BSPC)
#define LTHUMBO LT(_ADJUST, KC_DEL)
#define RTHUMBO KC_ENT
#define RTHUMBI LT(_RAISE,  KC_SPC)

#define MOUSED LT(_MOUSE, KC_D)
#define ARROWF LT(_ARROW, KC_F)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


uint32_t layer_state_set_rgb(uint32_t state);
