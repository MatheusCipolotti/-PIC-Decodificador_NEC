#ifndef __IR
    #define __IR

    #include <xc.h>
    #define _XTAL_FREQ 20000000
    
    void IR_Read(void);
    uint32_t binaryToDecimal(const char binaryVector[32]);

#endif