/*

Program to find the Inverse of Matrix using Gauss - Jordan Elimination method (with 
	 partial pivoting) with elimination process applied to all rows 
	except pivotal row elements
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
		for (l=0;l<2*n;l++){
			temp=arr[p][l]; //Swapping the elements of maximum row:column 
			arr[p][l]=arr[k][l];
			arr[k][l]=temp; //with the diagonal row:column
		}
	}
	return;
}//End of pivoting()function

void solve (float **arr,int n){//Function to calculate the solution of n variables
	int i,j,k,l,p;
	float m,y,max,temp;
	float x[n];
	for (k=0;k<n;k++){
			pivoting(arr,k,n) ;//calling for partial pivoting according to choice
		
		for (i=0;i<n;i++){
			if (i==k)
				continue;//skipping the diagonal elements
			m=arr[i][k]/arr[k][k];//calculating the multiplier value
			for (j=0;j<2*n;j++)
				arr[i][j]-=m*arr[k][j];//finding out the diagonal matrix
		}		
	}
	for(j=0;j<n;j++){
	
	for (i=0;i<n;i++){
	
		arr[j][i+n]=arr[j][i+n]/arr[j][j];
	}
	
	}//dividing  the augmented  matrix by the diagonal elements 
		
	for(j=0;j<n;j++)
	arr[j][j]/=arr[j][j];
	
	printf("\n The augmented matrix is :\n");
	for(j=0;j<n;j++){
		for(i=0;i<2*n;i++){
			if(i==n)
			printf(" |  %f ",arr[j][i]);
			else
			printf("%f ",arr[j][i]);
			
		}
		printf("\n");
		}
	printf("\n\n");

	printf("The Inverse Matrix is :-\n\n");
		for(i=0;i<n;i++){
			for(j=n;j<2*n;j++){
				printf("%f  ",arr[i][j]);//printing the inverse matrix
			}
			printf("\n");
			}
}//End of function calculate

int main(void){
					
	float **arr;//Initialising variables
	int i,j,n;
	printf("Enter no. of variables to be solved: ");
	scanf("%d",&n);//scanning no. of inputs to be taken
	arr=(float **)malloc(n*sizeof(float *));
	for(i=0;i<n;i++)
		arr[i]=malloc((2*n+1)*sizeof(float));
		
	printf("Enter the Matrix whose inverse is to be calculated \n");
	for(i=0;i<n;i++){
		for (j=0;j<n;j++)
			scanf("%f",&arr[i][j]);//Scanning the coefficient matrix along with the augmented matrix
	}
	for(i=0;i<n;i++){
	for(j=n;j<2*n;j++){
		if(j-i==n)
		arr[i][j]=1;
		else
		arr[i][j]=0;
		}
	}
		solve(arr,n);
	return 0;
}//End of main()

