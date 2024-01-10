// Copyright 2023 Jason Williams (@wilba)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_MATRIX_LED_COUNT 3
#define RGB_MATRIX_LED_PROCESS_LIMIT 3
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_CENTER { 0, 16 }
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL

#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 1
