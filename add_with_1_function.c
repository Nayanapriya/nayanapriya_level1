//Write a program to add two user input numbers using one function.
#include<stdio.h>
int main()
{
    int n1,n2,b;
    printf("enter two numbers");
    scanf("%d%d",&n1,&n2);
    b=sum(n1,n2);
    printf("sum=%d",b);
    return (0);
}
int sum(int n1,int n2)
{
    int n3;
    n3=n1+n2;
    return(n3);
}
