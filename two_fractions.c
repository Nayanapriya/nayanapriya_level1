//WAP to find the sum of two fractions.
#include <stdio.h>
typedef struct fraction
{
    int num,den;
}fraction;
fraction input()
{
    fraction f;
    printf("enter the numerator and denominator of fraction 1 and fraction 2 respectively");
    scanf("%d%d",&f.num,&f.den);
    return f;
}
int gcd(int x,int y)
{
    while(x!=y)
    {
        if(x>y)
            x=x-y;
        else
            y=y-x;
        
    }
    return x;
}

fraction compute(fraction f1,fraction f2)
{
    fraction f3, sum;
    f3.den=gcd(f1.den,f2.den);
    f3.den=(f1.den*f2.den)/f3.den;
    f3.num=(f1.num)*(f3.den/f1.den)+(f2.num)*(f3.den/f2.den);
    int c_f=gcd(f3.num,f3.den);
    f3.den=f3.den/c_f;
    f3.num=f3.num/c_f;
    return f3;
}
void output(fraction f1,fraction f2,fraction f3)
{
    printf("The addition of %d/%d and %d/%d in fraction form is %d/%d ",f1.num,f1.den,f2.num,f2.den,f3.num,f3.den);
    
}
int main()
{
    fraction f1,f2,f3;
    f1=input();
    f2=input();
    f3=compute(f1,f2);
    output(f1,f2,f3);
    return 0;
    
}
