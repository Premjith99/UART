/*
 * File:   ADC2.c
 * Author: Premjith J
 *
 * Created on October 25, 2023, 2:36 PM
 */


#include <xc.h>
#include<stdio.h>
void cmd(char);
void data(char);
void str(const char *);
void main(void) 
{
    char a[10],b[10];
    TRISC=0x00;
    TRISD=0x00;
    TRISA=0x01;
    ADCON0=0x01;
    ADCON1=0x00;
    cmd(0x38);
    cmd(0x0F);
  
   
    while(1)
    {
        for(int i=0;i<1000;i++);
        GO_DONE=1;
        while(GO_DONE==1);
        cmd(0x80);
        
       
        int s=(ADRESH/51);
        float p=(ADRESH/51.0);//should use 51.0then only decimal places will appear in lcd 
        /*
        int s=((ADRESH*10)/51);
        data((s/10)+48);
        data('.');
        data((s%10)+48);*/
        sprintf(a,"Int Val:%d",s);//in built function in stdio.h so no need to declare it just calling is enough.
        str(a);
        cmd(0xC0);
        
        
        sprintf(b,"Float Val:%f",p);
        str(b);
       
        
        
    }
           
    return;
}
void cmd(char a)
{
    RC0=0;
    
    PORTD=a;
    RC1=1;
    for(int i=0;i<=1000;i++);
    RC1=0;
    for(int i=0;i<=10000;i++);
}

void data(char a)
{
    RC0=1;
   
    PORTD=a;
    RC1=1;
    for(int i=0;i<=1000;i++);
    RC1=0;
    for(int i=0;i<=10000;i++);
}
void str(const char *d)
{
    while(*d)
    {
        data(*d);
        d++;
    }
}