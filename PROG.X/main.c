/*
 * DECODIFICADOR NEC
 * 
 * AUTOR: MATHEUS DANTAS CIPOLOTTI
 * 
 * MICROCONTROLADOR: 16F877A
 * CRISTAL: 20MHz (Externo)
 * COMPILADOR: XC8 V2.46
*/

#include "config.h"
#include <xc.h>
#include "Bibliotecas/EUSART_H.h"
#include "Bibliotecas/IR_H.h"

#define _XTAL_FREQ 20000000

unsigned char counter = 0x00, trava = 0x00;

// Manipulador da interrupção
void __interrupt() global(){
    if (INTF){
        counter++;
        __delay_us(100);
        
        if(PORTBbits.RB0 == 1 && trava == 0){
            INTF = 0; // Limpa a flag de interrupção
        }
        if(PORTBbits.RB0 == 0 && trava != 0){
            INTF = 0; // Limpa a flag de interrupção
        }
    }
}

void main(void){
    CMCON = 0x07;                   //Desabilita todos os comparadores internos
    
    //Configuracao das interrupcoes
    INTCONbits.GIE = 0x01;          //Habilita a interrupcao Global
    INTCONbits.PEIE = 0x00;         //Desabilita a interrupcao por Perifericos
    INTCONbits.INTE = 0x01;         //Habilita a interrupção externa
    INTCONbits.INTF = 0x00;         //Limpa a Flag de interrupcao do TMR0
    OPTION_REGbits.INTEDG = 0x00;   //Detecta borda de descida
    
    //UART Init - BaudRate 9600
    SPBRG = 31;                     //(Assincrono) Baud Rate = Fosc/(64(X+1))
    TXSTAbits.SYNC = 0;             //Configura modo assincrono
    TXSTAbits.TXEN = 1;             //Ativa envio de dados
    RCSTAbits.SPEN = 1;             //Ativar a porta Serial
    RCSTAbits.CREN = 1;             //Ativa o recebimento de dados
    
    //Configuracao dos PORTS
    TRISB = 0x01;
    TRISC = 0x80;
    PORTB = 0x00;
    PORTC = 0x00;
    
    while(1){
        IR_Read();                  
    }
}
