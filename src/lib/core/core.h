#ifndef KERNAL_CORE
#define KERNAL_CORE

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef uint16_t size_t;


typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;


#define NULL (char)0x00


#define KERNAL_NEEDED (int)0x00// That file is required for boot
#define KERNAL_OPTION (int)0x80// This file will not be required for boot
#define KERNAL_BACKUP (int)0xff// This will not be automaticly loaded, only loaded if a system error is detected

#ifdef __cplusplus
#define EXTNC_ extern "C"
#else
#define EXTNC_
#endif

#define EXTNC_START {
#define ECTNC_END }

#define MacroStrCon(x) #x

EXTNC_ void die();
EXTNC_ void ThrowISR(int n);

#define Vasm(x) asm volatile(x);
#define NO_INSTRUCTION Vasm("nop");
#define HALT while(1) { NO_INSTRUCTION; } 



// PLEASE FIX THIS!!!! USE PIC
#define sleep(x) for (int __dj = 0; __dj > x; __dj++) {;};

#endif // !KERNAL_CORE
