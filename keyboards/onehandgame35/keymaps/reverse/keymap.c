// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,
        KC_LCTL, KC_LGUI, KC_LALT, MO(1),   KC_SPC,  MO(2)
    ),
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,
        _______, _______, KC_UP  , _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
        _______, KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   _______,
        _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        KC_BSPC, KC_EQL, KC_MINS,  KC_0,    KC_9,     KC_8,    _______, _______,
        KC_BSLS, KC_RBRC, KC_LBRC, KC_P,    KC_O,     KC_I,    KC_U,
        KC_ENT,  KC_QUOT, KC_SCLN, KC_L,    KC_K,     KC_J,    _______,
        KC_RSFT, KC_SLSH, KC_DOT,  KC_COM,  KC_M,     _______, _______,
        _______, _______, _______, _______, _______,  _______
    )
};
