/* 
Write a program to find the approximate value of the root of the equation
x^3 - 5x + 1 = 0
lying between 0 and 1 by Regula-Falsi method, correct up to four decimal places.
*/
#include<stdio.h>
#include<math.h>
float f(float x){
	return x*x*x - 5*x + 1;
}
int main()
{
	float a = 0, b = 1,c;
	float error;
	do{
		c = (a*f(b)-b*f(a))/(f(b)-f(a));
		if (f(a)*f(c)<0)
			b=c;
		else
			a=c;
		error = fabs(f(c));
		
	}while(error>0.0001);
	printf("\nApproximate Root=%.4f",c);
	return 0;
}

