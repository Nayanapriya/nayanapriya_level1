//WAP to find the distance between two point using 4 functions.
#include <stdio.h>
#include<math.h>
float input()
{
    float z; 
    
    printf("Enter coordinates of point1(x1,y1) and point2(x2,y2)\n");
    scanf("%f",&z);
    return z;
   
    
}



float compute(float x1, float y1, float x2, float y2)
{
  float d;
  d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  return d;
}

float output(float x1,float y1,float x2,float y2,float d)
{
    printf("The distance between (%f,%f)and (%f,%f) is %f\n",x1,y1,x2,y2,d);
    return d;
}


float main()
{
    float x1,x2,y1,y2,d;
    x1=input();
    y1=input();
    x2=input();
    y2=input();
    d=compute(x1,y1,x2,y2);
    output(x1,y1,x2,y2,d);
    return 0;
    
}
