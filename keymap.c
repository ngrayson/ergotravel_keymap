#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

// fancy alt tab timer
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define ES_TSK LT(0,KC_1)
#define DOT_PR LT(0,KC_2)
#define COM_PR LT(0,KC_3)
#define TABL LT(0,KC_F1)
#define TABR LT(0,KC_F2)
#define TABCLOSE LT(0,KC_F3)
#define PLS_MIN LT(0,KC_F4)
#define RE_CACHE LT(0,KC_F5)
#define QUIT LT(0,KC_6)
#define MEN_AST LT(0,KC_TAB)
#define FOC_1 LT(0,KC_A)
#define FOC_2 LT(0,KC_S)
#define FOC_3 LT(0,KC_D)
#define FOC_4 LT(0,KC_F)
#define AUD_5 LT(0,KC_H) // 6 on tap, toggle audio source on hold
#define TD_RD LT(0,KC_G) // macro for labelling in gmail
#define WT_SV LT(0,KC_J) // macro for labelling in gmail
#define ABRC LT(0,KC_K) // Brackets (ambidexterous)

#define DRK_1 LT(0,KC_Z)
#define LNKPST_4 LT(0,KC_L) // hyperlink and paste clipboard
#define VIS_HASH LT(0,KC_C)
#define TAB_RES LT(0,KC_ESC)
#define ALT_TAB LT(0, KC_F22) // alt tab with timeout functionality
#define SHALTAB LT(0, KC_F21) // when held: shift, when tapped: alt tab with timeout functionality
#define KVMONE LT(0,KC_LGUI)
#define KVMTWO LT(0,KC_RGUI)

#define VDLEFT LGUI(LCTL(KC_LEFT))
#define VDRIGHT LGUI(LCTL(KC_RIGHT))
#define SNAPUP LGUI(KC_UP)
#define SNAPLEFT LGUI(KC_LEFT)
#define SNAPDOWN LGUI(KC_DOWN)
#define SNAPRIGHT LGUI(KC_RIGHT)
#define LOCK LGUI(KC_L)
#define MAXIMIZE HYPR(KC_M)
#define AUDIOSRC MEH(KC_G)
#define PIK_WIN LCA(KC_TAB)
#define VDTVIEW LGUI(KC_TAB)
#define SH_TAB LSFT_T(KC_TAB)
#define SSNIP LGUI(LSFT(KC_S)) // GUI+SHIFT+S for snipping tool
#define SH_SLS RSFT_T(KC_SLSH)
#define SH_BSLS RSFT_T(KC_BSLS)

#define CLFT LCTL(KC_LEFT)
#define CRGT LCTL(KC_RIGHT)
#define CUP LCTL(KC_UP)
#define CDN LCTL(KC_DOWN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     ES_TSK , KC_Q   , KC_W   , KC_E,    KC_R,    KC_T,    KC_INS,           KC_GRV, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , PLS_MIN,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     SH_TAB , KC_A   , KC_S   , KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_Z   , KC_X   , KC_C,    KC_V,    KC_B,    KC_SPC,           KC_MPLY, KC_N   , KC_M   , COM_PR , DOT_PR , ABRC   , SH_SLS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, RAISE  , KC_LALT, LOWER,            KC_SPC,           KC_BSPC,          KC_ENT , KC_RGUI, KC_DEL , _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     TAB_RES, TABL   , TABCLOSE, TABR  , QUIT   , RE_CACHE,_______,          _______, KC_F6  , KC_F7  , KC_UP  , KC_F9  , KC_F10 , KC_F11 ,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     SHALTAB, KC_HOME, KC_PGDN, KC_PGUP, KC_END , AUD_5  , SSNIP,            _______, KC_CIRC, KC_LEFT, KC_DOWN, KC_RIGHT,KC_F8  , KC_F12 ,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, DRK_1  , KC_2   , KC_3   , LNKPST_4 , KC_5 , _______,          _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , SH_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
    KC_GRV  , VDLEFT , SNAPUP , VDRIGHT, QUIT   , RE_CACHE, _______,         _______, _______,   _______, _______, _______, _______, QK_BOOT ,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______,SNAPLEFT, MAXIMIZE,SNAPRIGHT,RSA(KC_F),AUDIOSRC,_______,        _______, _______,   _______, _______, _______, _______, KC_PWR,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_CAPS,_______ , SNAPDOWN,LOCK   , _______, _______, _______,          _______, _______,   _______, KC_MSTP, KC_MPLY, KC_VOLU, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KVMONE , KVMTWO , _______, _______,          _______, _______,          _______, _______,            _______, KC_MPRV, KC_VOLD,  KC_MNXT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     ES_TSK , _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_MOD , RGB_VAI, RGB_SAI, RGB_HUI, AUDIOSRC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, _______ , _______, _______, _______, BL_STEP,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,           _______, _______,         _______,  _______,          _______, _______, _______, QK_BOOT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  )

};


layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KVMONE:
          if (record->event.pressed) {
              SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(20) SS_TAP(X_SCRL) SS_DELAY(20) "1" SS_DELAY(20));  // SS_TAP(X_ENTER)
          } else{
          }
          return false;
        case KVMTWO:
          if (record->event.pressed) {
              SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(20) SS_TAP(X_SCRL) SS_DELAY(20) "2" SS_DELAY(20));  // SS_TAP(X_ENTER)
          } else{
          }
          return false;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
          return false;
        case ES_TSK:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_ESC); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LCTL(LSFT(KC_ESC))); // Intercept hold function to send Ctrl-V
          }
          return false;

        case ABRC:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_LBRC); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_RBRC); // Intercept hold function to send Ctrl-V
          }
          return false;
        case DOT_PR:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_DOT); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_RPRN); // Intercept hold function to send Ctrl-V
          }
          return false;
        case COM_PR:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_COMM); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_LPRN); // Intercept hold function to send Ctrl-V
          }
          return false;
        case PLS_MIN:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_EQL); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_MINS); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TAB_RES:
          if (record->tap.count && record->event.pressed) {
              tap_code16(RCTL(RSFT(KC_T))); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TABL:
          if (record->tap.count && record->event.pressed) {
              tap_code16(RCTL(RSFT(KC_TAB))); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F1); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TABCLOSE:
          if (record->tap.count && record->event.pressed) {
            tap_code16(RCTL(KC_W)); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F2); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TABR:
          if (record->tap.count && record->event.pressed) {
              tap_code16(RCTL(KC_TAB)); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F3); // Intercept hold function to send Ctrl-V
          }
          return false;
        case RE_CACHE:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_F5); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(RCTL(KC_F5)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case QUIT:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_F4); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(RALT(KC_F4)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case MEN_AST:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_ASTR); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_X)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_1:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_1); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_1)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_2:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_2); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_2)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_3:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_3); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_3)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_4:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_4); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_4)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case AUD_5:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_5); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(AUDIOSRC); // Intercept hold function to send Ctrl-V
          }
          return false;
        case DRK_1:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_1); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LSFT(LALT(KC_F))); // Intercept hold function to send Ctrl-V
          }
          return false;
        case LNKPST_4:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_4);
          } else if (record->event.pressed) {
              SEND_STRING(SS_LCTL("k") SS_DELAY(20) SS_LCTL("v"));
          }
          return false;
        case VIS_HASH:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_HASH); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(LALT(KC_V))); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TD_RD:
          if (record->tap.count && record ->event.pressed){
            SEND_STRING("vto-do\n");
          }
          else if (record->event.pressed){
            SEND_STRING("vread-through\n");
          }
          return false;
        case WT_SV:
          if (record->tap.count && record -> event.pressed){
            SEND_STRING("vwaiting\n");
          }
          else if (record->event.pressed){
              SEND_STRING("vsave\n");
          }
          return false;

        case SHALTAB:
          if (record->tap.count && record->event.pressed) {
             if (record->event.pressed) { // alt tab timer active
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
          } else if (record->event.pressed) {
              register_code(KC_LSFT); // Intercept hold function to send Ctrl-V
          }
          else {
              unregister_code(KC_LSFT);
          }
          return false;
    }

    return true;
}

// alt tab timer
void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

