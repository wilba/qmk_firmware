/* Copyright 2020 Jason Williams (Wilba)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "wt60_kh2.h"

#ifdef RGB_MATRIX_ENABLE

// Physical position to LED index
//  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14
// 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15
// 29, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42
// 30, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43
// 55, 56, 57, 58, 59, 60, 61

led_config_t g_led_config = { {
    // Key matrix to LED Index
    {      0,      2,      4,      6,      8,     10,     12, NO_LED },
    {      1,      3,      5,      7,      9,     11,     13, NO_LED },
    {     28,     26,     24,     22,     20,     18,     16, NO_LED },
    {     27,     25,     23,     21,     19,     17,     15, NO_LED },
    { NO_LED,     32,     34,     36,     38,     40,     42, NO_LED },
    {     31,     33,     35,     37,     39,     41,     14, NO_LED },
    { NO_LED,     54,     52,     50,     48,     46,     44,     30 },
    { NO_LED,     53,     51,     49,     47,     45,     43, NO_LED },
    { NO_LED,     56, NO_LED,     58, NO_LED,     60, NO_LED, NO_LED },
    { NO_LED, NO_LED,     57,     59, NO_LED,     61, NO_LED,     55 },
    {     29, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
    // LED Index to Physical Position
    { 0, 0 },
    { 16, 0 },
    { 32, 0 },
    { 48, 2 },
    { 63, 4 },
    { 80, 7 },
    { 96, 8 },
    { 113, 7 },
    { 130, 5 },
    { 146, 3 },
    { 161, 1 },
    { 177, 0 },
    { 193, 0 },
    { 208, 0 },
    { 224, 0 },
    { 220, 14 },
    { 201, 14 },
    { 185, 14 },
    { 169, 14 },
    { 153, 16 },
    { 138, 18 },
    { 121, 20 },
    { 104, 21 },
    { 88, 21 },
    { 71, 19 },
    { 55, 17 },
    { 39, 15 },
    { 23, 14 },
    { 4, 14 },
    { 6, 28 },
    { 10, 41 },
    { 28, 28 },
    { 44, 29 },
    { 59, 32 },
    { 75, 34 },
    { 92, 35 },
    { 109, 35 },
    { 125, 34 },
    { 142, 32 },
    { 157, 29 },
    { 173, 28 },
    { 189, 28 },
    { 214, 28 },
    { 224, 41 },
    { 203, 41 },
    { 181, 41 },
    { 165, 42 },
    { 150, 44 },
    { 133, 47 },
    { 117, 48 },
    { 100, 49 },
    { 84, 48 },
    { 68, 47 },
    { 51, 44 },
    { 36, 42 },
    { 23, 55 },
    { 44, 57 },
    { 73, 62 },
    { 100, 64 },
    { 132, 61 },
    { 165, 57 },
    { 185, 55 },
}, {
    // LED Index to Flag
    // Mod keys on 0, 15, 28, 29, 30, 42, 43, 44, 55, 56, 60, 61
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 1, 1, 1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1, 1, 4, 4, 4,
    1, 1,
} };
    
#endif
