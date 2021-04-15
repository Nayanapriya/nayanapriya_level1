#include<stdio.h>
#include<string.h>
typedef struct
{
	char tc_name[10];
	int tot_minutes;
}timecards;

typedef struct 
{
	char names[10];
	float hr_wage;
	
	float hrs_worked;
	float min_worked;
	float total_time;
	float gross_pay;
}payroll;

int input_n_value()
{
	int n;
	printf("Enter the number of employees(<=20): ");
	scanf("%d",&n);
	if(n<=20)
		return n;
	else
		printf("Wrong input");
	return 0;	
}
int input_m_value()
{
	int m;
	printf("Enter the number of timecards: ");
	scanf("%d",&m);
	return m;
}
payroll input_employee()
{
	payroll p;
	printf("Enter employee's name and hourly wage: ");
   	scanf("%s %f",p.names,&p.hr_wage);
   	return p;
}

void input_n_employee(int n,payroll p[n])
{
    for(int i=0;i<n;i++)
    {
        p[i] = input_employee();
    }
}

timecards input_timecards()
{	
    timecards t;
    printf("Enter the employee's name and corresponding minutes worked: ");
    scanf("%s %d",t.tc_name,&t.tot_minutes);
    return t;
}

void input_m_timecards(int m,timecards t[m])
{
    for(int i=0; i<m; i++)
    {
    	t[i] = input_timecards();
    }
}
payroll compute(int m,timecards t[m], payroll p)
{
   
    p.min_worked=0;
    for(int i=0;i<m;i++)
    {
        if(strcmp(p.names,t[i].tc_name)==0)
        {
            p.min_worked+=t[i].tot_minutes;
        }
    }
    p.hrs_worked=p.min_worked/60;
    if(p.hrs_worked<=40)
        {p.gross_pay=p.hrs_worked*p.hr_wage;}
    else
        {p.gross_pay=40*p.hr_wage+(p.hrs_worked-40)*1.5*p.hr_wage;}
    return p;
    
   
}
void compute_n_values(int n, int m, timecards t[m],payroll p[n])
{
   
    for(int i=0; i<n; i++)
    {
    	p[i]=compute(m,t,p[i]);
    }
}

void output(payroll *p)
{
    printf("\n%s: %.2f hours,$%.2f",p->names,p->hrs_worked,p->gross_pay);
}
void output_n_employee(int n,payroll p[n])
{
    for(int i=0;i<n;i++)
    {
        output(&p[i]);
    }
}
int main()
{
	int n;
	n = input_n_value();
	payroll p[n];
	input_n_employee(n,p);
	int m;
	m=input_m_value(); 
	timecards t[m];
	input_m_timecards(m,t);
    compute_n_values(n,m,t,p);
	output_n_employee(n,p);
	return 0;
}
