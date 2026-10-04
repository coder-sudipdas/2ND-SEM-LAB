/*2. Write a program to find a real root of the following equation:
3x - cos x - 1 = 0
using Newton-Raphson method, correct up to four decimal places.*/

#include<stdio.h>
#include<math.h>
double f(double x){return 3*x-cos(x)-1;
}
double df(double x){return 3+sin(x);
}
 int main()
 {	int i;
 	double x0=0.5,x1;
 	double eps=1e-6;
 	int maxIter=100;
 	for(i=0;i<maxIter;i++)
 	{
 		x1 = x0 - f(x0)/df(x0);
 		if(fabs(x1-x0)<eps) break;
 		x0 = x1;
	 }
 	printf("\nRoot = %.6f (%d iterations)\n.",x1,i+1);
 	return 0;
 }
 