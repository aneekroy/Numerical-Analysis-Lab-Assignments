
//Program for regula falsi method for x*x-x-6

#include<stdio.h>
#include<stdlib.h>

//defining macros

#define f(x) x*x-x-6

int main(void){
	float x0=0,x1=0,x2=0,y0=0,y1=0,y2=0;//Intialising variables
	int iter =0;			//Declaring variables
	
	printf("The Solution for the Equation using regula falsi method : x*x-x-6=0 \n");
	
	do{ 
		printf("Enter Range :");
		scanf("%f %f",&x0,&x1);//Taking range as an input
		
		y0=f(x0),y1=f(x1); //updating Yo and Y1
		
		if(y0==0){	//checking for roots in the boundary condition
			printf("The solution is %f\n",x0);	
			exit(0);
		}
		else if(y1==0){ //checking for roots in the boundary condition
			printf("The solution is %f\n",x1);	
			exit(0);
			}
		}while((y0*y1)>0);//Condition for the range to include the roots
		
		printf("Iteration  \tA \t B  \t C  \t   f(A) \t f(B) \t  f(C)"); 
		//printing the header for output
		
		do{
		x2=(x0*y1-y0*x1)/(y1-y0); //applying formula for regula falsi method
		
		y2=f(x2);
		
		printf("\n%d\t  %f   %f  %f  %f  %f   %f\n",(++iter),x0,x1,x2,y0,y1,y2); 
		//Updating the values of x1 or x0 according to regula falsi method condition
		if(y0*y2>0){
			x0=x2;
			y0=y2;
		}
		else{
			x1=x2;
			y0=y2;
		}
		y0=f(x0),y1=f(x1);
		
		}while(y2>=0.000001||y2<=-0.000001);//terminating condition
		
		printf("\nThe solution is %f \n ",x2);//printing the solution
		return 0;
}//End of main()
