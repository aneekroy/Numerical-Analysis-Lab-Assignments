/*
	Program to find the root of the equation e^x- 4*x^2=0 using Macros and fixed point iterative method
	
	where g(x) = (0.5*pow(e,x/2)) in convergent condition and g(x) = log(4*x*x) in divergent condition
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define e 2.7182818284590452353602874713527

#define f(x) pow(e,x)-4*x*x

/*
#define g(x) log(4*x*x)
#define g1(x) (2/x)
*/

#define g(x) (0.5*pow(e,x/2))
#define g1(x) (0.25*pow(e,x/2))


void p(){ printf("\n-------------------------------------------------------------------------------\n");
	return;
}
int main(void){
	
	float x=0,y=0; 	//Initialising and Declaring variables
	int iter=0,flag=0;
		
	x=1.0;
	y=g(x);
	p();
	//printing the header of output
	printf("Iter No.  Xo\t\tXi\t\tf(x)\t\tg'(x)\t\tXo-Xi\n");
	p();
	
	while(y-x<=-0.000001||y-x>=0.000001){//terminating condition
		if(iter==0)
		if(g1(x)<-1||g1(x)>1){//checking divergent condition
		printf("Diverges");
		flag=1;
		break;
		}
		printf("%d\t%f\t%f\t%f\t%f\t%.5f\n",(++iter),x,y,f(x),g1(x),y-x);
		x=y; //Updating X value 
		y=g(x);	//applying fixed point iteration formula
		
	}//End of while loop
	
	p();
	if(flag!=1)printf("\nThe solution is %f\n",y);//printing the solution
	p();
	return 0;
	
}//End of main()


