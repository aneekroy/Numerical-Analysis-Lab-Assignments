#include<stdio.h>
#include<math.h>

#define absmax(x,y) (fabs(x)>fabs(y))?fabs(x):fabs(y)

#define f1(x,y)  (x*x+x*y-10)
#define f2(x,y) (y+3*x*y*y-57);
#define df1dx(x,y) (2*x+y)
#define df1dy(x,y) x
#define df2dx(x,y) (3*y*y)
#define df2dy(x,y) (1+6*x*y)

int main(void){
    float x,y,a,b,c,d,e,f,dx,dy;//Initialising Variables
    int i;
    x=1;
    y=0.1;//Initial Guesses for X and Y
    i=0;
    
    printf("Iter.\t  x\t\ty\t\tdx\t\tdy\n");
    
    do{
        a=df1dx(x,y);
        b=df1dy(x,y);
        c=df2dx(x,y);
        d=df2dy(x,y);
        e=f1(x,y);
        f=f2(x,y);
        dx=(b*f-e*d)/(b*c-a*d);//calculating delta(x)
        dy=(c*e-a*f)/(b*c-a*d);//Calculating delta(y)
        x-=dx;
        y-=dy;
        
        printf("%d\t%f\t%f\t%f\t%f\n",i,x,y,dx,dy);
        
        i++;
    
    }while( absmax(dx,dy)>=0.000005);//Terminating condition

    printf("\n\nThe solutions are: x = %f & y = %f .\n",x,y);
    
return 0;
}

