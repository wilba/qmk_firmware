
RGB_MATRIX_EFFECT(indicators_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool indicators_effect(effect_params_t* params) {
    HSV hsv = rgb_matrix_get_hsv();
    RGB rgb = hsv_to_rgb(hsv);
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
