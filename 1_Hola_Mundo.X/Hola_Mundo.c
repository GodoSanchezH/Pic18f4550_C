/* 
 * File:   Hola_Mundo.c
 * Author: Godo Sanchez
 * Created on 6 de enero de 2021, 07:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pic18f4550.h>
#include "System.h"
#include <xc.h>

/*
 *En este Programa Haremos un parpadeo usando todo los Pines 
 * del  PORTB,PORTD, y PORTA 
 */

void GPIO_Init(void);//Definimos La funcion

int main(int argc, char** argv) {

    GPIO_Init();//Invocamos la Funcion que inicializa la GPIO

    while(true){
        LATB |= 0xFF;
        LATD |= 0xFF;
        LATA |= 0xFF;
        __delay_ms(300);
        LATB &= 0x00;
        LATD &= 0x00;
        LATA &= 0x00;
        __delay_ms(300);
    }
    return (EXIT_SUCCESS);
}

//Desarollamos  La funcion
void GPIO_Init(void){
//Definimos los puertos Analogicos como Digitales 
    ADCON0 &= 0x00;
//Definimos Los puertos como Salidas
    TRISB &= 0x00;
    TRISA &= 0x00;
    TRISD &= 0x00;
//Inicializamos los puertos en Low
   LATB &= 0x00;
   LATD &= 0x00;
   LATA &= 0x00;
}
