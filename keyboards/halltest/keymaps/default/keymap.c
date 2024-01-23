// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.h"
#include <print.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_A,   KC_A,   KC_A,   KC_A,
        KC_A
    )
};

int16_t value;
int16_t b_value;
int f = 0;

void matrix_scan_user(void) {
    value = analogReadPin(GP26)/5;
    uprintf("%d\n",value - b_value);
    if (value < 12 && f == 0) {
        register_code(KC_A);
        f = 1;
    }
    if (value - b_value > 2 && f == 1) {
        unregister_code(KC_A);
    }
    if (value > 12 && f == 1) {
        unregister_code(KC_A);
        f = 0;
    }
    b_value = analogReadPin(GP26)/5;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
