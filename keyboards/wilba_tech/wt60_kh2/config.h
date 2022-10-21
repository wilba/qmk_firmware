// Copyright 2022 Jason Williams (@wilba)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

// key matrix size
#define MATRIX_ROWS 11
#define MATRIX_COLS 8

// Keyboard Matrix Assignments
#define MATRIX_ROW_PINS { GP11, GP10, GP12, GP13, GP17, GP16, GP23, GP22, GP28, GP29, GP4 }
#define MATRIX_COL_PINS { GP5, GP14, GP15, GP21, GP20, GP18, GP19, GP27 }
#define DIODE_DIRECTION COL2ROW

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 5

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap 
#define LOCKING_SUPPORT_ENABLE

// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE

// Default to 10ms polling for compatibility
#define USB_POLLING_INTERVAL_MS 10

#ifdef RGB_MATRIX_ENABLE
#   define RGB_DI_PIN GP9
#   define DRIVER_LED_TOTAL 62
#   define RGBLED_NUM 62
#   define WS2812_PIO_USE_PIO1
#endif

#ifdef RGBLIGHT_ENABLE
#   define RGB_DI_PIN GP9
#   define RGBLED_NUM 62
#   define RGBLIGHT_ANIMATIONS
#   define WS2812_PIO_USE_PIO1
#endif
