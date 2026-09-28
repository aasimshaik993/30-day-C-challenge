#include <stdio.h>
int main(){
float fuel,distance,mileage,fuel_price,total_fuel_price;
printf("Enter price of fuel per litre:\n");
scanf("%f", &fuel_price);
printf("Enter mileage of the vehicle in km/litre:\n");
scanf("%f", &mileage);
printf("Enter total distance of the trip in km:\n"); //the distance covered on the whole trip
scanf("%f", &distance);
fuel=distance/mileage;
total_fuel_price=fuel*fuel_price;
printf("The fuel consumed is: %f litres\n", fuel);
printf("The total cost for the fuel is: %f rupees\n", total_fuel_price);
return 0;
}
