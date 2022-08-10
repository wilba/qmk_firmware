// Copyright 2022 Jason Williams (@wilba)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "wt75_c2.h"

bool g_first_execution = false;

// This is some magic so that PCBs flashed with VIA firmware at the factory
// will start with an RGB test pattern. Not relevant for non-VIA firmware.
#ifdef VIA_ENABLE

// Called from via_init() if VIA_ENABLE
// Called from matrix_init_kb() if not VIA_ENABLE
void via_init_kb(void)
{
    // If the EEPROM has the magic, the data is good.
    // OK to load from EEPROM
    if (via_eeprom_is_valid()) {
    } else	{
        // Cache "first execution" state so we can do something
        // specific after QMK initialization has done its thing.
        g_first_execution = true;
        // DO NOT set EEPROM valid here, let caller do this
    }
}

void keyboard_post_init_kb() {
    // This is a workaround to ensure "EEPROM cleared" PCBs will
    // start with the RGB test mode, essential for testing LEDs.
    if ( g_first_execution ) {
        rgblight_mode(RGBLIGHT_MODE_RGB_TEST);
    }
}

#endif // VIA_ENABLE
