// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi(
        // 0    1       2       3       4        5          6           7           8           9       10      11          12          13          14
/*0*/   KC_Q,   KC_W,   KC_R,   KC_U,   KC_NO,   KC_NO,     KC_NO,      KC_I,       KC_NO,      KC_O,   KC_E,   KC_P,       KC_NO,      KC_SCRL,    QK_BOOT,
/*1*/   KC_NO,  KC_NO,  KC_B,   KC_N,   KC_DOWN, KC_RIGHT,  KC_F12,     KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_SLSH,    KC_LEFT,    KC_NO,      KC_NO,
/*2*/   KC_Z,   KC_X,   KC_V,   KC_M,   KC_NO,   KC_NO,     KC_ENT,     KC_COMM,    KC_NO,      KC_DOT, KC_C,   KC_NO,      KC_RSFT,    KC_NO,      KC_RCTL,
/*3*/   KC_1,   KC_2,   KC_4,   KC_7,   KC_NO,   KC_NO,     KC_F10,     KC_8,       KC_PGDN,    KC_9,   KC_3,   KC_0,       KC_END,     KC_PSCR,    KC_F5,
/*4*/   KC_GRV, KC_F1,  KC_5,   KC_6,   KC_DEL,  KC_INS,    KC_F9,      KC_EQL,     KC_PGUP,    KC_F8,  KC_F2,  KC_MINS,    KC_HOME,    KC_NO,      KC_LCTL,
/*5*/   KC_A,   KC_S,   KC_F,   KC_J,   KC_NO,   KC_NO,     KC_BSLS,    KC_K,       KC_NO,      KC_L,   KC_D,   KC_SCLN,    KC_NO,      KC_RALT,    KC_NO,
/*6*/   KC_ESC, KC_NO,  KC_G,   KC_H,   KC_SPC,  KC_NO,     KC_F11,     KC_F6,      KC_NO,      KC_NO,  KC_F4,  KC_QUOT,    KC_UP,      KC_LGUI,    KC_NO,
/*7*/   KC_TAB, KC_CAPS,KC_T,   KC_Y,   KC_NO,   KC_NO,     KC_BSPC,    KC_RBRC,    KC_NO,      KC_F7,  KC_F3,  KC_LBRC,    KC_LSFT,    KC_NO,      KC_LALT
    ),
};

