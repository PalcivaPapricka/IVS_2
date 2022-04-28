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

    int mul = 0;

    if(multiplication(3.5, -7.4) < -25.89 && multiplication(3.5, -7.4) > -25.91){
        printf(GREEN "#" RST);
        mul++;
    }
    else{
        printf(RED "#" RST);
    }
    if(multiplication(-1.48, 35) < -51.7 && multiplication(-1.48, 35) > -51.9){
        printf(GREEN "#" RST);
        mul++;
    }
    else{
        printf(RED "#" RST);
    }
    if(multiplication(32.8, 3.48) < 114.145 && multiplication(32.8, 3.48) > 114.143){
        printf(GREEN "#" RST);
        mul++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na násobení: %d/3\n", mul);

    //testing division

    int div = 0;

    if(division(-735.4, -5) < 148 && division(-735.4, -5) > 146){
        printf(GREEN "#" RST);
        div++;
    }
    else{
        printf(RED "#" RST);
    }
    if(division(-1.48, 35) < -0.042 && division(-1.48, 35) > -0.044){
        printf(GREEN "#" RST);
        div++;
    }
    else{
        printf(RED "#" RST);
    }
    if(division(32.8, 3.7) < 8.870 && division(32.8, 3.7) > 8.864){
        printf(GREEN "#" RST);
        div++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na dělení: %d/3\n", div);


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

    if(root(1028.63, 4) < 5.70 && root(1028.63, 4) > 5.60){
        printf(GREEN "#" RST);
        roo++;
    }
    else{
        printf(RED "#" RST);
    }
    if(root(58, 2) < 7.650 && root(58, 2) > 7.580){
        printf(GREEN "#" RST);
        roo++;
    }
    else{
        printf(RED "#" RST);
    }
    if(root(123456789.123, 8) < 10.275 && root(123456789.123, 8) > 10.260){
        printf(GREEN "#" RST);
        roo++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na odmocňování: %d/3\n", roo);


    //testing sinus

    int sin = 0;

    if(our_sinus(125.48) < -0.175 && our_sinus(125.48) > -0.188){
        printf(GREEN "#" RST);
        sin++;
    }
    else{
        printf(RED "#" RST);
    }
    if(our_sinus(-1.48) < -0.994 && our_sinus(-1.48) > -1){
        printf(GREEN "#" RST);
        sin++;
    }
    else{
        printf(RED "#" RST);
    }
    if(our_sinus(1989.1989) < -0.539 && our_sinus(1989.1989) > -0.541){
        printf(GREEN "#" RST);
        sin++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na sinus: %d/3\n", sin);


    //testing factorial

    int fac = 0;

    if(factorial(8) == 40320){
        printf(GREEN "#" RST);
        fac++;
    }
    else{
        printf(RED "#" RST);
    }
    if(factorial(12) == 479001600){
        printf(GREEN "#" RST);
        fac++;
    }
    else{
        printf(RED "#" RST);
    }
    if(factorial(5) == 120){
        printf(GREEN "#" RST);
        fac++;
    }
    else{
        printf(RED "#" RST);
    }

    printf("\nTesty funkce na faktoriál: %d/3\n", fac);
}
