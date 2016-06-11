
//Program to find the roots of  x*x-x-6 using bisection method 

#include<stdio.h>
#include<stdlib.h>

//defining macros

#define f(x) x*x-x-6
int main(void){

	float x0=0,x1=0,x2=0,y0=0,y1=0,y2=0;//declaring variables
	int iter =0;					//initialising variables
	
	printf("The Solution for the Equation using bisection method : x*x-x-6=0 \n");
	
	do{ 
		printf("Enter Range :");//Taking the input range
		scanf("%f %f",&x0,&x1);
		
		y0=f(x0),y1=f(x1);//updating Yo and Y1
		
		if(y0==0){	//checking for roots in the boundary condition
			printf("The solution is %f\n",x0);
			exit(0); 
			}
		else if(y1==0){	//checking for roots in the boundary condition
			printf("The solution is %f\n",x1);
			exit(0);
			}
			
		}while((y0*y1)>0);//Condition for the range to include the roots

		printf("Iteration  \tx0  \t x1  \t Mid  \t   f(x0) \t f(x1) \t  f(Mid)"); 
		//printing the header for output
		do{
		x2=(x0+x1)/2.0; //bisecting range
		y2=f(x2);
		
		printf("\n%d\t  %f   %f  %f  %f  %f   %f\n",(++iter),x0,x1,x2,y0,y1,y2); 
		if(y0*y2>0){
			x0=x2;
		}
		else{
			x1=x2;
		}
		//Updating the values of x1 or x0 according to bisection method condition
		y0=f(x0),y1=f(x1);

		}while(x1-x0>=0.000001||x1-x0<=-0.000001);//terminating condition
		x2=(x1+x0)/2.0;
		printf("\nThe solution is %f ",x2); //Printing the solution
		return 0;
}//End of main()
