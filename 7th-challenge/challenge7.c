#include <stdio.h>
int main(){
int i, n, j, count, duplicate=0, missing=0, duplicate_count=0, missing_count=0, out=0, r, target, target_count=0;
printf("Enter no. of tickets between 5 to 15 (N): ");
scanf("%d", &n);
while(n<5 || n>15){
printf("Invalid input. Enter again: ");
scanf("%d", &n);
}
int ticket[n];
printf("Enter ticket entries\n");
for(i=0; i<n; i++){
printf("ticket %d: ", i+1);
scanf("%d", &ticket[i]);
while(ticket[i]<1 || ticket[i]>n){
printf("Invalid input, enter again: ");
scanf("%d", &ticket[i]);
}
}
printf("The ticket ID sequence is: ");
for(i=0; i<n; i++){
printf("%d ", ticket[i]);
}
printf("\n");
for(i=1; i<=n; i++){
count=0;
for(j=0; j<n; j++){
if(ticket[j]==i) count++;
}
if(count>=2){
duplicate=i;
duplicate_count++;
}
if(count==0){
missing=i;
missing_count++;
}
}
if(duplicate_count != 1 || missing_count !=1) printf("Invalid entries");
if(duplicate_count == 1 && missing_count == 1){
printf("Duplicated ticket ID is: %d\n", duplicate);
printf("Missing ticket ID is: %d\n", missing);
for(i=0; i<n; i++){
for(j=i+1; j<n; j++){
if(ticket[i]>ticket[j]) out++;
}
}
printf("Out of order pairs are: %d\n", out);
printf("Enter the last 2 digits of registration number: ");
scanf("%d", &r);
target=(r%n)+1;
printf("Target ID is: %d\n", target);
printf("Positions of Target ID in the array: ");
for(i=0; i<n; i++){
if(ticket[i]==target){
printf("%d ", i+1);
target_count++;
}
}
printf("\n");
printf("Number of times target ID is present in the array: %d\n", target_count);
}
return 0;
}


