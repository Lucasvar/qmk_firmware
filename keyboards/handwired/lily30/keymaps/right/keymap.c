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
enum layer_names {
    _BASE,
    // _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base 
    *          ,-----------------------------------------.
    *          |   6  |   7  |  8   |  9   |  0   | supr |
    *          |------+------+------+------+------+------|
    *          |   Y  |   U  |   I  |   O  |   P  | Home |
    *          |------+------+------+------+------+------|
    *  ,-------|   H  |   J  |   K  |   L  |      | End  |
    * |    }   |------+------+------+------+------+------|
    * |------- |   N  |   M  |   ,  |  .   |   -  |      |
    *  \       \-----------------------------------------'
    *   \ Enter \  |BackSP |BackSP| AltGr| RAISE|
    *    \       \ |      |      |      |      |
    *     '------''---------------------------' 
 */
    [_BASE] = LAYOUT( \
    KC_DEL,   KC_0,   KC_9,    KC_8,    KC_7,    KC_6,        
    KC_HOME,   KC_P,   KC_O,    KC_I,    KC_U,    KC_Y,         
    KC_END, KC_A,   KC_L,    KC_K,    KC_J,    KC_H,         
    KC_LSFT,  KC_MINUS,   KC_DOT,    KC_SCOLON,    KC_M,    KC_N, KC_RBRACKET,
                KC_DOWN, KC_UP, KC_RALT,KC_ENT, KC_BSPC
    ),
    // [_FN] = LAYOUT(
    //     QMKBEST, QMKURL,  _______,
    //         RESET,    XXXXXXX
    // )
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
