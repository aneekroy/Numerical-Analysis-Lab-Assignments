/*
Program to compute the solution of a given system of linear equations using LU Decomposition Method
where the coefficient matrix is decomposed into Lower Triangular and Upper Triangular matrix

*/
#include<stdio.h>
#include<stdlib.h>
void display(float **mat,int n){
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<n;j++)
			printf("%f ",mat[i][j]);
		printf("\n");
	}

}


main(){
	float **a,**l,**u;
	int n,i,j,k,m,p;
	float sum,S;
	printf("Enter the dimension of the matrix: ");
	scanf("%d",&n);
	a=(float **)malloc(n*sizeof(float *));
	float *z=(float *)malloc(n*sizeof(float));
	float *b=(float *)malloc(n*sizeof(float));
	float *x=(float *)malloc(n*sizeof(float));
	
	for (i=0;i<n;i++)
		a[i]=(float *)malloc(n*sizeof(float));

	printf("Enter the coefficient matrix:\n");

	for (i=0;i<n;i++){
		for (j=0;j<n;j++)
			scanf("%f",&a[i][j]);

	}
	printf("\nEnter the Constant Column Matrix B:\n");
	for(i=0;i<n;i++)
		scanf("%f",(b+i));
	
	l=(float **)malloc(n*sizeof(float *));
	
	for (i=0;i<n;i++)
		l[i]=(float *)malloc(n*sizeof(float));

	u=(float **)malloc(n*sizeof(float *));
	
	for (i=0;i<n;i++)
		u[i]=(float *)malloc(n*sizeof(float));



	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++)
			l[i][j]=0;//Initialising L
		

	}

	for (i=0;i<n;i++){
		for (j=0;j<i;j++)
			u[i][j]=0;//Initialising U

	}

	for (i=0;i<n;i++)
		u[i][i]=1;


	for (i=0;i<n;i++)
		l[i][0]=a[i][0];

	for (i=1;i<n;i++)
		u[0][i]=a[0][i]/l[0][0];

	for (m=1;m<n;m++){
		for (i=m;i<n;i++){
			S=0;
			for (k=0;k<=m-1;k++)
				S+=l[i][k]*u[k][m];
			l[i][m]=a[i][m]-S; //Calculating L
		}

		for (j=m+1;j<n;j++){
			S=0;
			for (k=0;k<=m-1;k++)
				S+=l[m][k]*u[k][j];
			u[m][j]=(a[m][j]-S)/l[m][m];//Calculating U
		}

	}
	printf("\nThe Lower Triangular matrix is :\n\n")
	display(l,n);
	printf("\n\nThe Upper Triangular matrix is :\n\n");
	display(u,n);
	

    for(i=0;i<n;i++){                                  
        sum=0;
        for(p=0;p<i;p++)
        sum+=l[i][p]*z[p];
        z[i]=(b[i]-sum)/l[i][i];	//Finding Z where LZ=B

    }
   

    for(i=n-1;i>=0;i--){
        sum=0;
        for(p=n;p>i;p--)
            sum+=u[i][p]*x[p];
        x[i]=(z[i]-sum)/u[i][i];//Finding X where UX=Z
    }
   
    printf("The solution is:\n");
    for(i=0;i<n;i++)
        printf("\tx[%d]=%f \n",i,x[i]);
return 0;
}

  

