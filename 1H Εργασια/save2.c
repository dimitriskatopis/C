#include <stdio.h>
#include <math.h>

double fun (double x )
{
return  pow(x,3)+x+1;


}


double integrate(double a,double b,int N)
{
	float sum,fxi[N], x[N],  e[N];
	int i ,   x0, xN  ;
	double fun(double);
	x0=a;
	xN=b;
	sum=0;
	
	for(i=0; i<=N ;i++)
	{
		x[i]=x0+i*(b-a)/N;
		fxi[i]=fun(x[i]);
		e[i]=(fxi[i-1]+fxi[i])*(x[i]-x[i-1])/2;
		sum=sum+e[i];
	} 
	
	return  sum;
	
}

int main()
{
	int a, b, N;
	double x;

	do
	{
		printf("dwse a: ");
		scanf("%d",&a);
		printf("dwse b: ");
		scanf("%d",&b);
	}
	while(b<a);
	printf("dwse diasthmata N: ");
	scanf("%d", &N);
	x=integrate(a,b,N);
	printf("emvado=%lf",x);
	return 0;
}