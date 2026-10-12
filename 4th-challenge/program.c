#include <stdio.h>
int main(){
float expense, small_total = 0, medium_total = 0, large_total = 0, total_expenses = 0;
int small_count = 0, medium_count = 0, large_count = 0, total_count = 0;
do {
        printf("Enter expense amount (0 to stop): \n");
                scanf("%f", &expense);
        if (expense == 0) { break; }
        if (expense<0) {
                printf("Invalid amount. Enter Again: \n");
                        scanf("%f", &expense);
        }
if (expense>0) {
        total_count++;
        total_expenses += expense;
        }
if (expense>0 && expense<100) {
        small_count++;
        small_total += expense;
        }
if (expense>=100 && expense<500) {
        medium_count++;
        medium_total += expense;
        }
if (expense>=500) {
        large_count++;
        large_total += expense;
        }       }
while (expense != 0);
if (total_count>0) {
 printf("EXPENSE SUMMARY:\n");
 printf("No. of valid expenses: %d\n", total_count);
 printf("Total of valid expenses: %f\n", total_expenses);
 printf("Small expenses: count = %d total = %f\n", small_count, small_total);
 printf("Medium expenses: count = %d total = %f\n", medium_count, medium_total);
 printf("Large expenses: count = %d total = %f\n", large_count, large_total);
 printf("Average valid expense: %f\n", total_expenses/total_count);
        }
else {
 printf("No valid expenses were entered\n");
        }
return 0;
                }
