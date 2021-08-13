#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

#define LCGS(code) LCTL(LGUI(LSFT(code)))
#define LCS(code) LCTL(LSFT(code))
#define KC_NOBS KC_NONUS_BSLASH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,             KC_4,    KC_5,    KC_6,                 KC_7,         KC_8,    KC_9,    KC_0,    KC_MINS,           KC_EQL,         KC_BSPC,
  KC_TAB,          KC_Q,        KC_W,          KC_E,             KC_R,    KC_T,    KC_F3,                KC_7,         KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  KC_BSPC,         KC_A,        KC_S,          KC_D,             KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,              KC_SCLN,        KC_ENT,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,             KC_V,    KC_B,    KC_F4,                KC_7,         KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_UP,          KC_RSFT,
  KC_LCTL,         KC_LCMD,     KC_GRV,        KC_APPLICATION,   KC_LALT,                                                       KC_RALT, KC_SLSH, KC_LEFT,           KC_DOWN,        KC_RGHT,
                                                                   KC_F5, KC_F6,                  KC_F11, KC_F12,
                                                                          KC_F7,                  KC_F10,
                                                         KC_SPC, MO(1),   KC_F8,                  KC_F9, KC_DEL, MO(1)
),

[1] = LAYOUT_ergodox_pretty(
  // left hand
  _______, KC_F1,   KC_F2,   _______, _______, _______, _______,     _______, _______, _______,       _______,       _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, RALT(KC_LBRC), RALT(KC_RBRC), _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, KC_LBRC,       KC_RBRC,       _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, LSFT(KC_LBRC), LSFT(KC_RBRC), _______, _______, _______,
  _______, _______, _______, _______, _______,                                         KC_NOBS,       LSFT(KC_NOBS), _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),

[2] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
