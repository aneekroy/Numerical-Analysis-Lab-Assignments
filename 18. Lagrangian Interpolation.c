/*
Program for Lagrange's Interpolation using

y=Yobo(x)+Y1b1(x)+....+Y(k-1)b(k-1)(x)+Ykbk(x)+Y(k+1)b(k+1)(x)+....+Y(n-1)b(n-1)(x)+Ynbn(x)

where bi(xj)=1 when i=j OR bi(xj)=0 when i!=j

*/
#include<stdio.h>
int main(void){
	int n=0;
	printf("Enter the no. of co-ordinates:");
	scanf("%d",&n);
	int i=0,j=0;double P=0,x[n+1],y[n+1];
	for(i=0;i<n;i++){
		printf("\nEnter x(%d) ,y(%d) :",i,i);
		scanf("%lf %lf",(x+i),(y+i));
	}

	double	sum=0,num=1,dem=0;

	printf("\nEnter the point for interpolation:");
	scanf("%lf",&P);
	
	for(i=0;i<n;i++){
		num=1,dem=1;
		for(j=0;j<n;j++)
			if(i!=j){
			num*=P-x[j];
			dem*=x[i]-x[j];	
		}
		sum+=(y[i]*num)/dem;
	}
	printf("\nY(%lf)=%lf",P,sum);
	return 0;
}
