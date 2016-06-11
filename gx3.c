/*
Program to find the roots of the equations x^2-x-6=0 using Iterative Method.

where g(x)=(x*x-6) 

the program should terminate if absolute error is in the range 10^(-6).
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//defining macros

#define g(x) (x*x-6)
#define gd(x) (2*x)
#define f(x) (x*x-x-6)
#define MAX_COUNT 1000
int main()
{
	int count=0;	//declaring and initialising variables
	float x0=0,x1=0,error=0;//declaring and initialising variables
	char iffound=0;	//declaring and initialising variables
	
	printf("Please enter the initial value: ");
	scanf("%f",&x0);	//taking the initial guess
	
	do{
		x1=g(x0);	//applying the iterative formula using g(x)
		error=fabs(x1-x0);	//Calculating the absolute error 
		if(count==0)//Check condition for first iteration
		{
			if(gd(x0)>1||gd(x0)<-1||gd(x0)==0){ //checking convergence of equation
				printf("\nThe equation is not convergent\n");
				iffound=1;
				break;
			}
			else{	//Printing the Header Format
				printf("\n   i	  xi	  f(xi)	         error");
				printf("\n-------------------------------------------");
			}
		}
		printf("\n %3d	%3.5f	 %3.5f	%3.5f",count,x0,f(x0),count==0?0:error);
		x0=x1;		//updating x0 value
		count++;	//updating the iteration count
	}while(error>0.0005&&count<MAX_COUNT);	//Terminating condition
	
	if(!iffound)
		printf("\nThe required root is: %f\n",x0); //printing the root if found
	return 0;
}//End of main()
		


