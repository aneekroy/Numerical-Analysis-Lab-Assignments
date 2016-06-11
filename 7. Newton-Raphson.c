
//Program to find the roots of  x*x-x-6 using newton raphson method 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//defining function macros

#define f(x) (x*x-x-6)
#define f1(x) (2*x-1)

int main(void){
	
	double x=10,x1=0.0;int iter=0;//Initialising and declaring variables
	printf("Enter Initial Guess :");
	scanf("%lf",&x); //Reading Initial Guess
	
	printf("The Solution for the Equation using Newton Raphson method : x*x-x-6=0 \n");
	
	printf("\nIter\tx\tf(x) \t ERROR \n");//printing header for Output
	do{
		x1=x;
		x=x1-(f(x1)/f1(x1));//applying formula for newton raphson
		printf("%d  %lf %lf %lf \n",(++iter),x,f(x),fabs(x-x1));
	}while(fabs(x-x1)>0.00001);//terminating condition
		
		printf("The solution is : %lf",x);//printing solution
		return 0;	
}//End of main()
