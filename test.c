/*
    @task       Solution of an IVS team project - creating calculator
    @team       "ludia bez týmu sem >>>"
    @members    Kramár Viktor, Chovanec David, Vilimovský Dan
    @created    23.4.2022
    @test       Tested with GCC compiler
*/
/**
    @file   test.c
    @author Dan Vilimovský
    @brief  Programme to test mathematical functions from count.h
*/

#include "count.h"

int main(){
    //testing addition
    int add = 0;

    if(addition(3.141597, -3756.57) < -3753.4283 && addition(3.141597, -3756.57) > -3753.4285){
        printf(GREEN "#" RST);
        add++;
    }
    else{
        printf(RED "#" RST);
    }
    if(addition(-148.26, 786.5457) < 638.2858 && addition(-148.26, 786.5457) > 638.2856){
        printf(GREEN "#" RST);
        add++;
    }
    else{
        printf(RED "#" RST);
    }
    if(addition(-98.9987, -57847.5784) < -57946.5760 && addition(-98.9987, -57847.5784) > -57946.5785){
        printf(GREEN "#" RST);
        add++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na sčítání: %d/3\n", add);

    //testing subtraction
    int sub = 0;

    if(subtraction(3.141597, -3756.57) < 3759.7120 && subtraction(3.141597, -3756.57) > 3759.7110){
        printf(GREEN "#" RST);
        sub++;
    }
    else{
        printf(RED "#" RST);
    }
    if(subtraction(-148.26, 786.5457) < -934.8050 && subtraction(-148.26, 786.5457) > -934.8065){
        printf(GREEN "#" RST);
        sub++;
    }
    else{
        printf(RED "#" RST);
    }
    if(subtraction(-98.9987, -57847.5784) < 57748.5785 && subtraction(-98.9987, -57847.5784) > 57748.5775){
        printf(GREEN "#" RST);
        sub++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na odčítání: %d/3\n", sub);

    //testing multiplication


    //testing division


    //testing power

    int pow = 0;

        if(power(3.5, 7) < 6433.93 && power(3.5, 7) > 6433.92){
        printf(GREEN "#" RST);
        pow++;
    }
    else{
        printf(RED "#" RST);
    }
    if(power(-1.48, 35) < -910248.60 && power(-1.48, 35) > -910249.10){
        printf(GREEN "#" RST);
        pow++;
    }
    else{
        printf(RED "#" RST);
    }
    if(power(32.8, 3) < 35287.99 && power(32.8, 3) > 35287.00){
        printf(GREEN "#" RST);
        pow++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na mocnění: %d/3\n", pow);


    //testing root

    int roo = 0;

    //printf("odmocnina 4 1784.5: %lf \n", root(1784.5, 4));

    //testing sinus

    int sin = 0;

    //printf("sin z pi: %lf \n", our_sinus(3.1415));


    //testing factorial

    int fac = 0;

    //printf("fac 6: %lu \n", factorial(6));
    //printf("fac 6: %lf \n", double_factorial(6));
}