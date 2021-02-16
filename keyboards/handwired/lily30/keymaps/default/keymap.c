/* Copyright 2020 Lucas
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

// Defines names for use in layer keycodes and the keymap
// enum layer_names {
//     _BASE = 0,
//     _RAISE = 1,
// };
#define _BASE  0
#define _RAISE 1

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base 
    * ,-----------------------------------------.        
    * | ESC  |   1  |   2  |   3  |   4  |   5  |        
    * |------+------+------+------+------+------|        
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |        
    * |------+------+------+------+------+------|        
    * |LShift|   A  |   S  |   D  |   F  |   G  |-------.
    * |------+------+------+------+------+------|   {   |
    * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|
    * `----------------------------------------/       /
    *            |RAISE| LOWER | LGUI | LAlt |/ Space / 
    *            |     |      |      |      |/       /  
    *            `----------------------------------'   
 */
    [_BASE] = LAYOUT( 
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,        
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,         
        LSFT_T(KC_CAPSLOCK), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,         
        KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, S(ALGR(KC_QUOT)),
                MO(_RAISE), KC_A, KC_LGUI, KC_LALT, KC_SPC
    ),
    [_RAISE] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,  KC_F11,   KC_F12,   KC_F5,  
        KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_TRNS,   KC_TRNS,   KC_TRNS, 
        KC_TRNS,  KC_BRID,    KC_BRIU,    KC_TRNS,    KC_TRNS,    KC_TRNS, 
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   ALGR(S(KC_LBRC)), 
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS 
    )
}; 


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
