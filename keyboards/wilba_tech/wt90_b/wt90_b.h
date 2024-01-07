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

#pragma once

#include "quantum.h"

#define ____ KC_NO

#define LAYOUT( \
    K000, K100, K001, K101, K002, K102, K003, K103, K004, K104, K005, K105, K006, K106, K007, K107, K008, K108, \
    K200, K300, K201, K301, K202, K302, K203, K303, K204, K304, K205, K305, K206, K306, K207, K307, K208, K308, \
    K400, K500, K401, K501, K402, K502, K403, K503, K404, K504, K405, K505, K406, K506, K407, K507, K408, K508, \
    K600, K700, K601, K701, K602, K702, K603, K703, K604, K704, K605, K705, K606,       K607, K707, K608, K708, \
    K800,       K801, K901, K802, K902, K803, K903, K804, K904, K805, K905, K806, K906, K807, K907, K808, K908, \
    KA00, KB00,                         KA03,                   KA05, KB05, KA06, KB06, KA07, KB07, KA08        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308 }, \
    { K400, K401, K402, K403, K404, K405, K406, K407, K408 }, \
    { K500, K501, K502, K503, K504, K505, K506, K507, K508 }, \
    { K600, K601, K602, K603, K604, K605, K606, K607, K608 }, \
    { K700, K701, K702, K703, K704, K705, ____, K707, K708 }, \
    { K800, K801, K802, K803, K804, K805, K806, K807, K808 }, \
    { ____, K901, K902, K903, K904, K905, K906, K907, K908 }, \
    { KA00, ____, ____, KA03, ____, KA05, KA06, KA07, KA08 }, \
    { KB00, ____, ____, ____, ____, KB05, KB06, KB07, ____ } \
}
