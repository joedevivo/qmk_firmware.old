#include "rorschach.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FN3 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,

  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen
#define KC_ESCC MT(MOD_LCTL, KC_ESC)
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_BL_S BL_STEP
#define KC_GRVF LT(_FN3, KC_GRV)
#define KC_ENTS MT(MOD_LSFT, KC_ENT)
#define KC_BSTP BL_STEP
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESCC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,                N  , M  ,COMM,DOT ,SLSH,ENTS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GRVF,LCTL,LALT,LGUI,LOWR,SPC ,               BSPC,RASE,LEFT,DOWN, UP ,RGHT,
  //`----+----+----+----+----+----+----.    .----+----+----+----+----+----+----'
                              LEFT,DEL ,     PGDN,RGHT
  //                         `----+----'    `----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL ,CAPP,LEFT,RGHT, UP ,LBRC,               RBRC, P4 , P5 , P6 ,PLUS,PIPE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,CPYP,    ,    ,DOWN,LCBR,               RCBR, P1 , P2 , P3 ,MINS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     BSTP,    ,    ,    ,    ,DEL ,               DEL ,    , P0 ,PDOT,    ,    ,
  //`----+----+----+----+----+----+----.    .----+----+----+----+----+----+----'
                                  ,    ,         ,     
  //                         `----+----'    `----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL ,MPRV,MNXT,VOLU,PGUP,UNDS,               EQL ,HOME,    ,    ,    ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MUTE,MSTP,MPLY,VOLD,PGDN,MINS,               PLUS,END ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----.    .----+----+----+----+----+----+----'
                                  ,    ,         ,     
  //                         `----+----'    `----+----'
  ),

  [_FN3] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----.    .----+----+----+----+----+----+----'
                                  ,    ,         ,     
  //                         `----+----'    `----+----'
  ),

  // Adjust (Lower + Raise)
  [_ADJUST] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,RMOD,RHUI,RSAI,RVAI,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RST ,DBUG,RHUD,RSAD,RVAD,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----.    .----+----+----+----+----+----+----'
                                  ,    ,         ,     
  //                         `----+----'    `----+----'
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
