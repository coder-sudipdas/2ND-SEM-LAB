// Newton Forward Interpolation
#include<stdio.h>
#include<math.h>
#define N 20
int main()
{
	float h,f,p,d,s;
	float x[N],y[N];
	int i,j,n;
	printf("\nEnter the value of n(number of terms you want to enter):");
	scanf("%d",&n);
	printf("\nEnter the elements of x:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%f",&x[i]);
	}
	printf("\nEnter the elements of y:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%f",&y[i]);
	}
	h=x[2]-x[1];
	printf("\nPlease enter the value of x for which you want to print y:\n");
	scanf("%f",&f);
	p=1;
	d=y[1];
	s=(f-x[1])/h;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=(n-i);j++)
		{
			y[j]=y[j+1]-y[j];
		}
		p=p*(s-i+1)/i;
		d=d+p*y[1];
	}
	printf("\nFor the value of x(%f) the value of y is %0.4f",f,d);
	return 0;
	
	
}
