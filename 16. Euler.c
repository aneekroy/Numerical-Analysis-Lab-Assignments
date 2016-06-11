/*
Program to find Solution of Differential Equation Using Modified Euler's method
for the equation dy/dx=2*(x^2)+2*y

*/
#include<stdio.h>
#include<math.h>

#define f(x,y) (2*x*x+2*y)
#define exact_y( x) (1.5*exp(2*x)-x*x-x-0.5)

int main(){
	int flag;
	float h=0.1,x=0,y=1;
	float x0,y0,y1_0,y1_1,temp_y1_0;
	
	printf("   X\t   Y_COMP\t Y_ACTUAL\tABS_ERROR\n");
	
	printf("%f  %f\t %f\t%f\n",x,y,exact_y(x),fabs(y-exact_y(x)));
	
	while (x<1){
		x0=x; x+=h; y0=y;
		y1_0=y0+h*f(x0,y0);
		do{
			y1_1=y0+h*(f(x0,y0)+f(x,y1_0))*0.5;
			temp_y1_0=y1_0;
			y1_0=y1_1;

		}while(fabs(temp_y1_0-y1_1)<=0.000005);

		y=y1_1;
		printf("%f  %f\t %f\t%f\n",x,y,exact_y(x),fabs(y-exact_y(x)));
	}
	
	return 0;
}
