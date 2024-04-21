#include "EUSART_H.h"

void UART_Write(const char data){
    while(!TRMT);
    TXREG = data;
}

void UART_Write_Text(const char text[]){
    int i;
    for(i=0;text[i]!='\0';i++){
        UART_Write(text[i]);        
    }
}

void UART_Write_Text_ln(const char text[]){
    UART_Write_Text(text);
    UART_Write('\r');
    UART_Write('\n');   
}
