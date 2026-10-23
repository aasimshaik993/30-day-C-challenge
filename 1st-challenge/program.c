//Problem: A student has marks for five subjects. Write a C program to read the marks of all five subjects and calculate the total marks, average marks, and percentage. Display all three results clearly.
#include <stdio.h>

int main()
{
int s1,s2,s3,s4,s5;
float total,average,percentage;

        printf("Enter marks of sub1, sub2, sub3, sub4 and sub5 respectively:\n");
        scanf("%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5);

total=s1+s2+s3+s4+s5;
average=total/5;
percentage=(total/500)*100; //maximum marks per subject is 100

        printf("The total marks in all five subjects combined is:%f\n", total);
        printf("The average mark of the marks of five subjects is:%f\n", average);
        printf("The percentage for the total marks is:%f\n", percentage);

return 0;
}
