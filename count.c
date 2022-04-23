/*
    @task       Solution of an IVS team project - creating calculator
    @team       "ludia bez týmu sem >>>"
    @members    Kramár Viktor, Chovanec David, Vilimovský Dan
    @created    23.4.2022
    @test       Tested with GCC compiler
*/
/**
    @file   count.c
    @author Dan Vilimovský
    @brief  Definig mathematical functions from header file count.h
*/

#include "count.h"

double addition(float num_1, float num_2){
    return (num_1 + num_2);
}

double subtraction(float num_1, float num_2){
    return (num_1 - num_2);
}

double multiplication(float num_1, float num_2){
    return (num_1 * num_2);
}

double division(float num_1, float num_2){
    if (num_2 == 0.0){
        fprintf(stderr, RED "[ERROR]" RST ": Cannot divide by 0.\n");
        //TODO ukoncit program / math error
        return 0;
    }
    return (num_1 / num_2);
}

double power(float num_1, int exponent){
    if (exponent < 0){
        fprintf(stderr, RED "[ERROR]" RST ": Exponent must be a positive number or zero.\n");
        //TODO ukoncit program / math error
        return 0;
    }
    if (exponent = 0){
        return 1;
    }
    double result = num_1;
    for(int i = 0; i < (exponent - 1); i++){
        result = result * num_1;
    }
    return result;
}

double root(float num_1, int exponent){
    if (num_1 < 0){
        fprintf(stderr, RED "[ERROR]" RST ": Cannot count root from negative number.\n");
        //TODO ukoncit program / math error
        return 0;
    }
    float exp = 1 / exponent;
    return pow(num_1, exp);
}

//TODO fce povinne ze zadani navic

unsigned long factorial(int num){
    if (num < 0){
        fprintf(stderr, RED "[ERROR]" RST ": Cannot count factorial from negative number. \n");
        //TODO ukoncit program / math error
        return 0; 
    }
    unsigned long result = num;
    int counter = num - 1;
    while(counter > 1){
        result = result * counter;
        counter--;
    }
    return result;
}
