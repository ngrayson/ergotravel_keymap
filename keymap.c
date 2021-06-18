#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  COMPONE,
  COMPTWO
  // ADJUST,
};

enum combos {
  QE_SCTAB,
  WR_CTAB,
  ET_CST
};

const uint16_t PROGMEM qe_combo[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM et_combo[] = {KC_E, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QE_SCTAB] = COMBO(qe_combo, RCS(KC_TAB)),
  [WR_CTAB] = COMBO(wr_combo, RCTL(KC_TAB)),
  [ET_CST] = COMBO(et_combo, RCS(KC_T))
};

#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define OSHIFT OSM(MOD_LSFT)
#define OCTL OSM(MOD_LCTL)
#define OWIN OSM(MOD_LGUI)
#define OALT OSM(MOD_LALT)
#define VDLEFT LGUI(LCTL(KC_LEFT))
#define VDRIGHT LGUI(LCTL(KC_RIGHT))
#define SNAPUP LGUI(KC_UP) 
#define SNAPLEFT LGUI(KC_LEFT)
#define SNAPDOWN LGUI(KC_DOWN)
#define SNAPRIGHT LGUI(KC_RIGHT)
#define ALTF4 LALT(KC_F4)
#define REFRESH LCTL(KC_F5)
#define LOCK LGUI(KC_L)
#define MAXIMIZE HYPR(KC_M)
#define AUDIOSRC MEH(KC_G)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,           KC_MINS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_BSLS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,    KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LWIN, OSL(_RAISE), KC_LALT,    OSL(_LOWER), KC_SPC,           KC_BSPC, KC_ENT,            LOWER,  KC_LEFT,   KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_INS ,             _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,  \
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,             _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 , \
  OSHIFT , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______,             _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_PGUP, KC_RPRN, \
  OCTL   , OWIN   , _______, OALT   ,          _______, _______,             _______, _______,          _______, KC_HOME, KC_PGDN, KC_END  \

  ),

  [_RAISE] = LAYOUT(
  TSKMGR , VDLEFT  , SNAPUP  , VDRIGHT  , ALTF4    , REFRESH , _______,          _______, _______,   _______, _______, _______, _______, RESET ,  \
  CALTDEL, SNAPLEFT, MAXIMIZE, SNAPRIGHT, RSA(KC_F), AUDIOSRC, _______,          _______, _______,   _______, _______, _______, _______, KC_PWR, \
  KC_CAPS, _______ , SNAPDOWN, LOCK     , _______  , _______ , _______,          _______, _______,   _______, KC_MSTP, KC_MPLY, KC_VOLU, KC_MUTE, \
  COMPONE, COMPTWO , _______ , _______  ,            _______ , _______,          _______, _______,            _______, KC_MPRV, KC_VOLD,  KC_MNXT  \
  
  )

//   [_ADJUST] = LAYOUT(
//      TSKMGR,  _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL,
//      _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
//      _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, _______, _______, _______, _______, BL_STEP,
//      _______, _______, _______, _______,           _______, _______,         _______,  _______,          _______, _______, _______, RESET
//   )

};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
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
    case COMPONE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "1");
      } else{
      }
      return false;
      break;
    case COMPTWO:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "2");
      } else{
      }
      return false;
      break;
    // case ADJUST:
    //   if (record->event.pressed) {
    //     layer_on(_ADJUST);
    //   } else {
    //     layer_off(_ADJUST);
    //   }
    //   return false;
    //   break;
  }
  return true;
}
