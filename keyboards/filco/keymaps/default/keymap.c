// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// clang-format off
/*
┌─────┐       ┌─────┐┌─────┐┌─────┐┌─────┐    ┌─────┐┌─────┐┌─────┐┌─────┐    ┌─────┐┌─────┐┌─────┐┌─────┐ ┌─────┐┌─────┐┌─────┐
│ Esc │       │ F1  ││ F2  ││ F3  ││ F4  │    │ F5  ││ F6  ││ F7  ││ F8  │    │ F9  ││ F10 ││ F11 ││ F12 │ │PrtSc││ScrLc││Pause│
│ 6,0 │       │ 4,1 ││4,10 ││7,10 ││6,10 │    │3,14 ││ 6,7 ││ 7,9 ││ 4,9 │    │ 4,6 ││ 3,6 ││ 6,6 ││ 1,6 │ │3,13 ││0,13 ││0,14 │
└─────┘       └─────┘└─────┘└─────┘└─────┘    └─────┘└─────┘└─────┘└─────┘    └─────┘└─────┘└─────┘└─────┘ └─────┘└─────┘└─────┘

┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────────────┐ ┌─────┐┌─────┐┌─────┐
│  `  ││  1  ││  2  ││  3  ││  4  ││  5  ││  6  ││  7  ││  8  ││  9  ││  0  ││  -  ││  =  ││Backspace    │ │ Ins ││Home ││PgUp │
│ 4,0 ││ 3,0 ││ 3,1 ││ 3,10││ 3,2 ││ 4,2 ││ 4,3 ││ 3,3 ││ 3,7 ││ 3,9 ││ 3,11││ 4,11││ 4,7 ││   7,6       │ │ 4,5 ││ 4,12││ 4,8 │
└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────────────┘ └─────┘└─────┘└─────┘
┌─────────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────────┐ ┌─────┐┌─────┐┌─────┐
│Tab      ││  Q  ││  W  ││  E  ││  R  ││  T  ││  Y  ││  U  ││  I  ││  O  ││  P  ││  [  ││  ]  ││\        │ │ Del ││ End ││PgDn │
│7,0      ││ 0,0 ││ 0,1 ││ 0,10││ 0,2 ││ 7,2 ││ 7,3 ││ 0,3 ││ 0,7 ││ 0,9 ││ 0,11││ 7,11││ 7,7 ││ 5,6     │ │ 4,4 ││ 3,12││ 3,8 │
└─────────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────────┘ └─────┘└─────┘└─────┘
┌───────────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌──────────────┐
│Caps Lock  ││  A  ││  S  ││  D  ││  F  ││  G  ││  H  ││  J  ││  K  ││  L  ││  ;  ││  '  ││Enter         │
│7,1        ││ 5,0 ││ 5,1 ││ 5,10││ 5,2 ││ 6,2 ││ 6,3 ││ 5,3 ││ 5,7 ││ 5,9 ││ 5,11││ 6,11││2,6           │
└───────────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└──────────────┘
┌───────────────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────┐┌─────────────────┐        ┌─────┐
│Shift          ││  Z  ││  X  ││  C  ││  V  ││  B  ││  N  ││  M  ││  ,  ││  .  ││  /  ││Shift            │        │  ↑  │
│7,12           ││ 2,0 ││ 2,1 ││ 2,10││ 2,2 ││ 1,2 ││ 1,3 ││ 2,3 ││ 2,7 ││ 2,9 ││ 1,11││2,12             │        │ 6,12│
└───────────────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────┘└─────────────────┘        └─────┘
┌───────┐┌───────┐┌───────┐┌─────────────────────────────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐ ┌─────┐┌─────┐┌─────┐
│Control││Option ││Command││                  Space                  ││Command││Option ││Menu   ││Control│ │  ←  ││  ↓  ││  →  │
│4,14   ││7,14   ││6,13   ││                   6,4                   ││1,13   ││5,13   ││1,9    ││2,14   │ │ 1,12││ 1,4 ││ 1,5 │
└───────┘└───────┘└───────┘└─────────────────────────────────────────┘└───────┘└───────┘└───────┘└───────┘ └─────┘└─────┘└─────┘

    0       1       2       3       4        5          6           7           8           9       10      11          12          13          14
0   KC_Q,   KC_W,   KC_R,   KC_U,   KC_NO,   KC_NO,     KC_NO,      KC_I,       KC_NO,      KC_O,   KC_E,   KC_P,       KC_NO,      KC_SCRL,    KC_PAUS,
1   KC_NO,  KC_NO,  KC_B,   KC_N,   KC_DOWN, KC_RIGHT,  KC_F12,     KC_NO,      KC_NO,      QK_BOOT,KC_NO,  KC_SLSH,    KC_LEFT,    KC_RGUI,    KC_NO,
2   KC_Z,   KC_X,   KC_V,   KC_M,   KC_NO,   KC_NO,     KC_ENT,     KC_COMM,    KC_NO,      KC_DOT, KC_C,   KC_NO,      KC_RSFT,    KC_NO,      KC_RCTL,
3   KC_1,   KC_2,   KC_4,   KC_7,   KC_NO,   KC_NO,     KC_F10,     KC_8,       KC_PGDN,    KC_9,   KC_3,   KC_0,       KC_END,     KC_PSCR,    KC_F5,
4   KC_GRV, KC_F1,  KC_5,   KC_6,   KC_DEL,  KC_INS,    KC_F9,      KC_EQL,     KC_PGUP,    KC_F8,  KC_F2,  KC_MINS,    KC_HOME,    KC_NO,      KC_LCTL,
5   KC_A,   KC_S,   KC_F,   KC_J,   KC_NO,   KC_NO,     KC_BSLS,    KC_K,       KC_NO,      KC_L,   KC_D,   KC_SCLN,    KC_NO,      KC_RALT,    KC_NO,
6   KC_ESC, KC_NO,  KC_G,   KC_H,   KC_SPC,  KC_NO,     KC_F11,     KC_F6,      KC_NO,      KC_NO,  KC_F4,  KC_QUOT,    KC_UP,      KC_LGUI,    KC_NO,
7   KC_TAB, KC_CAPS,KC_T,   KC_Y,   KC_NO,   KC_NO,     KC_BSPC,    KC_RBRC,    KC_NO,      KC_F7,  KC_F3,  KC_LBRC,    KC_LSFT,    KC_NO,      KC_LALT
*/
enum layers {
    MAIN,
    UTILS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAIN] = LAYOUT_tkl_ansi(
//    0            1            2            3            4            5            6            7            8            9            10           11           12           13           14
/*0*/ KC_Q,        KC_W,        KC_R,        KC_U,        KC_NO,       KC_NO,       KC_NO,       KC_I,        KC_NO,       KC_O,        KC_E,        KC_P,        KC_NO,       DM_PLY1,     DM_PLY2,
/*1*/ KC_NO,       KC_NO,       KC_B,        KC_N,        KC_DOWN,     KC_RIGHT,    KC_F12,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_SLSH,     KC_LEFT,     KC_RGUI,     KC_NO,
/*2*/ KC_Z,        KC_X,        KC_V,        KC_M,        KC_NO,       KC_NO,       KC_ENT,      KC_COMM,     KC_NO,       KC_DOT,      KC_C,        KC_NO,       QK_LEAD,     KC_NO,       KC_RCTL,
/*3*/ KC_1,        KC_2,        KC_4,        KC_7,        KC_NO,       KC_NO,       KC_F10,      KC_8,        KC_PGDN,     KC_9,        KC_3,        KC_0,        KC_END,      KC_PSCR,     KC_F5,
/*4*/ KC_GRV,      KC_F1,       KC_5,        KC_6,        KC_DEL,      KC_INS,      KC_F9,       KC_EQL,      KC_PGUP,     KC_F8,       KC_F2,       KC_MINS,     KC_HOME,     KC_NO,       KC_LCTL,
/*5*/ KC_A,        KC_S,        KC_F,        KC_J,        KC_NO,       KC_NO,       KC_BSLS,     KC_K,        KC_NO,       KC_L,        KC_D,        KC_SCLN,     KC_NO,       KC_RALT,     KC_NO,
/*6*/ KC_ESC,      KC_NO,       KC_G,        KC_H,        KC_SPC,      KC_NO,       KC_F11,      KC_F6,       KC_NO,       KC_NO,       KC_F4,       KC_QUOT,     KC_UP,       KC_LGUI,     KC_NO,
/*7*/ KC_TAB,      MO(1),       KC_T,        KC_Y,        KC_NO,       KC_NO,       KC_BSPC,     KC_RBRC,     KC_NO,       KC_F7,       KC_F3,       KC_LBRC,     KC_LSFT,     KC_NO,       KC_LALT
),
[UTILS] = LAYOUT_tkl_ansi(
//    0            1            2            3            4            5            6            7            8            9            10           11           12           13           14
/*0*/ KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     DM_REC1,     DM_REC2,
/*1*/ KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     MS_DOWN,     MS_RGHT,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     MS_LEFT,     KC_TRNS,     KC_TRNS,
/*2*/ KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_MPLY,     KC_MPRV,     KC_TRNS,     KC_MNXT,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
/*3*/ KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_MUTE,     KC_TRNS,     KC_TRNS,     KC_TRNS,
/*4*/ KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_VOLU,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_VOLD,     KC_TRNS,     KC_TRNS,     KC_TRNS,
/*5*/ KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_BSPC,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
/*6*/ QK_BOOT,     KC_TRNS,     KC_TRNS,     KC_TRNS,     MS_BTN1,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     MS_UP,       KC_TRNS,     KC_TRNS,
/*7*/ KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_LALT
),
};

