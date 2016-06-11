
//Program for secant method for e^x-2*x-1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//defining macros

#define f(x) exp(x)-2*x-1

int main(void){

	float x0=-10,x1=0,x2=0,y0=0,y1=0,y2=0; //declaring variables
	int iter =0;						//initialising variables
	
	printf("The Solution for the Equation using secant method : e^x-2x-1=0 \n");
		
		printf("Enter The two guesses for the root :"); //Taking initial guesses
		scanf("%f %f",&x0,&x1);
		y0=f(x0),y1=f(x1);
		
		if(y0==0){ //checking for roots in the boundary condition
			printf("The solution is %f\n",x0);
			exit(0);
		}
		else if(y1==0){ //checking for roots in the boundary condition
			printf("The solution is %f\n",x1);
			exit(0);
			}
		printf("Iteration  \tx0  \t x1  \t x2 \t   f(x0) \t f(x1) \t  f(x2)\n"); 
		//printing the header for output
		do{
		x2=(x0*y1-x1*y0)/(y1-y0);//Applying Secant formula
		y2=f(x2);
		printf("\n%d\t  %f   %f  %f  %f  %f   %f\n",(++iter),x0,x1,x2,y0,y1,y2);
		//Updating Xo and Yo ,X1 and Y1  
		y0=y1;
		y1=y2;
		x0=x1;
		x1=x2;
		}while(f(x2)>=0.000001||f(x2)<=-0.000001);//terminating condition

		printf("\nThe solution is %f ",x2);//Printing the root
		return 0;
}//End of main()
