
RGB_MATRIX_EFFECT(indicators_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    include "wt90_b.h"

// On the PCB, the first LED is the bottom one
// In the config, the first indicator is the top one
const uint8_t led_index_to_indicator_index[3] = {2, 1, 0};

static bool indicators_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        HSV hsv = get_indicator_color(led_index_to_indicator_index[i]);
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
