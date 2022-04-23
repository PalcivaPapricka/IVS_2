/*
    @task       Solution of an IVS team project - creating calculator
    @team       "ludia bez týmu sem >>>"
    @members    Kramár Viktor, Chovanec David, Vilimovský Dan
    @created    23.4.2022
    @test       Tested with GCC compiler
*/
/**
    @file   count.h
    @author Dan Vilimovský
    @brief  Declarating mathematical functions
*/

#ifndef COUNT_H
#define COUNT_H

#include <math.h>
#include <stdio.h>

#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define RST "\e[0m"

/**
 * @brief Adds two numbers together.
 * 
 * @param num_1 
 * @param num_2 
 * @return double 
 */
double addition(float num_1, float num_2);

/**
 * @brief Subtracts second number from the first one.
 * 
 * @param num_1 
 * @param num_2 
 * @return double 
 */
double subtraction(float num_1, float num_2);

/**
 * @brief Multiplies two numbers.
 * 
 * @param num_1 
 * @param num_2 
 * @return double 
 */
double multiplication(float num_1, float num_2);

/**
 * @brief Divides first number by the second one.
 * 
 * @param num_1 
 * @param num_2 
 * @return double 
 */
double division(float num_1, float num_2);

/**
 * @brief Calculates the nth power of the entered number, where exponent is integer.
 * 
 * @param num_1 
 * @param exponent 
 * @return double 
 */
double power(float num_1, int exponent);

/**
 * @brief Calculates the nth root of the entered number.
 * 
 * @param num_1 
 * @param exponent 
 * @return double 
 */
double root(float num_1, int exponent);

/**
 * @todo 1 povinna fce navic, neni v zadani specifikovana ######################################################################################
 */

/**
 * @brief Calculates factorial of entered number.
 * 
 * @return unsigned long 
 */
unsigned long factorial(int num);

#endif