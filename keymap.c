#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

// https://docs.qmk.fm/#/keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ~   |   1  |   2  |   3  |   4  |   5  |   -  |                    |   +  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   {  |                    |   }  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  | Left |                    | Right|   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | LANG |   Z  |   X  |   C  |   V  |   B  |  Up  |                    | Down |   N  |   M  |   ,  |   .  |   /  | PGUP |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | LANG |  OS  |  ALt |  Del | Shift| Raise| Space|      ||||||||      | Enter| Lower| CTRL | Back | HOME |  END | PGDN |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_GRV,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_MINS,          KC_EQL,   KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR, \
    KC_ESC,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_LBRC,          KC_RBRC,  KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_TAB,   KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_LEFT,          KC_RIGHT, KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_HENK,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,  KC_UP,            KC_DOWN,  KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PGUP, \
    KC_MHEN,  KC_LGUI, KC_LALT, KC_DEL, KC_LSFT, RAISE, KC_SPC,           KC_ENT,   LOWER, KC_LCTL, KC_BSPC, KC_HOME, KC_END,  KC_PGDN
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |   `  |  Up  |   -  |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |      | Left | Down | Right|   =  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  |      |                    |      |      |      |   [  |   ]  |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |  Esc | Shift|ADJUST|  Tab |      ||||||||      |      | Lower|      |      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_NO,  KC_F1,  KC_F2,  KC_F3, KC_F4,  KC_F5,  KC_F6,              KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12, KC_NO, \
    KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,              KC_NO,  KC_NO,  KC_GRV,  KC_UP,   KC_MINS,  KC_NO,  KC_NO, \
    KC_NO,  KC_1,   KC_2,   KC_3,  KC_4,   KC_5,   KC_NO,              KC_NO,  KC_NO,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_EQL, KC_NO, \
    KC_NO,  KC_6,   KC_7,   KC_8,  KC_9,   KC_0,   KC_NO,              KC_NO,  KC_NO,  KC_NO,   KC_LBRC, KC_RBRC,  KC_NO,  KC_NO, \
    KC_NO,  KC_NO,  KC_NO,  KC_ESC,KC_LSFT,ADJUST, KC_TAB,             KC_NO,  LOWER,  KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      | WH_L | WH_U | WH_R |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      | CLI_4| MK_U | CLI_5|      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |      | CLI_1| MK_L | MK_D | MK_R |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |                    |      |      | CLI_1| wH_D | CLI_2|      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |      | RAISE| Space|      ||||||||      |  Alt |ADJUST| CTRL |      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,            KC_NO,  KC_NO,   KC_WH_L, KC_WH_U, KC_WH_R, KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,            KC_NO,  KC_NO,   KC_BTN4, KC_MS_U, KC_BTN5, KC_NO, KC_NO, \
    KC_NO, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,           KC_NO,  KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, \
    KC_NO, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F12,           KC_NO,  KC_NO,   KC_BTN1, KC_WH_D, KC_BTN2, KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   RAISE,  KC_SPC,           KC_LALT,ADJUST,  KC_LCTL, KC_NO,   KC_NO,   KC_NO, KC_NO
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
