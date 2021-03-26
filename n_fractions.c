//WAP to find the sum of n fractions.
#include <stdio.h>
struct fraction
{
    int n;
    int d;
};
typedef struct fraction fract;
int size()
{
    int n ;
    printf("Enter the number of fractions to be added:\n");
    scanf("%d",&n);
    return n;
}
void input(int n , fract f[n])
{
    printf("Enter the numerator and denominator fraction respectively:\n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d%d",&f[i].n , &f[i].d);
    }
}
int gcd(int a , int b)
{ 
     if (b == 0)
        return a;
    return gcd(b, a%b);
}   
fract compute_2fractions(fract f1 , fract f2)
{
    fract f3;
    f3.d = f1.d* f2.d;
    f3.n = (f1.n)*(f2.d)+(f2.n)*(f1.d);
    int common_factor = gcd(f3.n,f3.d);
    f3.d = f3.d/common_factor;
    f3.n = f3.n/common_factor;
    return f3;
}
fract compute_nfractions(int n , fract f[n])
{
    fract sum;
    sum.n = 0;
    sum.d = 1;
    for(int  i=0; i<n;i++)
    {
        sum = compute_2fractions(sum , f[i]);
    }
    return sum;
}
void display(int n , fract f[n] , fract sum)
{
    printf("the fractions to be summed up are\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d/%d\n",f[i].n,f[i].d);
    }
    printf("The sum is : %d/%d ",sum.n,sum.d);
}
int main()
{
    int n;
    n = size();
    fract f[n] , sum;
    input(n,f);
    sum = compute_nfractions(n,f);
    display(n,f,sum);
    return 0;
}

