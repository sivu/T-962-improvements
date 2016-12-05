#ifndef IO_H_
#define IO_H_

#include <stdint.h>

#define __FIO(x,SUB) FIO##x##SUB

#define FIODIR(x) __FIO(x,DIR)
#define FIOCLR(x) __FIO(x,CLR)
#define FIOSET(x) __FIO(x,SET)
#define FIOPIN(x) __FIO(x,PIN)
#define FIOMASK(x) __FIO(x,MASK)

#define IAP_READ_PART (54)
#define IAP_REINVOKE_ISP (57)
#define PART_REV_ADDR (0x0007D070)

typedef struct {
    const char* name;
    const uint32_t id;
} partmapStruct;

void Set_Heater(uint8_t enable);
void Set_Fan(uint8_t enable);
void IO_InitWatchdog(void);
void IO_PrintResetReason(void);
int IO_Partinfo(char* buf, int n, char* format);
void IO_JumpBootloader(void);
void IO_Init(void);
#endif /* IO_H_ */
