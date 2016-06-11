/*

Program to solve system of Linear Simultaneous Equations using Gauss - Jordan Elimination method
	(with and without partial pivoting) with elimination process applied to all rows except pivotal
	row element
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void pivoting(float **arr,int k,int n){	//Function for partial pivoting
	
	int p=0,l=0;	//Initialising and declaring variables
	float max=0,temp=0;

	max=fabs(arr[k][k]); //initialising maximum
	p=k;
	for (l=k+1;l<n;l++){
		if (fabs(arr[l][k])>max){
			max=fabs(arr[l][k]);//finding out the maximum in the given column
			p=l;//assigning the row number for given column
		}	
	}
		
	if (p!=k){
		for (l=0;l<n+1;l++){
			temp=arr[p][l]; //Swapping the elements of maximum row:column 
			arr[p][l]=arr[k][l];
			arr[k][l]=temp; //with the diagonal row:column
		}
	}
	return;
}//End of pivoting()function

void solve (float **arr,int n,int flag){//Function to calculate the solution of n variables
	int i,j,k,l,p;
	float m,y,max,temp;
	float x[n];
	for (k=0;k<n;k++){
		if (flag) 
			pivoting(arr,k,n) ;//calling for partial pivoting according to choice
		
		for (i=0;i<n;i++){
			if (i==k)
				continue;//skipping the diagonal elements
			m=arr[i][k]/arr[k][k];//calculating the multiplier value
			for (j=0;j<=n;j++)
				arr[i][j]-=m*arr[k][j];//finding out the diagonal matrix
		}		
	}
	printf("\n The diagonal matrix and augmented matrix is :\n");
	for(j=0;j<n;j++){
		for(i=0;i<=n;i++){
			if(i==n)
			printf(" |  %f ",arr[j][i]);
			else
			printf("%f ",arr[j][i]);
			
		}
		printf("\n");
		}
	printf("\n\n");
	printf("Solutions of the Given Equations are :-\n");
	for (i=0;i<n;i++){
		x[i]=arr[i][n]/arr[i][i];
		
	}//dividing  the augmented column matrix by the diagonal elements 
	
	for (i=0;i<n;i++)
		printf("x%d = %f\n",i,x[i]);//printing the solutions

}//End of function calculate

int main(void){
					
	float **arr;//Initialising variables
	int i,j,n,choice;
	printf("Enter no. of variables to be solved: ");
	scanf("%d",&n);//scanning no. of inputs to be taken
	arr=(float **)malloc(n*sizeof(float *));
	for(i=0;i<n;i++)
		arr[i]=malloc((n+1)*sizeof(float));

	for(i=0;i<n;i++){
		printf("Enter the co-efficient of variables and constant term of eqn. %d one by one: \n",i+1);
		for (j=0;j<(n+1);j++)
			scanf("%f",&arr[i][j]);//Scanning the coefficient matrix along with the augmented matrix
	}
	
	printf("Enter 0 for without pivoting else enter 1:");
	scanf("%d",&choice);//Taking choice for pivoting or Non-pivoting

	if (choice)
		solve(arr,n,1);
	else 
		solve(arr,n,0);
	return 0;
}//End of main()

