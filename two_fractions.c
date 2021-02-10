//WAP to find the sum of two fractions.
#include<stdio.h>
#include<conio.h>
typedef struct
     {
        int num;
        int den;
     
      }Fraction;
 
   Fraction sum(Fraction,Fraction);
 
   int main()
    {
     int num1,den1,num2,den2;
     printf("Enter  numerator and  denominator of fraction 1:");
     scanf("%d%d",&num1,&den1);
     printf("Enter numerator and denominator of fraction 2:");
     scanf("%d%d",&num2,&den2);
    
     Fraction f1={num1, den1}; 
     Fraction f2 ={num2, den2};
     Fraction result = sum(f1, f2);
     printf("Result=%d/%d",result.num,result.den);  
 
     
     return 0;
    }
   Fraction sum(Fraction f1, Fraction f2)
    {
     Fraction result={(f1.num * f2.den) + (f2.num * f1.den), f1.den * f2.den};
     return result;
 
   }
