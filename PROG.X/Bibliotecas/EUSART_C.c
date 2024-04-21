#include "EUSART_H.h"

void UART_Write(const char data){
    while(!TRMT);
    TXREG = data;
}

void UART_Write_ln(const char data){
    UART_Write(data);
    UART_Write('\r');
    UART_Write('\n');    
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

char UART_Read(){
    while(!RCIF);           //Verifica se um caractere foi recebido
    return RCREG;
}

void UART_Read_Text(char *Output, const unsigned int lenght){
    for(unsigned int i = 0; i<lenght; i++){
        Output[i] = UART_Read();
    }
    Output[lenght]='\0';
}
