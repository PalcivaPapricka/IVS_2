/*
    @task       Solution of an IVS team project - creating calculator
    @team       "ludia bez týmu sem >>>"
    @members    Kramár Viktor, Chovanec David, Vilimovský Dan
    @created    23.4.2022
    @test       Tested with GCC compiler
*/
/**
    @file   count.c
    @author Dan Vilimovský, David Chovanec
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
        fprintf(stderr, RED "[ERROR]" RST ": Exponent must be a positive integer or zero.\n");
        //TODO ukoncit program / math error
        return 0;
    }
    if (exponent == 0){
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
    double a = num_1;
    int n = exponent;
    double root;
    double delta, newVal, oldVal = a / n;
        do {
            newVal = oldVal;
            for(int i = 1; i < n -1; ++i){
                newVal *= oldVal;
            }
            newVal = (a / newVal + (n-1)*oldVal) / n;
            delta = oldVal - newVal;
            if(delta < 0){
                delta = -delta;
            }
            root = oldVal = newVal;
        } while (delta > 0.000001);

    return (root);
}


double our_sinus(double num_1){
    double x = num_1;
    double s = -1;
    for (int i = 3; i <= 100; i += 2) {
        x += s * (power(num_1, i) / double_factorial(i));
        s *= -1;
    }
    return x;
}

double double_factorial(double num){
    if (num < 0){
        fprintf(stderr, RED "[ERROR]" RST ": Cannot count factorial from negative number. \n");
        //TODO ukoncit program / math error
        return 0; 
    }
    double result = num;
    int counter = num - 1;
    while(counter > 1){
        result = result * counter;
        counter--;
    }
    return result;
}


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