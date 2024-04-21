#include "IR_H.h"
#include "EUSART_H.h"

unsigned char counter = 0x00, trava = 0x00, code_count = 0x00;
unsigned long decimalValue = 0x00;
char code[33] = "00000000111111110000000011111111";


// Função para converter o vetor char binário em um valor decimal
uint32_t binaryToDecimal(const char binaryVector[32]) {
uint32_t decimalValue = 0;
    for (int i = 0; i < 32; i++) {
        // Desloca o valor decimal uma posição para a esquerda e adiciona o dígito binário atual
        decimalValue = (decimalValue << 1) + (binaryVector[i] - '0');
    }
return decimalValue;
}

void IR_Read(){
    if(counter >= 80 && counter <= 100){
        //UART_Write_Text_ln("NEC:");
        OPTION_REGbits.INTEDG = 1;
        trava++;
        counter = 0x00;
    }
    else if(counter >= 26 && counter <= 79){
        //UART_Write_Text_ln("ERRO");
        counter = 0x00;
        for(int i = 0; i < 31; i++){
            code[i] = '0';
        }
    } 
    else if(counter >= 101){
        //UART_Write_Text_ln("ERRO");
        counter = 0x00;
        for(int i = 0; i < 31; i++){
            code[i] = '0';
        }
    }
    else if(counter >= 4 && counter <= 8){
        //UART_Write_Text("0");
        code[code_count] = '0';
        trava++;
        code_count++;
        counter = 0x00;
    }
    else if(counter >= 9 && counter <= 25){
        //UART_Write_Text("1");
        code[code_count] = '1';
        trava++;
        code_count++;
        counter = 0x00;
    }
    else if(code_count == 32){
        trava = 0x00;
        counter = 0x00;
        code_count = 0x00;
        OPTION_REGbits.INTEDG = 0;
            
        decimalValue = binaryToDecimal(code);
        UART_Write_Text_ln(code);
            
        __delay_ms(1000);
    }
}
