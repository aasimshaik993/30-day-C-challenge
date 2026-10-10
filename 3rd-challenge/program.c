#include <stdio.h>
int main()
{
int customer_type;
float initial_amount, discount_percentage, discount_amount, amount_after_discount, distance, delivery_charge, final_amount;
        printf("Enter customer type(1 for student, 2 for regular customer): ");
                scanf("%d", &customer_type);
        printf("Enter initial amount: ");
                scanf("%f", &initial_amount);
        printf("Enter distance: ");
                scanf("%f", &distance);
if (customer_type == 1) {
        if (initial_amount >= 2000) {discount_percentage = 15.0;}
        else {discount_percentage = 10.0;}
                        }
else if (customer_type == 2) {
        if (initial_amount >= 3000) {discount_percentage = 8.0;}
        else {discount_percentage = 0;}
                                }
else { printf("Invalid customer type entered\n"); }
                        discount_amount = initial_amount * (discount_percentage / 100);
                        amount_after_discount = initial_amount - discount_amount;
if (distance > 0 && distance <= 5.0) {delivery_charge = 40;}
else if (distance > 5.0 && distance <= 15.0) {delivery_charge = 70;}
else if (distance > 15.0) {delivery_charge = 100;}
else { printf("Invalid distance\n"); }
                        final_amount = amount_after_discount + delivery_charge;
        printf("Initial amount is: %.2f\n", initial_amount);
        printf("Discount amount is: %.2f\n", discount_amount);
        printf("Amount after discount is: %.2f\n", amount_after_discount);
        printf("Delivery charge is: %.2f\n", delivery_charge);
        printf("Final payable amount is: %.2f\n", final_amount);
return 0;
                }
