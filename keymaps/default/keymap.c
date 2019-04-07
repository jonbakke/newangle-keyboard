/* Copyright 2018 Jonathan Bakke
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

/* Version 1.1a
 * 
 * Move capslock from F1-f to F1-Esc-F3
 * 
 */

/* TODO
 * Upgrade QMK
 * Add capital-I-apostrophe to F1-e
 */

#include "newangle.h"

/* Layers */
#define BASE 0
#define SYMB 1
#define SHRT 2
#define NUMB 3
#define FF12 4
#define FF24 5
#define NAVI 6

/* Macros */
enum custom_keycodes {
    MY_IAPO = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MY_IAPO:
	      SEND_STRING("I'");
                return false;
        }
    }
    return true;
};

/* Layout */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = KEYMAP(
/*
,  .  K  P           G  C  R  L 
A  O  E  I  Y     F  H  T  N  S 
Z  Q  J  U  X  es V  D  M  W  B  -- escape
   gu sh fn fn    ct fn sp al    -- gui, shift, function layers, control, space, alt
*/
    KC_COMM, KC_DOT,  KC_K,                                KC_C,    KC_R,    KC_L,
  KC_A,    KC_O,    KC_E,    KC_P,                  KC_G,    KC_T,    KC_N,    KC_S,
KC_Z,    KC_Q,    KC_J,    KC_I,    KC_Y,    KC_F,    KC_H,    KC_M,    KC_W,    KC_B,
              KC_LGUI, KC_U,    KC_X,    KC_ESC,  KC_V,    KC_D,    OSM(MOD_LALT),
            OSM(MOD_LSFT), MO(SYMB), MO(NUMB), OSM(MOD_LCTL), MO(NAVI), KC_SPC
),

[SYMB] = KEYMAP(
/*
,  .  ;  "           ?  !  -  _ 
ho pu ?? '  \     ca sh gu al ct -- home, pgup, media layer, caps
en pd [  ]  /  fn  @  (  )  #  *  -- end, pgdn
   xx xx XX xx    `  tb en ??    -- xx for unavail, XX for pressed, tab, enter
*/
    KC_COMM, KC_DOT,  KC_SCLN,                             KC_EXLM, KC_MINS, KC_UNDS,
  KC_HOME, KC_PGUP, MY_IAPO, KC_DQUO,             KC_QUES, KC_LGUI, KC_LALT, KC_LCTL,
KC_END,  KC_PGDN, KC_LBRC, KC_QUOT, KC_BSLS, KC_NO, OSM(MOD_LSFT), KC_RPRN, KC_HASH, KC_ASTR,
    KC_NO,   KC_RBRC, KC_SLSH, MO(SHRT),    KC_AT,   KC_LPRN, KC_NO,
                  KC_NO,   KC_TRNS, KC_NO,   KC_GRV,  KC_TAB,  KC_ENT
),

[SHRT] = KEYMAP(
/*
?? ?? ?? ??          ?? ff vu ?? -- fast foward, volu up
?? ?? ?? ?? ??    ?? sb pp mu ?? -- screen bright, play, mute
?? ?? ?? ?? ?? XX ?? sd rw vd ?? -- screen dim, rewind, vol dn
   xx xx XX xx    ?? ?? ?? ??
*/
    KC_NO,   KC_NO,   KC_NO,                               KC_MFFD, KC_VOLU, KC_NO,
  KC_NO,   KC_NO,   KC_TRNS, KC_NO,                 KC_NO,   KC_MPLY, KC_MUTE, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F15,  KC_MRWD, KC_VOLD, KC_NO,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_F14,  KC_NO,
                  KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_CAPS,   KC_NO
),

[NUMB] = KEYMAP(
/*
1  2  3  4           k. k, %  ^  -- keypad dot, keypad comma
5  6  7  8  in    $  sh gu al ct -- insert
9  0  -  =  ps ?? &  k/ k* k- k+ -- print screen, keypad slash, etc
   xx xx xx XX    12 tb en 24    -- layer toggles
*/
    KC_1,    KC_2,    KC_3,                                KC_PCMM, KC_PERC, KC_CIRC,
  KC_5,    KC_6,    KC_7,    KC_4,                  KC_PDOT, KC_LGUI, KC_LALT, KC_LCTL,
KC_9,    KC_0,    KC_MINS, KC_8,    KC_INS,  KC_DLR,  KC_LSFT, KC_PAST, KC_PMNS, KC_PPLS,
             KC_NO,   KC_EQL,  KC_PSCR, KC_NO,    KC_AMPR, KC_PSLS, MO(FF24),
                  KC_NO,   KC_NO,   KC_TRNS, MO(FF12), KC_TAB, KC_ENT
),

[FF12] = KEYMAP(
/*
F1 F2 F3 F4          ?? ?? ?? ??
F5 F5 F7 F8 ??    ?? sh gu al ct
F9 F0 11 12 ?? ?? ?? ?? ?? ?? ??
   xx xx xx XX    XX xx xx xx
*/
    KC_F1,   KC_F2,   KC_F3,                               KC_NO,   KC_NO,   KC_NO,
  KC_F5,   KC_F6,   KC_F7,   KC_F4,                 KC_NO,   KC_LGUI, KC_LALT, KC_LCTL,
KC_F9,   KC_F10,  KC_F11,  KC_F8,   KC_NO,   KC_NO,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,
             KC_NO,   KC_F12,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO
),

[FF24] = KEYMAP(
/*
13 14 15 16          ?? re ?? ?? -- reset
17 18 19 20 ??    ?? sh gu al ct
21 22 23 24 ?? ?? ?? ?? ?? ?? ??
   xx xx xx XX    xx xx xx XX   
*/
    KC_F13,  KC_F14,  KC_F15,                              RESET,   KC_NO,   KC_NO,
  KC_F17,  KC_F18,  KC_F19,  KC_F16,                KC_NO,   KC_LGUI, KC_LALT, KC_LCTL,
KC_F21,  KC_F22,  KC_F23,  KC_F20,  KC_NO,   KC_NO,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,
             KC_NO,   KC_F24,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_TRNS,
                  KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO
),

[NAVI] = KEYMAP(
/*
?? a0 a1 a2          wl wd wu wr -- mouse accel speeds
ct al gu sh ??    bs lt dn up rt
?? ?? ?? ?? ?? ?? de ml md mu mr
   ?? lc rc mc    xx XX xx xx    -- left click, right, middle
*/
    KC_NO,   KC_ACL0, KC_ACL1,                             KC_WH_D, KC_WH_U, KC_WH_R,
  KC_LCTL, KC_LALT, KC_LGUI, KC_ACL2,               KC_WH_L, KC_DOWN, KC_UP,   KC_RGHT,
KC_NO,   KC_NO,   KC_NO,   KC_LSFT, KC_NO,   KC_BSPC, KC_LEFT, KC_MS_D, KC_MS_U, KC_MS_R,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_DEL,  KC_MS_L, KC_NO,
                  KC_BTN1, KC_BTN2, KC_BTN3, KC_NO,   KC_TRNS, KC_NO
)
};

const uint16_t PROGMEM fn_actions[] = {

};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
