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
    K000, K100, K001, K101, K002, K102, K003, K103, K004, K104, K005, K105, K006, K106, K506, \
    K200, K300, K201, K301, K202, K302, K203, K303, K204, K304, K205, K305, K206, K306,       \
    KA00, K500, K401, K501, K402, K502, K403, K503, K404, K504, K405, K505, K406,             \
    K607,       K601, K701, K602, K702, K603, K703, K604, K704, K605, K705, K606, K706,       \
          K907, K801,             K902, K803, K903,             K805, K905                    \
) { \
    { K000, K001, K002, K003, K004, K005, K006, ____ }, \
    { K100, K101, K102, K103, K104, K105, K106, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, ____ }, \
    { ____, K401, K402, K403, K404, K405, K406, ____ }, \
    { K500, K501, K502, K503, K504, K505, K506, ____ }, \
    { ____, K601, K602, K603, K604, K605, K606, K607 }, \
    { ____, K701, K702, K703, K704, K705, K706, ____ }, \
    { ____, K801, ____, K803, ____, K805, ____, ____ }, \
    { ____, ____, K902, K903, ____, K905, ____, K907 }, \
    { KA00, ____, ____, ____, ____, ____, ____, ____ } \
}
