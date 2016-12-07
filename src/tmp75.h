#ifndef TMP75_H_
#define TMP75_H_

#include <stdint.h>

void TMP75_Init();

uint8_t TMP75_IsPresent();
float TMP75_GetTemp();



#endif /* end of include guard: TMP75_H_ */
