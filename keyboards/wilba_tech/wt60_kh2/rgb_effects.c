#include "rgb_effects.h"
#include "rgb_matrix.h"
#include "eeprom.h"

// Store the colors at the start of custom EEPROM memory
#define PER_KEY_COLOR_EEPROM_ADDR (VIA_EEPROM_CUSTOM_CONFIG_ADDR)

typedef struct PACKED {
    uint8_t h;
    uint8_t s;
} HS;

enum custom_value {
    id_color        = 1,
};

// TODO: promote this to struct with other parameters
HS g_per_key_color[RGB_MATRIX_LED_COUNT];

void set_per_key_color(uint8_t i, HS color) {
    if ( i < RGB_MATRIX_LED_COUNT ) {
        g_per_key_color[i] = color;
    }
}

HS get_per_key_color(uint8_t i) {
    if ( i < RGB_MATRIX_LED_COUNT ) {
        return g_per_key_color[i];
    }
    return g_per_key_color[RGB_MATRIX_LED_COUNT-1];
}

bool effect_per_key_color(effect_params_t* params) {
    if ( params->init ) {

    }
    for ( int i=0; i<RGB_MATRIX_LED_COUNT; i++ ) {
        HSV hsv;
        hsv.h = g_per_key_color[i].h;
        hsv.s = g_per_key_color[i].s;
        hsv.v = rgb_matrix_config.hsv.v;
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return false;
}

void custom_command(uint8_t *data, uint8_t length);
void custom_get_value(uint8_t *data);
void custom_set_value(uint8_t *data);

// Override to handle commands on channel 0
void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id = &(data[0]);
    uint8_t *channel_id = &(data[1]);

    if (*channel_id == id_custom_channel) {
        custom_command(data, length);
        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;
}

void custom_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);

    switch (*command_id) {
        case id_custom_set_value: {
            custom_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            custom_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            custom_save();
            break;
        }
        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

void custom_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_color: {
            uint8_t start_index = value_data[0];
            uint8_t count = MIN(value_data[1], 13);
            for ( int i = 0; i < count; i++ ) {
                HS hs = get_per_key_color(start_index + i);
                value_data[i * 2 + 2] = hs.h;
                value_data[i * 2 + 3] = hs.s;
            }
            break;
        }
    }
}

void custom_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_color: {
            uint8_t start_index = value_data[0];
            uint8_t count = MIN(value_data[1], 13);
            for ( int i = 0; i < count; i++ ) {
                HS hs;
                hs.h = value_data[i * 2 + 2];
                hs.s = value_data[i * 2 + 3];
                set_per_key_color(start_index + i, hs);
            }
            break;
        }
    }
}

void custom_init(void)
{
    for ( int i=0; i<RGB_MATRIX_LED_COUNT; i++ ) {
        g_per_key_color[i].h = rand() & 0xFF;
        g_per_key_color[i].s = 0xFF;
    }
}

void custom_load(void)
{
    eeprom_read_block( (void*)g_per_key_color, ((void*)PER_KEY_COLOR_EEPROM_ADDR), RGB_MATRIX_LED_COUNT * 2 );
}

void custom_save(void)
{
    eeprom_update_block( (void*)g_per_key_color, ((void*)PER_KEY_COLOR_EEPROM_ADDR), RGB_MATRIX_LED_COUNT * 2 );
}
