// Copyright 2023 Jason Williams (@wilba)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#include "wt90_b.h"

// #ifdef VIA_ENABLE

typedef struct PACKED {
    uint8_t h;
    uint8_t s;
} HS;

enum indicator_state { indicator_state_always_on = 0, indicator_state_num_lock = 1, indicator_state_caps_lock = 2, indicator_state_scroll_lock = 3 };

typedef struct {
    uint8_t indicator_state[3];
    HS      indicator_color[3];
} wt90_b_config; // 9 bytes

wt90_b_config g_config = {.indicator_state = {0, 0, 0}, .indicator_color = {{0, 0}, {0, 0}, {0, 0}}};

// Callback from the RGB Matrix effect.
HSV get_indicator_color(uint8_t index) {
    HSV hsv = rgb_matrix_get_hsv();
    if (index <= 2) {
        HS hs   = g_config.indicator_color[index];
        hsv.h   = hs.h;
        hsv.s   = hs.s;
        bool on = g_config.indicator_state[index] == indicator_state_always_on || (g_config.indicator_state[index] == indicator_state_num_lock && host_keyboard_led_state().num_lock) || (g_config.indicator_state[index] == indicator_state_caps_lock && host_keyboard_led_state().caps_lock) || (g_config.indicator_state[index] == indicator_state_scroll_lock && host_keyboard_led_state().scroll_lock);
        hsv.v   = on ? hsv.v : 0;
    }
    return hsv;
}

enum wt90_b_config_value { id_indicator_state = 1, id_indicator_color = 2 };

void config_load(void) {
    eeprom_read_block(&g_config, ((void *)VIA_EEPROM_CUSTOM_CONFIG_ADDR), VIA_EEPROM_CUSTOM_CONFIG_SIZE);
}

void config_save(void) {
    eeprom_update_block(&g_config, ((void *)VIA_EEPROM_CUSTOM_CONFIG_ADDR), VIA_EEPROM_CUSTOM_CONFIG_SIZE);
}

void config_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_indicator_state: {
            uint8_t index = value_data[0];
            if (index >= 0 && index <= 2) {
                g_config.indicator_state[index] = value_data[1];
            }
            break;
        }
        case id_indicator_color: {
            uint8_t index = value_data[0];
            if (index >= 0 && index <= 2) {
                g_config.indicator_color[index].h = value_data[1];
                g_config.indicator_color[index].s = value_data[2];
            }
            break;
        }
        default:
            break;
    }
}

void config_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_indicator_state: {
            uint8_t index = value_data[0];
            if (index >= 0 && index <= 2) {
                value_data[1] = g_config.indicator_state[index];
            }
            break;
        }
        case id_indicator_color: {
            uint8_t index = value_data[0];
            if (index >= 0 && index <= 2) {
                value_data[1] = g_config.indicator_color[index].h;
                value_data[2] = g_config.indicator_color[index].s;
            }
            break;
        }
        default:
            break;
    }
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if (*channel_id == 0) {
        switch (*command_id) {
            case id_custom_set_value: {
                config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value: {
                config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save: {
                config_save();
                break;
            }
            default: {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    } else {
        *command_id = id_unhandled;
    }

    // DO NOT call raw_hid_send(data,length) here, let caller do this
}

void via_init_kb(void) {
    // This checks both an EEPROM reset (from bootmagic lite, keycodes)
    // and also firmware build date (from via_eeprom_is_valid())
    if (eeconfig_is_enabled()) {
        config_load();
    } else {
        config_save();
        // DO NOT set EEPROM valid here, let caller do this
    }
}

// #endif // VIA_ENABLE
