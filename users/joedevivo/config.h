#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

/* Use I2C or Serial, not both */
#define USE_SERIAL
//#define USE_I2C

/* Select hand configuration */
//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16

#endif
