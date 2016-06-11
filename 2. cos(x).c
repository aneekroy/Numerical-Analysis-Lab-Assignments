/*program to compute the cos(x) using :

cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + .... 

Termination condition for the loop is value of term should be less than 10^-6.
 
 */
#include<stdio.h>
#include<stdlib.h>

//Progam to find Cos Series

int main(void){

	int loop,n;				//declaration of variables and
	float value,sum=0,term; //initialisation of variables

	printf("The Cosine series will be :\n");

	for(loop=0;loop<=360;loop=loop+30){

		value=loop*3.1415/180; //Change into radian
		term=1; //Initialising Variables
		sum=1;
		n=1;

		while((term>0.000001)||(term<-0.000001)){ //termination condition

			term=(-1)*value*value*term/((2*n)*(2*n-1));//Relation equation
			n++; //Incrementing power of (x) for the next term in series
			sum+=term; //Finding the cos value by adding the value of term to sum

		} // End of while()

		printf("\t\tCos(%d)=%f",loop,sum); //printing cos(x) value
		printf("\n");

	} //End of for loop()

	return 0;

}//End of main()

