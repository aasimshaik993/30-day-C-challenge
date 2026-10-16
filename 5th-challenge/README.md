Algorithm:
1. Start.
2. Create a loop which will show this menu: Select the operation that needs to be performed. 1 for solving linear equation. 2 for calculating the factorial. 3 for solving a quadratic equation. 0 to end the program.
3. if operation = 1, linear equation is of the form a(x)+b=0. Ask the user for value of a and b. Calculate the value of x using x=-b/a. Print the value of x.
4. if operation = 2, ask the user for which number the factorial needs to be calculated (number must be between 0 to 12 including 0 and 12). Calculate the factorial. Print the value of the factorial.
5. if operation = 3, quadratic equation is of the form a(x*x)+b(x)+c=0. Ask the user for the value of a, b and c. Calculate the determinant using the formula d=(b*b)-4*a*c.
6. In operation = 3, If d<0 then the roots are imaginary and distinct. Print that roots are imaginary and distinct.
7. In operation = 3, If d=0 then the roots are real and equal so root1=root2=-b/2a. Print that roots are equal and also print the value of the roots.
8. In operation = 3, If d>0 then the roots are real and distinct so root1=(-b+sqrt(d))/2a and root2=(-b-sqrt(d))/2a. Print that roots are real and distinct and also print the value of the roots.
9. If operation = 0 then exit the loop.
10. Stop. 
