/*
Program to implement Simpsons' 1/3 rd rule to implement integration of 1/(1-x)
*/
#include<stdio.h>
#define f(x) 1/(1+x)

double integration(float hi,float lo,int n){
	int i;
	float h=(hi-lo)/n;
	float y0=f(lo);
	float yn=f(hi);
	double s1=0,s2=0;
	for (i=0;i<n/2;i++)
		s1+=f(lo+2*i*h+h);
		
	for (i=0;i<n/2-1;i++)
		s2+=f(lo+2*i*h+2*h);

	return h*(y0+4*s1+2*s2+yn)/3;


}

int main(void){
	float a,b;//initialising and declaring variables
	float I;
	printf("Enter the lower and upper limits of integral: ");
	scanf("%f %f",&a,&b);

	printf("The result is %0.6lf.\n",integration(b,a,10000));
return 0;
}
