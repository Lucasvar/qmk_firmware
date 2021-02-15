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
#include "keymap_spanish.h"
#include "sendstring_spanish.h"
// #include "sendstring_spanish.h"
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FAKEALT
    // _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    TILDE
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base 
    *          ,-----------------------------------------.
    *          |   6  |   7  |  8   |  9   |  0   | supr |
    *          |------+------+------+------+------+------|
    *          |   Y  |   U  |   I  |   O  |   P  |      |
    *          |------+------+------+------+------+------|
    *  ,-------|   H  |   J  |   K  |   L  |      | Home |
    * |    }   |------+------+------+------+------+------|
    * |------- |   N  |   M  |   ,  |  .   |   -  |  End |
    *  \       \-----------------------------------------'
    *   \ Enter \  |BackSP |BackSP| AltGr| RAISE|
    *    \       \ |      |      |      |      |
    *     '------''---------------------------' 
 */
    [_BASE] = LAYOUT( \
    KC_DEL,   KC_0,   KC_9,    KC_8,    KC_7,    KC_6,        
    KC_HOME,   KC_P,   KC_O,    KC_I,    KC_U,    KC_Y,         
    KC_ENT, LT(_FAKEALT, KC_SCLN),   KC_L,    KC_K,    KC_J,    KC_H,         
    KC_END,  KC_SLSH,   KC_DOT,    KC_COMM,    KC_M,    KC_N, S(KC_7),
                KC_RIGHT, KC_DOWN, KC_UP,KC_LEFT, KC_BSPC
    ),

    /* _FAKEALT 
    *                                   
    *          ,-----------------------------------------.
    *          |   '  |   ¿  |      |  |   |  \   | supr |
    *          |------+------+------+------+------+------|
    *          |   |  |   @  |   ~  |   ¬  |   &  | Home |
    *          |------+------+------+------+------+------|
    *  ,-------|   <  |   >  |   *  |   ?  |      | Enter|
    * |    -   |------+------+------+------+------+------|
    * |------- |   +  |   {  |   [  |  ]   |   }  |  End |
    *  \       \-----------------------------------------'
    *   \ Enter \  |  ←   |  ↑   |  ↓   |  →   |
    *    \       \ |      |      |      |      |
    *     '------''---------------------------' 
 */
    [_FAKEALT] = LAYOUT( \
    KC_DEL,   ALGR(KC_MINS),   KC_GRV,    TILDE,    KC_EQL,    KC_MINS,        
    KC_HOME,   KC_CIRC,    ALGR(KC_6),  ALGR(KC_4),  ALGR(KC_2),    ALGR(KC_1),         
    KC_ENT, KC_TRNS,   S(KC_MINS),    S(KC_RBRC),    S(KC_NUBS),    KC_NUBS,         
    KC_END,  ALGR(KC_0),   ALGR(KC_9),    ALGR(KC_8),    ALGR(KC_7),   KC_RBRC, KC_SLSH,
                KC_RIGHT, KC_DOWN, KC_UP,KC_LEFT, KC_BSPC
    )
 
    // [_FN] = LAYOUT(
    //     QMKBEST, QMKURL,  _______,
    //         RESET,    XXXXXXX
    // )..:.:..:.ññÑñÑñÑñ''?'???p''''???..::....:.ññÑñmmmmmaaa ñÑññ
    //7777ñññ
};
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base 
//     * ,-------------------------------------.        
//     * | ESC  |   1  |   2  |   3  |   4  |   5  |        
//     * |------+------+------+------+------+------|        
//     * | Tab  |   Q  |   W  |   E  |   R  |   T  |        
//     * |------+------+------+------+------+------|        
//     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.
//     * |------+------+------+------+------+------|   {   |
//     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|
//     * `-----------------------------------------/       /
//     *            | LAlt | LOWER | Fn  | LGUI | / Space / 
//     *            |      |       | bs  |      |/       /  
//     *            `-----------------------------------'   
//  */
//     [_BASE] = LAYOUT( 
//     KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,        
//     KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,         
//     KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,         
//     KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,
//                 KC_LALT, KC_ENT, KC_BSPC,KC_LGUI, KC_SPC
//     ),
//     // [_FN] = LAYOUT(
//     //     QMKBEST, QMKURL,  _______,
//     //         RESET,    XXXXXXX
//     // )
// };

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
        case TILDE:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("canción");
            } else {
                // when keycode QMKURL is released
            }
            break;
        
    }
    return true;
}
