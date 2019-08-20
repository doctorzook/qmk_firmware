#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _MAC 1
#define _ALT 2
#define _SPCL 3
#define _RESET 4

enum custom_keycodes {
  WIN_MODE = SAFE_RANGE,
	MAC_MODE
};

#define _ENDASH 0x2013 // Unicode en-dash
#define _EMDASH 0x2014 // Unicode em-dash

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* Qwerty base layer.*/
		{ KC_ESC,   KC_1,    KC_2,      KC_3,    KC_4,    KC_5,    XXXXXXX,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
    { KC_TAB,   KC_Q,    KC_W,      KC_E,    KC_R,    KC_T,    XXXXXXX,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL  },
		{ KC_LCTL,  KC_A,    KC_S,      KC_D,    KC_F,    KC_G,    XXXXXXX,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
		{ KC_LSFT,  KC_Z,    KC_X,      KC_C,    KC_V,    KC_B,     KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
		{ KC_LCTL,  KC_LGUI, MO(_SPCL), KC_LALT, MO(_ALT),KC_BSPC,  KC_ENT,  KC_SPC,  MO(_ALT),KC_MINS, KC_QUOT, KC_EQL,  KC_RCTL }
},

[_MAC] = { /* This should layer on top of _DEFAULT to provide some customization, particularly for control keys. */
		{ _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ KC_LGUI, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ _______, KC_LALT, _______, KC_LGUI, _______, _______, _______,  _______, _______, _______, _______, _______, _______ }
},

[_ALT] = { /* Navigation and function keys, primarily. */
		{ KC_GRV,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX },
		{ XXXXXXX,       XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP },
		{ XXXXXXX,       KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  KC_PGDN },
		{ KC_LSFT,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX },
		{ XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DELT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  }
},

[_SPCL] = { /* Other alternative keys. Mode switching, unicode, and number pad. */
		{ TO(_DEFAULT), WIN_MODE, MAC_MODE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC(_ENDASH) },
		{ XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PAST, UC(_EMDASH) },
		{ XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX },
		{ XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX },
		{ MO(_RESET),   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,   KC_BSPC, KC_P0,   XXXXXXX, KC_PDOT, KC_PSLS, XXXXXXX }
},

[_RESET] = { /* To make flashing the keyboard easier, but not too easy to accidentally hit it. */
		{ TO(_DEFAULT),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
		{ XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
		{ XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
		{ XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
		{ XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET }
}

/* For future cut-and-paste convenience.
[_TRNS] = {
		{ _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
		{ _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ }
},
*/

};

void setWindowsMode(void) {
	// This Unicode input mode requires setting a registry key:
	// Key:   KEY_CURRENT_USER\Control Panel\Input Method\EnableHexNumpad
	// Type:  REG_SZ
	// Value: 1
	set_unicode_input_mode(UC_WIN);
	layer_off(_MAC);
}

void setMacMode(void) {
	// This Unicode input mode requires going to 
	//   System Preferences > Keyboard > Input Sources
	// Adding Unicode Hex Input to the list (it's under Other), and 
	// then activating it from the input dropdown in the Menu Bar.
	set_unicode_input_mode(UC_OSX);
	layer_on(_MAC);
}

// This is run at startup.S
void matrix_init_user(void) {
	setWindowsMode();
}

// This should be run on each keypress.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
		case WIN_MODE:
			if (record->event.pressed) {
				setWindowsMode();
			}
			return false; // Skip all further processing of this key
		case MAC_MODE:
			if (record->event.pressed) { 
				setMacMode();
			}
			return false;
    default:
      return true; // Process all other keycodes normally
  }
}
