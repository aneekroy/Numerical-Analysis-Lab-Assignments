/*Program to find 1/(1-x) using  :

1/(1-x) = 1 + x + x^2 + x^3 + x^4 + x^5 + x^6 + ... when (-1 < x < +1),

The Termination condition for the loop is value of term should be less than 10^(-6). 

*/

#include<stdio.h>

 	//Program to find the value of 1/(1-x) using series

double power(double x,int n){//function for calculating power
	double y=1;
	while(n!=0){
		y*=x;
		n--;
	}
	return y;
}//end of power() function

int main(void){
	double num,sum=1;//declaration and initialisation of variables 
	int i=1;		//initialization of variables
	double temp;
	
	printf("Please input a value (Between (-1) and (+1) ): ");
	scanf("%lf",&num);	//scanning input value of (x) from user
	
	temp=num;			//Initialising temp
	
	while((num>0.000001)||(num<-0.000001)){ //terminating condition
		sum=sum+num;
		i++;
		num=power(temp,i);
	}//End of while() loop		
	
	printf("\n The value of 1-(1/x) will be: %lf \n",sum);//printing the sum value
	return 0;
}//end of main()

