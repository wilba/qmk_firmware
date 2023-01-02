

RGB_MATRIX_EFFECT(_effect_per_key_color)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "rgb_effects.h"

static bool _effect_per_key_color(effect_params_t* params) {
    return effect_per_key_color(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS