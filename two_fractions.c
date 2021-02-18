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
    int numerator,denominator;
    sum=(((f1.num*f2.den)+(f2.num*f1.den))/(f1.den*f2.den));
    numerator=((f1.num*f2.den)+(f2.num*f1.den));
    denominator=(f1.den*f2.den);
    printf("The addition of %f/%f and %f/%f in fraction form is %d/%d ",f1.num,f1.den,f2.num,f2.den,numerator,denominator);
    return sum;
}
void output(float sum)
{
    printf("and the simplified form is %f",sum);
    
}
int main()
{
    fraction f1,f2;
    float sum;
    float numerator,denominator;
    f1=input();
    f2=input();
    sum=compute(f1,f2);
    
    output(sum);
    return 0;
    
}
