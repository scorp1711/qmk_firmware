/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers { _QWERTY, _COLEMAK, _WORKMAN, _LOWER, _RAISE, _FUNC };

enum planck_keycodes { QWERTY = SAFE_RANGE, COLEMAK, WORKMAN };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FUNC)
#define ENTSHFT RSFT_T(KC_ENT)
#define ALTRLFT RALT_T(KC_LEFT)
#define CTLRDWN RCTL_T(KC_DOWN)
#define CTRLESC LCTL_T(KC_ESC)
#define CTRLDEL LCTL_T(KC_DEL)
#define EURO RALT(KC_5)
#define ___X___ XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  FN  | GUI  | Alt  |Lower |    Space    |Raise |AltLft|CtlDwn|  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, ENTSHFT,
        ___X___,   FN, KC_LALT, KC_LGUI,   LOWER,        KC_SPC,      RAISE, ALTRLFT, CTLRDWN,   KC_UP, KC_RGHT
    ),

    /* Colemak
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_COLEMAK] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
        CTRLESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, ENTSHFT,
        ___X___,   FN, KC_LALT, KC_LGUI,   LOWER,        KC_SPC,      RAISE, ALTRLFT, CTLRDWN,   KC_UP, KC_RGHT
    ),

        /* Workman
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_WORKMAN] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, KC_BSPC,
        CTRLESC, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH, ENTSHFT,
        ___X___,   FN, KC_LALT, KC_LGUI,   LOWER,        KC_SPC,      RAISE, ALTRLFT, CTLRDWN,   KC_UP, KC_RGHT
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CtlDel| Home | Pgdn | Pgup | End  |      |   -  |   =  |   {  |   }  |   |  |  `   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |   _  |   +  |   [  |   ]  |   \  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Home | Pgdn | Pgup | End  |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_BSPC,
        CTRLDEL, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, ___X___, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,
        _______, ___X___, ___X___, ___X___, ___X___, ___X___, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, _______,
        _______, _______, _______, _______, _______,      _______,     _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   €  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CtlDel| Home | Pgdn | Pgup | End  |      |      | Left | Down |  Up  |Right |  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |   ,  |   .  |   /  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Home | Pgdn | Pgup | End  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
           EURO,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
        CTRLDEL, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, ___X___, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_INS,
        _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_COMM,  KC_DOT, KC_SLSH, _______,
        _______, _______, _______, _______, _______,      _______,     _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END
    ),

    /* Function
     * ,-----------------------------------------------------------------------------------.
     * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |Qwerty|Colemk|      |      |      |      |  Pev | Vol- | Vol+ | Next |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      | Mute | Play |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |  Pev | Vol- | Vol+ | Next |
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNC] = LAYOUT_planck_mit(
          RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, ___X___,
        ___X___,  QWERTY, COLEMAK, WORKMAN, ___X___, ___X___, ___X___, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, ___X___,
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_MUTE, KC_MPLY,
        ___X___, ___X___, ___X___, ___X___, ___X___,      ___X___,     ___X___, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
    )

};

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORKMAN);
            }
            return false;
            break;
    }
    return true;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

void encoder_update(bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
            break;
        case _LOWER:
            clockwise ? tap_code16(G(KC_TAB)) : tap_code16(G(S(KC_TAB)));
            break;
        default:
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
