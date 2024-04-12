/*
 * File:   UART1.c
 * Author: Premjith J
 *
 * Created on October 27, 2023, 2:33 PM
 */


#include <xc.h>
void trans(char);
void str(const char *);
void main(void) 
{
    TRISC=0x00;
    TXSTA=0X24;
    RCSTA=0X80;
    SPBRG=129;
    
    str("Premjith");
   
    while(1);
    return;
}
void str(const char *b)
{
    while(*b)
    {
        trans(*b);
        b++;
    }
}
void trans(char a)
{
    while(TXIF==0);
    TXREG=a;
    while(TRMT==0);
    
}