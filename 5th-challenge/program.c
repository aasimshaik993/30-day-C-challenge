#include <stdio.h>
#include <math.h>
int main(){
int operation;
do {
	printf("Enter the operation you would like to perform: \n");
	printf("Enter 1 for solving a linear equation\n");
	printf("Enter 2 for solving the factorial for a number\n");
	printf("Enter 3 for solving a quadratic equation\n");
	printf("Enter 0 to exit\n");
		scanf("%d", &operation);
if (operation == 1) {
float a, b, x;
	printf("The linear equation is of the form ax + b = 0\n");
	printf("Enter the value of a and b: ");
		scanf("%f %f", &a, &b);
	x = (-b) / a;
	if (a == 0) {
		printf("The linear equation has no solution or infinitely many solutions\n");
			}
	else if (x == 0 || x < 0 || x > 0) {
		printf("Value of variable x is: %.2f\n", x);
						}
			}
if (operation == 2) {
int i, n, factorial = 1;
	printf("Enter a number n from 0 through 12 which you want to find the factorial for: ");
		scanf("%d", &n);
	if (n > 0 && n <= 12) {
		for (i = 1; i <= n; i++) {
			factorial *= i;
						}
		printf("The factorial for the given number is: %d\n", factorial);
				}
			}
if (operation == 3) {
float a, b, c, d, root1, root2;
	printf("The quadratic equation is of the form ax*x+bx+c=0\n");
	printf("Enter the values of the coefficients a, b and c repspectively: \n");
		scanf("%f %f %f", &a, &b, &c);
	if (a == 0) {
		printf("Invalid input because a can't be zero\n");
			}
	d = b * b - 4 * a * c;
	if (d > 0) {
		root1=((-b) + (sqrt(d)))/(2*a);
		root2=((-b) - (sqrt(d)))/(2*a);
		printf("Roots are real and distinct\n");
		printf("Root 1 = %f\n", root1);
		printf("Root 2 = %f\n", root2);
			}
	else if (d == 0) {
		root1 = root2 = -b/2*a;
		printf("Roots are real and equal\n");
		printf("Root 1 and root 2 are: %f, %f\n", root1, root2);
				}
	else {
		printf("Roots are imaginary\n");
		}
			}
if (operation == 0) {
	break;
			}
	}
while (operation != 0);
return 0;
}
