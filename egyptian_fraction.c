#include<stdio.h>
typedef struct
{
	int n;
	int numerator[10];
	int denominator[10];
	int final_numerator;
	int final_denominator;
}fraction;

int input_n()
{
	int n;
	printf("Enter number of test cases: ");
	scanf("%d",&n);
	return n;
}

fraction input_fraction()
{
	fraction f;
	printf("Enter the number of fractions: ");
	scanf("%d",&f.n);
	for(int i=0;i<f.n;i++)
	{
	    printf("Enter denominator of the fraction: ");
	    scanf("%d",&f.denominator[i]);
	    f.numerator[i]=1;
	}
	return f;
}

void input_n_fraction(int n, fraction f[n])
{
	for(int i=0;i<n;i++)
	{
		f[i] = input_fraction();
	}
}

int find_gcd(int a, int b)
{
    while (a != b)
    {
       	if (a > b)
         	a -= b;
        else
          	b -= a; 
    }
   	return a;
}

void compute_fraction(fraction *f)
{
	int final_numerator=0,final_denominator=1, gcd;
	for(int i=0;i<f->n;i++)
	{
		final_denominator *= f->denominator[i];
	}
	for(int i=0;i<f->n;i++)
	{
		final_numerator += (f->numerator[i]) * (final_denominator/f->denominator[i]);
	}
	gcd = find_gcd(final_numerator, final_denominator);
    f->final_numerator = final_numerator/gcd;
	f->final_denominator = final_denominator/gcd;
}

void compute_n_fraction(int n, fraction f[n])
{
	for(int i=0;i<n;i++)
	{
		compute_fraction(&f[i]);
	}
}

void output_fraction(int n,fraction f)
{
	for(int i=0;i<f.n-1;i++)
	{
	    printf("%d/%d + ",f.numerator[i],f.denominator[i]);
    }
    printf("%d/%d = %d/%d\n",f.numerator[f.n-1],f.denominator[f.n-1],f.final_numerator,f.final_denominator);
}

void output_n_fraction(int n, fraction f[n])
{
	for(int i=0;i<n;i++)
	{
		output_fraction(n,f[i]);
	}
}

int main()
{
	int n;
	n = input_n();
	fraction f[n];
	input_n_fraction(n,f);
	compute_n_fraction(n,f);
	output_n_fraction(n,f);
	return 0;
}
