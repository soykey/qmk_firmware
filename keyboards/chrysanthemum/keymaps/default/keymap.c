// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later


#include "action.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "analog.h"
// #include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │PgU│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent├───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │PgD│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │End│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │                        │Alt│ Fn│Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_NO,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,              KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_INT1, KC_8,
        KC_CAPS,                            KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_NUHS, KC_ENT,  KC_INT3,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),             KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Delete│   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │Ins│   │   │   │   │PSc│Scr│     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │Pau│    │   │
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
     * │    │   │   │   │   │   │   │   │Mut│Vl-│Vl+│   │      │   │   │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │   │   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [1] = LAYOUT(
        KC_GRV,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    _______,    KC_F9,    KC_F10,    KC_F11, KC_F12,  _______, _______,
        _______,  _______,              _______,    KC_MPLY,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______, KC_F8,
        _______,                            _______,    _______,    _______,    _______,    _______,    _______,    KC_QUOT,  _______, _______,  _______,
        _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______, _______,   _______,
        _______, _______, _______,                            _______,                    _______, MO(0),             _______, _______, _______
    )
};

int16_t s0[4] = {0, 1, 0, 1};
int16_t s1[4] = {0, 0, 1, 1};

uint16_t keys[4] = {KC_W, KC_A, KC_S, KC_D};

int16_t value[4] = {0, 0, 0, 0};
int16_t b_value[4] = {0, 0, 0, 0};
int16_t ap = 14;
int16_t diff = 3;
int16_t f[4] = {0, 0, 0, 0};

void matrix_init_user(void) {
    setPinOutput(GP21);
    setPinOutput(GP22);
    setPinOutput(GP26);
    writePinLow(GP26);
}

void matrix_scan_user(void) {

    for (int i = 0; i<4; i++) {
        // For 74hc4051 multiplexer
        if (s0[i] == 1) {
            writePinHigh(GP21);
        } else {
            writePinLow(GP21);

        }

        if (s1[i] == 1) {
            writePinHigh(GP22);
        } else {
            writePinLow(GP22);
        }


        // Read the value
        value[i] = analogReadPin(GP28)/10; // 18~180/10 = 1.8~18
        // uprintf("%d\n", value[i]);


        // Press and Release
        if (value[i] < ap && f[i] == 0) {
            register_code(keys[i]);
            f[i] = 1;
        }
        if (value[i] > ap && f[i] == 1) {
            unregister_code(keys[i]);
            f[i] = 0;
        }


        //Rapid Trigger
        if (value[i] - b_value[i] > diff && f[i] == 1) {
            unregister_code(keys[i]);
        }


        // Read the value
        b_value[i] = analogReadPin(GP28)/10;
    }
}


void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
