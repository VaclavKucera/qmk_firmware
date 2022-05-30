/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NUMPAD,
  _ADJUST,
  _FUNCTION
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define NUMSPACE LT(_NUMPAD,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | FTab |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  '   | Ctrl | Alt  | GUI  |Lower |Space |SpNum |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_ESC,                KC_Q,    KC_W,     KC_E,     KC_R,   KC_T,        KC_Y,    KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,
  LT(_FUNCTION,KC_TAB),  KC_A,    KC_S,     KC_D,     KC_F,   KC_G,        KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
  OSM(MOD_LSFT),         KC_Z,    KC_X,     KC_C,     KC_V,   KC_B,        KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
  _______,               KC_LCTRL,KC_LALT,  KC_LGUI,  LOWER,  NUMSPACE,    NUMSPACE,RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  '   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  -   |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |    Space    |Raise |      | BUp  | BDown|      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, _______, _______,  _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______,
  _______, _______, _______,  _______, _______, KC_SPC,  KC_SPC,  _______, _______, KC_PAUS, KC_SLCK, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   ě  |   š  |   č  |   ř  |   ž  |   ý  |   á  |   í  |   é  |  ú   | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |      |  ů   |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Mute |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |    Space    |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_TILD, RALT(KC_2),RALT(KC_3),RALT(KC_4),RALT(KC_5),RALT(KC_6),RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0),RALT(KC_LBRC), KC_DEL,
  _______,  _______,  _______,   _______,   _______,   _______,   _______,    KC_UNDS,   KC_PLUS,   _______,  RALT(KC_SCLN),RALT(KC_QUOT),
  _______,  _______,  _______,   _______,   _______,   _______,   _______,    KC_MUTE,   _______,   _______,   _______,   _______,
  _______,  _______,  _______,   _______,   _______,   KC_SPC,    KC_SPC,     _______,   KC_MNXT,   KC_VOLD,   KC_VOLU,   KC_MPLY
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_NUMPAD] = LAYOUT_ortho_4x12(
  _______,  KC_1,     KC_2,      KC_3,      KC_4,      KC_5,      KC_6,       KC_7,      KC_8,      KC_9,      KC_0,    _______,
  _______,  _______,  _______,   _______,   _______,   _______,   _______,    KC_4,      KC_5,      KC_6,      _______, _______,
  _______,  _______,  _______,   _______,   _______,   _______,   _______,    KC_1,      KC_2,      KC_3,      _______, _______,
  _______,  _______,  _______,   _______,   _______,   KC_SPC,    KC_SPC,     _______,   KC_0,      _______,   _______, _______
), 

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |RESET |RGBVAI|RGBSAI|RGBHUI|BLSTEP|      |      |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |RGBVAD|RGBSAD|RGBHUD|RGBTOG|      |      |  F4  |  F5  |  F6  |  F12 |  F13 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |CAltDe|      |      |      |      |      |      |  F1  |  F2  |  F3  |  F14 |  F15 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TSKMGR|      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  RESET,   RGB_VAI, RGB_SAI, RGB_HUI, BL_STEP, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F12,  KC_F13,
  CALTDEL, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F14,  KC_F15,
  TSKMGR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |LClick|MUp   |RClick|      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MLeft |MDown |MRight|      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
  _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    
    return false;
}
