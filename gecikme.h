#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gecikme(){
    char mesaj[16]="Bilgileri Girin";
    int i, j, sayac=0;

    for(i=0;i<120;i++){
        for(j=0;j<10000000;j++){}
            if(i>50 && sayac<16)printf("%c",mesaj[sayac++]);

            else{
                printf("*");
            }
        }
    }

