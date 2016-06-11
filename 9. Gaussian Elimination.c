/*

Program to solve system of Linear Simultaneous Equations using Gaussian Elimination method
	with and without partial pivotting
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void pivoting(float **arr,int k,int n){//Function for partial pivoting
	
	int p=0,l=0;//Initialising and declaring variables
	float max=0,temp=0;

	max=fabs(arr[k][k]);//initialising maximum
	p=k;
	for (l=k+1;l<n;l++){
		if (fabs(arr[l][k])>max){
			max=fabs(arr[l][k]);//finding out the maximum in the given column
			p=l;//assigning the row number
		}	
	}
		
	if (p!=k){
		for (l=0;l<n+1;l++){ 
			temp=arr[p][l];	//Swapping the elements of maximum row:column
			arr[p][l]=arr[k][l];
			arr[k][l]=temp;	//with the diagonal row:column
		}
	}
}//End of function pivoting

void solve (float **arr,int n,int flag){//Function to calculate the solution
	
	int i,j,k;
	float m,y;
	float x[n];//Initialising variables
	for (k=0;k<n-1;k++){
		
		if (flag) 
			pivoting(arr,k,n) ;
		
		for (i=k+1;i<n;i++){
			m=arr[i][k]/arr[k][k];//Calculating the multiplier term
			for (j=k;j<=n;j++)
				arr[i][j]-=m*arr[k][j];//finding out the upper triangular matrix'x element
		}
	
	}
	printf("\nUpper triangular Coefficient matrix and augmented matrix is :\n");
	for(j=0;j<n;j++){
		for(i=0;i<=n;i++){
			if(i==n)
			printf(" |  %f ",arr[j][i]);
			else
			printf("%f ",arr[j][i]);
			
		}
		printf("\n");
		}
		
	printf("\nSolutions of the Given Equations are :-\n");
	for (i=n-1;i>=0;i--){
		y=0;
		for (j=i+1;j<n;j++)
			y+=arr[i][j]*x[j];
		x[i]=(arr[i][n]-y)/arr[i][i];	
	
	}
	
	for (i=0;i<n;i++)
		printf("x[%d] = %f\n",i,x[i]);//Printing solutions

}//End of solve() function


int main(void){//Start of main()
					
	float **arr;//Initialising variables
	int i,j,n,choice;
	printf("Enter no. of variables : ");
	scanf("%d",&n);
	arr=(float **)malloc(n*sizeof(float *));
	for (i=0;i<n;i++)
		arr[i]=malloc((n+1)*sizeof(float));


	for (i=0;i<n;i++){
		printf("Enter the co-efficient of variables and constant term of eqn. %d : \n",i+1);	
		for (j=0;j<(n+1);j++)
			scanf("%f",&arr[i][j]);//Scanning the coefficient matrix along with the augmented matrix
	}
	printf("Enter 1 pivoting else enter 0:");
	scanf("%d",&choice);//Taking choice for pivoting or Non-pivoting
	if (choice)
		solve(arr,n,1);
	else 
		solve(arr,n,0);
	
	return 0;
}//End of main()

