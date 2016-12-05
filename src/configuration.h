#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "LPC214x.h"

#ifndef BIT
#define BIT(x) (1<<x)
#endif


//1-wire port and pin
#define FIO_OW 0
#define PIN_OW BIT(7)

#define SYSFAN_MIN_TEMP 40 //temperature when fan at minimum speed. if temperature is less, fan is off
#define SYSFAN_MAX_TEMP 50 //temperature when fan is at maximum speed
#define SYSFAN_MIN_PWM 0x50
#define SYSFAN_MAX_PWM 0xff



#endif /* CONFIGURATION_H_ */
