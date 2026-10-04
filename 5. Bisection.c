/*
5. Find a positive root of the following equation using Bisection method correct up to three
decimal places:
x^3 - x - 1 = 0
*/
#include<stdio.h>
#include<math.h>
double f(double x){
	return x*x*x - x - 1;
	
}
int main()
{
	double a,b,c;
	int maxIter = 100;
	double eps = 1e-6;
	a = 1, b = 2;
	if(f(a)*f(b)>=0)
	{
		printf("\nInvalid initial guesses\n");
		return 1;
	}
	for (int i=0;i<maxIter;i++)
	{
		c = (a+b)/2;
		if(f(a)*f(c)<0)
			b = c;
		else
			a = c;
	}
	printf("\nRoot = %.3f",c);
	return 0;
}


