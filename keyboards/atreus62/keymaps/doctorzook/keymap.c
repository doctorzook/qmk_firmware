// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _MAC 1
#define _NAV 2
#define _RESET 3
#define _SPCL 4

enum custom_keycodes {
  IKK_TEST = SAFE_RANGE,
	IKK_WIN_MODE,
	IKK_MAC_MODE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* Qwerty base layer.*/
		{ KC_ESC,   KC_1,    KC_2,      KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
    { KC_TAB,   KC_Q,    KC_W,      KC_E,    KC_R,    KC_T,    KC_TRNS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL  },
		{ KC_LCTL,  KC_A,    KC_S,      KC_D,    KC_F,    KC_G,    KC_TRNS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
		{ KC_LSFT,  KC_Z,    KC_X,      KC_C,    KC_V,    KC_B,     KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
		{ KC_LCTL,  KC_LGUI, MO(_SPCL), KC_LALT, MO(_NAV),KC_BSPC,  KC_ENT,  KC_SPC,  MO(_NAV),KC_MINS, KC_QUOT, KC_EQL,  KC_RCTL }
},

[_MAC] = { /* This should layer on top of _DEFAULT to provide some customization, particularly for control keys. */
		{ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS, KC_LALT, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_NAV] = { 
		{ KC_GRV,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS },
		{ KC_TRNS,       KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP },
		{ KC_TRNS,       KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  KC_PGDN },
		{ KC_LSFT,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS },
		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_DELT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  }
},

[_SPCL] = {
		{ TO(_DEFAULT), IKK_WIN_MODE, IKK_MAC_MODE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC(8211) /* en-dash*/ },
		{ KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, UC(8212) /* em-dash*/ },
		{ KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_TRNS },
		{ KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_TRNS },
		{ MO(_RESET),   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PEQL,  KC_TRNS, KC_P0,   KC_TRNS, KC_PDOT, KC_PMNS, KC_TRNS }
},

// [_XXXDEFAULT] = { /* qwerty */
// 		{ KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
// 		{ KC_BSLS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC },
// 		{ KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
// 		{ KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DELT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC },
// 		{ KC_LCTL,  KC_LGUI, KC_LALT, KC_GRV,  MO(_NAV),KC_BSPC, KC_ENT,   KC_SPC,  KC_EQL,  KC_MINS, KC_QUOT, KC_ENT,  KC_RGUI }
// },
// 
// [_XXXNAV] = { 
// 		{ TO(_DEFAULT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
// 		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F12,  KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS },
// 		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS },
// 		{ TO(_RESET),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
// 		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
// },

[_RESET] = {
		{ TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
}


/*
[_TRNS] = {
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};


// IKK: So to be honest, I don't know what this does. I think it's old stuff from TMK; I may be able to remove it.
const uint16_t PROGMEM fn_actions[] = {

};

// IKK: This is an old way to define macros... which I'm not using in this layout. Should probably nix it. 
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
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
	set_unicode_input_mode(UC_OSX);
	layer_on(_MAC);
}

// This gets run at startup
void matrix_init_user(void) {
	setWindowsMode(); // Start off in Windows mode by default
}

// This should get run on each keypress.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case IKK_TEST:
      if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_T));
				SEND_STRING(SS_TAP(X_E));
				SEND_STRING("ST");
      } else {
        // NOP
      }
      return false; // Skip all further processing of this key
		case IKK_WIN_MODE:
			if (record->event.pressed) {
				setWindowsMode();
			}
			return false;
		case IKK_MAC_MODE:
			if (record->event.pressed) { 
				setMacMode();
			}
			return false;
    default:
      return true; // Process all other keycodes normally
  }
}
