#include QMK_KEYBOARD_H

extern uint8_t is_master;

#ifdef OLED_DRIVER_ENABLE
#define KEYLOGGER_LENGTH 5
static uint32_t oled_timer = 0;
static char keylog_str[KEYLOGGER_LENGTH + 1] = {"\n"};
// clang-format off
static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', ' ', ' ',  16, ' ', ' ', ' ',  // 4x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 5x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void add_keylog(uint16_t keycode);
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _THIRD 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  THIRD,
  ADJUST
};

#define KC________ KC_TRNS
#define KC____X___ KC_NO

#define KC_ALGUI LALT_T(KC_LGUI)
#define KC_LOCKW LGUI_T(KC_L)
#define KC_THENT LT(_THIRD, KC_ENT)
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_SNUHS S(KC_NUHS)
#define KC_SNUBS S(KC_NUBS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          TAB,       Q,       W,       E,       R,       T,                            Y,       U,       I,       O,      P,     BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         LCTL,       A,       S,       D,       F,       G,                            H,       J,       K,       L,    SCLN,    QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         LSFT,       Z,       X,       C,       V,       B,                            N,       M,    COMM,     DOT,    SLSH,    RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             ALGUI,  LOWER,     SPC,      THENT,  RAISE,     RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          ESC,    EXLM,      AT,    HASH,     DLR,    PERC,                         CIRC,    AMPR,    ASTR,    LPRN,    RPRN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, ___X___, ___X___, ___X___, ___X___, ___X___,                         MINS,     EQL,    LCBR,    RCBR,    PIPE,     GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    LOCK, ___X___, ___X___, ___X___, ___X___,                         UNDS,    PLUS,    LBRC,    RBRC,    BSLS,    TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          ESC,       1,       2,       3,       4,       5,                            6,       7,       8,       9,       0, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    HOME,    PGDN,    PGUP,     END, ___X___,                      ___X___,    LEFT,    DOWN,      UP,   RIGHT,     DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___,    COMM,     DOT, ___X___,     INS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [_THIRD] = LAYOUT_kc( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  )

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___,    MPRV,    MPLY,    MNXT,    MUTE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___X___,      F1,      F2,      F3,      F4,      F5,                           F6, ___X___, ___X___,   LOCKW, ___X___,    VOLU,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___X___,      F7,      F8,      F9,     F10,     F11,                          F12, ___X___, ___X___, ___X___, ___X___,    VOLD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_third_layer(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void add_keylog(uint16_t keycode) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
    keycode = keycode & 0xFF;
  } else if (keycode > 0xFF) {
    keycode = 0;
  }

  for (uint8_t i = (KEYLOGGER_LENGTH - 1); i > 0; --i) {
    keylog_str[i] = keylog_str[i - 1];
  }

  if (keycode < (sizeof(code_to_name) / sizeof(char))) {
    keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
  }
}

void render_keylogger_status(void) {
  oled_write_P(PSTR("Log: "), false);
  oled_write(keylog_str, false);
}

void render_layer_state(void) {
  oled_write_P(PSTR("Layer"), false);
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("  Sym"), layer_state_is(_LOWER) && !layer_state_is(_RAISE));
  oled_write_P(PSTR("  Num"), layer_state_is(_RAISE) && !layer_state_is(_LOWER));
  oled_write_P(PSTR("Third"), layer_state_is(_THIRD));
  oled_write_P(PSTR("   Fn"), layer_state_is(_ADJUST));
  oled_write_P(PSTR("-----"), false);
}

void render_mod_status(uint8_t modifiers) {
  oled_write_P(PSTR("Mods:"), false);
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
  oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
  oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
  oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    render_layer_state();
    oled_write_ln_P(PSTR("\n"), false);
    render_keylogger_status();
}

void render_status_secondary(void) {
    render_layer_state();
    oled_write_ln_P(PSTR("\n"), false);

    #ifdef NO_ACTION_ONESHOT
      render_mod_status(get_mods());
    #else
      render_mod_status(get_mods() | get_oneshot_mods());
    #endif
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
    #ifndef SPLIT_KEYBOARD
    else {
        oled_on();
    }
    #endif

    if (is_master) {
        render_status_main();
    } else {
        render_status_secondary();
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  #ifdef OLED_DRIVER_ENABLE
    oled_timer = timer_read32();
    add_keylog(keycode);
  #endif
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_third_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_third_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_third_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_third_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
  }
  return true;
}
