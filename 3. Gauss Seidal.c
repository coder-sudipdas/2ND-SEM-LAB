/*
Write a program to solve the following system of equations using Gauss-Seidel iteration
method.
20x + y - 2z = 17
3x + 20y - z = -18
2x - 3y + 20z = 25
*/
#include<stdio.h>
#include<math.h>
int main()
{
	float x=0,y=0,z=0;
	float x_new,y_new,z_new;
	float error;
	
	do{
		x_new = (17-y+2*z)/20;
		y_new = (-18-3*x_new+z)/20;
		z_new = (25-2*x_new+3*y_new)/20;
		error = fabs(x_new-x)+fabs(y_new-y)+fabs(z_new-z);
		
		x=x_new;
		y=y_new;
		z=z_new;
	}while(error>0.0001);
	printf("\nx = %.4f\ny=%.4f\nz=%.4f",x,y,z);
	return 0;
}
