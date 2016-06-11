/*
Program to find the solution to set of linear simultaneous equations
by Gauss-Seidel Iterative method corrected upto 6 decimalplace

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void solve(float **arr,int n){
	//Initialisation of variables
	float x[n],y[n],S,d;
	int i,j,k=0;
	
	for (i=0;i<n;i++)
		x[i]=0;	//Initial Guess for Xi

	do{
		for (i=0;i<n;i++)
			y[i]=x[i]; //intialising Yi from previous iteration
		for (i=0;i<n;i++){
			S=0;
			for (j=0;j<n;j++)
				if(j!=i)
					S+=arr[i][j]*y[j];
					//applying the values of Xo to Xn (!= i) all from previous iteration
			x[i]=(arr[i][n]-S)/arr[i][i];//Updating the value of Xi

		}

		d=0;
		for (i=0;i<n;i++){
			if (fabs(x[i]-y[i])>d)
				d=fabs(x[i]-y[i]);//Finding the absolute difference between previous and current iteration
		}
		k++;

	}while (d>=0.0000005);//Terminating condition

	for (i=0;i<n;i++)
		printf("%f ",x[i]);//Printing the final solution
}


int main(void){
	
	float **arr;//declaring variables
	int i,j,n,flag=0;//Initialising variables
	float S;
	
	printf("Enter no. of variables to be solved: ");
	scanf("%d",&n);
	
	arr=(float **)malloc(n*sizeof(float *));
	for (i=0;i<n;i++)
		arr[i]=malloc((n+1)*sizeof(float));

	for (i=0;i<n;i++){
		printf("Enter the co-efficient of variables and constant term of eqn. %d one by one: \n",i+1);
		for (j=0;j<(n+1);j++)
			scanf("%f",&arr[i][j]);
	}
	
	for (i=0;i<n;i++){
		S=0;
		for (j=0;j<n;j++)
			S+=fabs(arr[i][j]);
		S-=fabs(arr[i][i]);	
		
		if (fabs(arr[i][i])<=S){//Checking for Diagonal Dominance for solution using Gauss Seidel
			flag=1;
			break;
		}
		
	}
	if (flag)
		printf("The method will not converge\n");
	else 	
		solve(arr,n);				
return 0;
}

