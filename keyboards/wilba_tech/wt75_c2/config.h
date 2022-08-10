// Copyright 2022 Jason Williams (@wilba)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID       0x6582 // wilba.tech
#define PRODUCT_ID      0x0032 // PCB #50
#define DEVICE_VER      0x0001
#define MANUFACTURER    wilba.tech
// "C2" in PRODUCT would be expanded to "((0x6 << 4) | 2)"
// because it's a pin definition. Fixed by using
// character literals. 
#define PRODUCT         wilba.tech WT75-\x43\x32

// key matrix size
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

// Keyboard Matrix Assignments
#define MATRIX_ROW_PINS { F1, F0, E6, F4, F6, F7 }
#define MATRIX_COL_PINS { F5, D5, B1, B2, B3, D3, D2, C7, C6, B6, B5, B4, D7, D6, B7, D4 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 5

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE

// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE

// RGBLIGHT configuation
#define RGB_DI_PIN B0
#ifdef RGB_DI_PIN
   #define RGBLED_NUM 4
   #define RGBLIGHT_HUE_STEP 8
   #define RGBLIGHT_SAT_STEP 8
   #define RGBLIGHT_VAL_STEP 8
   #define RGBLIGHT_ANIMATIONS
#endif
