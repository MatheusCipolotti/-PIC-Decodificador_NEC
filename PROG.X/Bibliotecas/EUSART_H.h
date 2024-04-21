#ifndef __EUSART
    #define __EUSART

    #include <xc.h>
    #define _XTAL_FREQ 20000000
    
    void UART_Write(const char data);
    void UART_Write_ln(const char data);
    void UART_Write_Text(const char text[]);
    void UART_Write_Text_ln(const char text[]);
    char UART_Read(void);
    void UART_Read_Text(char *Output, const unsigned int lenght);
    void IR_Read(void);

#endif