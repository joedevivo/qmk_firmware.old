/* Copyright 2019 Joe DeVivo
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

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
  L00, L01, L02, L03, L04,  L05,                          R05,  R04,  R03, R02, R01, R00, \
  L10, L11, L12, L13, L14,  L15,                          R15,  R14,  R13, R12, R11, R10, \
  L20, L21, L22, L23, L24,  L25,                          R25,  R24,  R23, R22, R21, R20, \
            L32, L33, LT00, LT01, LT10, LT11, RT11, RT10, RT01, RT00, R33, R32, \
                                  LT20, LT21, RT21, RT20 \
){ \
    {L00,   L01,   L02,  L03, L04,  L05,   LT10}, \
    {L10,   L11,   L12,  L13, L14,  L15,   LT11}, \
    {L20,   L21,   L22,  L23, L24,  L25,   LT20}, \
    {KC_NO, KC_NO, L32,  L33, LT00, LT01,  LT21}, \
    {KC_NO, KC_NO, R32,  R33, RT00, RT01,  RT21}, \
    {R20,   R21,   R22,  R23, R24,  R25,   RT20}, \
    {R10,   R11,   R12,  R13, R14,  R15,   RT11}, \
    {R00,   R01,   R02,  R03, R04,  R05,   RT10}, \
}
