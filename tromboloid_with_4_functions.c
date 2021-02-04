//WAP to find the volume of a tromboloid using 4 functions.
#include <stdio.h>
float input()
{
    float h; 
    printf("Enter a value of height,depth,breadth respectively\n");
    scanf("%f",&h);
    return h;
}

float find_volume(float h, float d, float b)
{
    float volume;
    volume = ((h*d*b)+(d/b))/3;
    return volume;
}

void output(float h, float d, float b,float volume)
{
    printf("volume of tromboloid with height=%f,depth=%f,breadth=%f is %f",h,d,b,volume);
}

float main()
{
    float x,y,z,k;
    x=input();
    y=input();
    z=input();
    k=find_volume(x,y,z);
    
    output(x,y,z,k);
    return 0;
}

