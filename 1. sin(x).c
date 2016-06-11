/*
Program to compute the value of sin(x) using the following series :

sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ....

Computation for sin(x) is to be continued until the value of term becomes less than 10^-6.

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	
	int loop=0,n=0;				//declaration of variables and
	double value=0,sum=0,term=0;//initialisation of variables
	
	printf("The Sine series will be :\n");
	
	for(loop=0;loop<=360;loop=loop+30){

		value=loop*3.1415/180;//Changing into radian
		term=value;//Initialising the variables
		sum=value;
		n=1;

		while((term>0.0000001)||(term<-0.0000001)){ //termination condition

			term=(-1)*value*value*term/((2*n)*(2*n+1));//Relation Equation
			n++; //Incrementing power of (x) for the next term in series
			sum+=term; //Finding the sine value by adding the value of term to sum

		}// End of while()

		printf("\t\tSine(%d)=%lf\n",loop,sum);
	
	}//End of for() loop
	
	return 0;
}//End of main()
