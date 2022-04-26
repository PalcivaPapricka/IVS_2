/*
    @task       Solution of an IVS team project - creating calculator
    @team       "ludia bez týmu sem >>>"
    @members    Kramár Viktor, Chovanec David, Vilimovský Dan
    @created    23.4.2022
    @test       Tested with GCC compiler
*/
/**
    @file   stddev.c
    @author David Chovanec
    @brief  counts determinative deviation
*/

#include <stdlib.h>
#include "count.h"

int main(){
double a;
int count = 0;
double sum = 0;
double average = 0;
 FILE *fp;
fp = fopen ("file.txt", "w");
   
   while (scanf("%lf", &a) != EOF){
        sum =  addition(sum, a);
        fprintf(fp, "%lf \n", a);
        count++;
    }

   average = division(sum, count); 

fclose(fp);
  
  fp = fopen ("file.txt", "r");

  double numberArray[count];
  sum = 0;
  double sub = 0;
  double pow = 0;
  double res = 0;

    for (int i = 0; i < count; i++){
        fscanf(fp, "%lf", &numberArray[i]);
        sub = subtraction(average,numberArray[i]);
        pow = power(sub, 2);
        sum = addition(sum, pow);
        }
    
    res = division(sum, count);
    res = root(res, 2);
    //printf("%lf \n", res);    
    
fclose(fp);  
      
remove("file.txt");
double x = root(16,3);
printf ("%lf\n", x);  
  
  return 0;  
} 