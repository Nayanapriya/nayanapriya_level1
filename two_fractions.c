//WAP to find the sum of two fractions.
#include <stdio.h>
typedef struct fraction
{
    float num,den;
}fraction;
fraction input()
{
    fraction f;
    printf("enter the numerator and denominator of fraction 1 and fraction 2 respectively");
    scanf("%f%f",&f.num,&f.den);
    return f;
}
float compute(fraction f1,fraction f2)
{
    float sum;
    sum=(((f1.num*f2.den)+(f2.num*f1.den))/(f1.den*f2.den));
    return sum;
}
void output(fraction f1,fraction f2,float sum)
{
    printf("The addition of %f/%f and %f/%f is %f",f1.num,f1.den,f2.num,f2.den,sum);
    
}
int main()
{
    fraction f1,f2;
    float sum;
    f1=input();
    f2=input();
    sum=compute(f1,f2);
    output(f1,f2,sum);
    return 0;
    
}
