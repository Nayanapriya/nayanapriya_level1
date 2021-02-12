//Write a program to find the sum of n different numbers using 4 functions
#include <stdio.h>

int input()
{
    int a;
    printf("Enter the  number of elements to be added\n");
    scanf("%d",&a);
    return a;
}

void input_array(int n, int a[n])
{
    printf("Enter elements in array : ");
    for( int i=0; i<n; i++)
    
        scanf("%d",&a[i]);
    
}

int compute(int n, int a[n])
{
    int sum=0;
    for(int i=0;i<n;i++) 
        sum += a[i];
    
    return sum;
}

int output( int sum)
{
    int i;
    printf("The sum of different elements =%d ",sum); 
    return sum;
   
}

int main()
{
    int n,sum;
    n = input();
    int a[n];
    input_array(n,a);
    sum=compute(n,a);
    output(sum);
}
