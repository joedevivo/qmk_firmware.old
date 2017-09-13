/*
Copyright 2016 Fred Sundvik <fsundvik@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

static const I2CConfig i2ccfg = {
  400000 // clock speed (Hz); 400kHz max for IS31
};

static const uint8_t led_mask[] = {
	0xFF, 0x00, /* C1-1 -> C1-16 */
	0xFF, 0x00, /* C2-1 -> C2-16 */
	0xFF, 0x00, /* C3-1 -> C3-16 */
	0xFF, 0x00, /* C4-1 -> C4-16 */
	0x3F, 0x00, /* C5-1 -> C5-16 */
	0x00, 0x00, /* C6-1 -> C6-16 */
	0x00, 0x00, /* C7-1 -> C7-16 */
	0x00, 0x00, /* C8-1 -> C8-16 */
	0x00, 0x00, /* C9-1 -> C9-16 */
};

// The address of the LED
#define LA(c, r) (c + r * 16 )

// The numbers in the comments are the led numbers DXX on the PCB
// The mapping is taken from the schematic of left hand side
static const uint8_t led_mapping[GDISP_SCREEN_HEIGHT][GDISP_SCREEN_WIDTH] = {
    { LA(0, 0), LA(1, 0), LA(2, 0), LA(3, 0), LA(4, 0), LA(5, 0), LA(6, 0), LA(7, 0), LA(8, 0), LA(9, 0), LA(10, 0), LA(11, 0), LA(12, 0), LA(13, 0), LA(14, 0), LA(15, 0)},
    { LA(0, 1), LA(1, 1), LA(2, 1), LA(3, 1), LA(4, 1), LA(5, 1), LA(6, 1), LA(7, 1), LA(8, 1), LA(9, 1), LA(10, 1), LA(11, 1), LA(12, 1), LA(13, 1), LA(14, 1), LA(15, 1)},
    { LA(0, 2), LA(1, 2), LA(2, 2), LA(3, 2), LA(4, 2), LA(5, 2), LA(6, 2), LA(7, 2), LA(8, 2), LA(9, 2), LA(10, 2), LA(11, 2), LA(12, 2), LA(13, 2), LA(14, 2), LA(15, 2)},
    { LA(0, 3), LA(1, 3), LA(2, 3), LA(3, 3), LA(4, 3), LA(5, 3), LA(6, 3), LA(7, 3), LA(8, 3), LA(9, 3), LA(10, 3), LA(11, 3), LA(12, 3), LA(13, 3), LA(14, 3), LA(15, 3)},
    { LA(0, 4), LA(1, 4), LA(2, 4), LA(3, 4), LA(4, 4), LA(5, 4), LA(6, 4), LA(7, 4), LA(8, 4), LA(9, 4), LA(10, 4), LA(11, 4), LA(12, 4), LA(13, 4), LA(14, 4), LA(15, 4)},
    { LA(0, 5), LA(1, 5), LA(2, 5), LA(3, 5), LA(4, 5), LA(5, 5), LA(6, 5), LA(7, 5), LA(8, 5), LA(9, 5), LA(10, 5), LA(11, 5), LA(12, 5), LA(13, 5), LA(14, 5), LA(15, 5)},
    { LA(0, 6), LA(1, 6), LA(2, 6), LA(3, 6), LA(4, 6), LA(5, 6), LA(6, 6), LA(7, 6), LA(8, 6), LA(9, 6), LA(10, 6), LA(11, 6), LA(12, 6), LA(13, 6), LA(14, 6), LA(15, 6)},
    { LA(0, 7), LA(1, 7), LA(2, 7), LA(3, 7), LA(4, 7), LA(5, 7), LA(6, 7), LA(7, 7), LA(8, 7), LA(9, 7), LA(10, 7), LA(11, 7), LA(12, 7), LA(13, 7), LA(14, 7), LA(15, 7)},
    { LA(0, 8), LA(1, 8), LA(2, 8), LA(3, 8), LA(4, 8), LA(5, 8), LA(6, 8), LA(7, 8), LA(8, 8), LA(9, 8), LA(10, 8), LA(11, 8), LA(12, 8), LA(13, 8), LA(14, 8), LA(15, 8)},
};


#define IS31_ADDR_DEFAULT 0x74 // AD connected to GND
#define IS31_TIMEOUT 5000

static GFXINLINE void init_board(GDisplay *g) {
    (void) g;
    /* I2C pins */
    palSetPadMode(GPIOB, 0, PAL_MODE_ALTERNATIVE_2); // PTB0/I2C0/SCL
    palSetPadMode(GPIOB, 1, PAL_MODE_ALTERNATIVE_2); // PTB1/I2C0/SDA
    palSetPadMode(GPIOB, 16, PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOB, 16);
    /* start I2C */
    i2cStart(&I2CD1, &i2ccfg);
    // try high drive (from kiibohd)
    I2CD1.i2c->C2 |= I2Cx_C2_HDRS;
    // try glitch fixing (from kiibohd)
    I2CD1.i2c->FLT = 4;
}

static GFXINLINE void post_init_board(GDisplay *g) {
	(void) g;
}

static GFXINLINE const uint8_t* get_led_mask(GDisplay* g) {
    (void) g;
    return led_mask;
}

static GFXINLINE uint8_t get_led_address(GDisplay* g, uint16_t x, uint16_t y)
{
    (void) g;
    return led_mapping[y][x];
}

static GFXINLINE void set_hardware_shutdown(GDisplay* g, bool shutdown) {
    (void) g;
    if(!shutdown) {
        palSetPad(GPIOB, 16);
    }
    else {
        palClearPad(GPIOB, 16);
    }
}

static GFXINLINE void write_data(GDisplay *g, uint8_t* data, uint16_t length) {
	(void) g;
	i2cMasterTransmitTimeout(&I2CD1, IS31_ADDR_DEFAULT, data, length, 0, 0, US2ST(IS31_TIMEOUT));
}

#endif /* _GDISP_LLD_BOARD_H */
