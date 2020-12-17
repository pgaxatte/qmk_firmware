#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum layers {
    BASE, // default layer
    NMOD, // default layer without the modifiers
    SYMB, // symbols
    MDIA, // media keys
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN
};

// Mod tap keys
#define LSFT2 LSFT_T(KC_A)
#define LCTL2 LCTL_T(KC_Z)
#define LALT2 LALT_T(KC_X)
#define LL1   LT(SYMB, KC_V)
#define LL2   LT(MDIA, KC_B)

#define RSFT2 RSFT_T(KC_SCLN)
#define RCTL2 RCTL_T(KC_SLSH)
#define RALT2 RALT_T(KC_DOT)
#define RL1   LT(SYMB, KC_M)
#define RL2   LT(MDIA, KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0: default
    // left hand
    DF(NMOD), KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   TO(SYMB),
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_MINS,
    KC_TAB,   LSFT2,   KC_S,    KC_D,    KC_F,   KC_G,
    KC_LSFT,  LCTL2,   LALT2,   KC_C,    LL1,    LL2,    KC_LBRC,
    KC_LCTL,  KC_LWIN, KC_LEFT, KC_RGHT, KC_LALT,

                                                  KC_NO, MO(SYMB),
                                                         KC_HOME,
                                         KC_SPC, KC_ENT, KC_END,
    // right hand
    TO(MDIA), KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_EQL,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
              KC_H,   KC_J,    KC_K,    KC_L,    RSFT2,   KC_QUOT,
    KC_RBRC,  RL2,    RL1,     KC_COMM, RALT2,   RCTL2,   KC_RSFT,
                      KC_RALT, KC_UP,   KC_DOWN, KC_RWIN, KC_RCTL,

    MO(MDIA), KC_PSCR,
    KC_PGUP,
    KC_PGDN, KC_DEL, KC_BSPC
),
[NMOD] = LAYOUT_ergodox( // layout 1: base without modifiers
    // left hand
    DF(BASE), KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   TO(SYMB),
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_MINS,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_LBRC,
    KC_LCTL,  KC_LWIN, KC_LEFT, KC_RGHT, KC_LALT,

                                                  KC_NO, MO(SYMB),
                                                         KC_HOME,
                                         KC_SPC, KC_ENT, KC_END,
    // right hand
    TO(MDIA), KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_EQL,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
              KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_RBRC,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_RALT, KC_UP,   KC_DOWN, KC_RWIN, KC_RCTL,

    MO(MDIA), KC_PSCR,
    KC_PGUP,
    KC_PGDN, KC_DEL, KC_BSPC
    ),
[SYMB] = LAYOUT_ergodox( // layer 2: symbols
    // left hand
    KC_NO,   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TO(BASE),
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                       KC_TRNS, KC_TRNS,
                                                KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    TO(MDIA), KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGUP, KC_F12,
              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, DEBUG,
    KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   VRSN,
                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,

    KC_NO,    KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),
[MDIA] = LAYOUT_ergodox( // layout 3: media
     // left hand
    KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, TO(SYMB),
    KC_BRIU, KC_NO,   KC_UP,   KC_NO,    KC_NO,   KC_NO,   KC_TRNS,
    KC_BRID, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,   KC_NO,
      KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_TRNS,
      KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,

                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    TO(BASE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,
    KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLU,
              KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_NO,   KC_VOLD,
    KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

    KC_NO,   KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_led_all_off();
};

// Set the LED in function of the selected layer
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
        case BASE:
        case NMOD:
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
        case SYMB:
            ergodox_right_led_2_on();
            ergodox_right_led_3_off();
            break;
        case MDIA:
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            break;
    }

    return state;
};

// Set the LED in function of the selected base layer
layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
        case BASE:
            ergodox_right_led_1_off();
            break;
        case NMOD:
            ergodox_right_led_1_on();
            break;
    }
    return state;
}
