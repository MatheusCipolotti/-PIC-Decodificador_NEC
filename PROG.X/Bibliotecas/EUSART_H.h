#ifndef __EUSART
    #define __EUSART

    #include <xc.h>
    #define _XTAL_FREQ 20000000
    
    void UART_Write(const char data);
    void UART_Write_Text(const char text[]);
    void UART_Write_Text_ln(const char text[]);

#endif