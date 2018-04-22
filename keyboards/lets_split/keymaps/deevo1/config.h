#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* Use I2C or Serial, not both
 * Since you went with RGB underglow, you don't have
 * enough wires to use I2C. Serial is fine.
 */
#define USE_SERIAL
//#define USE_I2C

/* Select hand configuration:
 * This is coming to you with EE_HANDS set, which means that no
 * matter which USB cable you plug in, the keymapping will be correct.
 *
 * MASTER_LEFT would make it so that when you plug in on the right half, the
 * entire keymap is mirrored, with the top right key being `tab`.
 *
 * Another issue with RGB underglow, is that the data all flows in one
 * direction. From the controller to LED1...N. It's been soldered to run left
 * to right, so when you use the USB port on the left half, it works as
 * expected. Plugging in to the right half will work for typing, but the RGB
 * won't work as expected.
 *
 * TL;DR - Plug in on the left half
 */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

/*
 * Here's the RGB Configuration. You shouldn't have to touch this.
 */
#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12

#endif
