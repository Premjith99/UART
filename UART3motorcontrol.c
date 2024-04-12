/*
 * File:   UART3motorcontrol.c
 * Author: Premjith J
 *
 * Created on October 30, 2023, 2:09 PM
 */


#include <xc.h>

char rec(void);

void main(void) 
{
    TRISC=0x80;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=129;
    while(1)
    {
        char a=rec();
        /*if(a=='c')
        {
            RC0=1;
            RC1=0;
        }
        else if(a=='a')
        {
            RC0=0;
            RC1=1;
        }
        else  if(a=='s')
        {
            RC0=0;
            RC1=0;
        }*/
        switch(a)
        {
            case 'c':
                RC0=1;
                RC1=0;
                break;
            case 'a':
                RC0=0;
                RC1=1;
                break; 
            case 's':
                RC0=0;
                RC1=0;
                break;    
        }
            
    }
        
    return;
}
char rec(void)
{
    while(RCIF==0);
    return RCREG;
}