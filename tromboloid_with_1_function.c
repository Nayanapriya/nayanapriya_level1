//Write a program to find the volume of a tromboloid using one function
#include<stdio.h>
float volume(float h, float d,float b)
{
    float vol=((h*d*b)+(d/b))/3;
    return vol;
}
float main()
{
    float h,b,d,v;
    printf("enter the values of h,b,d");
    scanf("%f%f%f",&h,&d,&b);
    v = volume(h,d,b);
    printf("volume of tromboloid=%f",v);
}
