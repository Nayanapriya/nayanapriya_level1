#include<stdio.h>
#include<math.h>

typedef struct
{
	float x;
	float y;
}vertex;

typedef struct
{
	float length;
	float breadth;
	float area;
	vertex v[3];
}rectangle;

int input_n()
{
	int n;
	printf("Enter number of test cases: ");
	scanf("%d",&n);
	return n;
}

rectangle input_rectangle()
{
    rectangle r;
	for(int i=0;i<3;i++)
    {
		scanf("%f%f",&r.v[i].x,&r.v[i].y);
	}
	return r;
}

void input_n_rectangle(int n, rectangle r[n])
{
	for(int i=0;i<n;i++)
	{
		r[i] = input_rectangle();
	}
}

float max(float side1, float side2, float side3)
{
 	if(side1>side2 && side1>side3)
		return side1;
	else if(side2>side1 && side2>side3)
		return side2;
	else
		return side3;
}

float min(float side1, float side2, float side3)
{
    	if(side1<side2 && side1<side3)
		return side1;
	else if(side2<side1 && side2<side3)
		return side2;
	else
		return side3;
}

void compute_rectangle(rectangle *r)
{
	float side1,side2,side3,min_side,max_side,sum;
	side1 = sqrt(pow((r->v[0].x-r->v[1].x),2)+pow((r->v[0].y-r->v[1].y),2));
	side2 = sqrt(pow((r->v[2].x-r->v[1].x),2)+pow((r->v[2].y-r->v[1].y),2));
	side3 = sqrt(pow((r->v[2].x-r->v[0].x),2)+pow((r->v[2].y-r->v[0].y),2));
	min_side = min(side1,side2,side3);
	max_side = max(side1,side2,side3);
	sum = side1 + side2 + side3;
	r->breadth = sum - min_side - max_side;
    	r->length = min_side;
	r->area = r->length * r->breadth;
}

void compute_n_rectangle(int n, rectangle r[n])
{
	for(int i=0;i<n;i++)
	{
		compute_rectangle(&r[i]);
	}
}

void output_rectangle(rectangle r)
{
	printf("\nArea of rectangle with vertices (%.1f,%.1f), (%.1f,%.1f), (%.1f,%.1f) is %.1f",r.v[0].x,r.v[0].y,r.v[1].x,r.v[1].y,r.v[2].x,r.v[2].y,r.area);
}

void output_n_rectangle(int n, rectangle r[n])
{
	for(int i=0;i<n;i++)
	{
		output_rectangle(r[i]);
	}
}

int main()
{
	int n;
	n = input_n();
	rectangle r[n];
	input_n_rectangle(n,r);
	compute_n_rectangle(n,r);
	output_n_rectangle(n,r);
	return 0;
}	