// clang-format on

void keyboard_pre_init_user(void) {
    // Set our LED pins as output
    setPinOutput(GP14);
    setPinOutput(GP2);
}

void keyboard_post_init_user(void) {
    gpio_write_pin(GP14, false);
    gpio_write_pin(GP2, false);
}

// SHIFT OVERRIDES
const key_override_t shift_left_override = ko_make_with_layers(MOD_MASK_SHIFT,       // when Shift is held
                                                               MS_LEFT,              // and you press the MS_LEFT key
                                                               QK_MOUSE_WHEEL_RIGHT, // send mouse wheel left instead
                                                               (1 << UTILS)          // only apply on UTILS layer
);

const key_override_t shift_right_override = ko_make_with_layers(MOD_MASK_SHIFT, MS_RGHT, QK_MOUSE_WHEEL_LEFT, (1 << UTILS));

const key_override_t shift_up_override = ko_make_with_layers(MOD_MASK_SHIFT, MS_UP, QK_MOUSE_WHEEL_DOWN, (1 << UTILS));

const key_override_t shift_down_override = ko_make_with_layers(MOD_MASK_SHIFT, MS_DOWN, QK_MOUSE_WHEEL_UP, (1 << UTILS));

// Put them into the override array:
const key_override_t *key_overrides[] = {
    &shift_left_override,
    &shift_right_override,
    &shift_up_override,
    &shift_down_override,
    NULL, // terminator
};


bool dynamic_macro_record_start_user(int8_t direction) {
    gpio_write_pin(GP2, true);
    return true;
}

bool dynamic_macro_record_end_user(int8_t direction) {
    gpio_write_pin(GP2, false);
    return true;
}


void leader_start_user(void) {
    gpio_write_pin(GP14, true);
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_Y)) {
        // Leader, f => Types the below string
        SEND_STRING(SS_LGUI("c"));
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LGUI("a") SS_LGUI("x"));
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }

    gpio_write_pin(GP14, false);
}
