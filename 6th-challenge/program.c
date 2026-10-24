#include <stdio.h>
int main(){
int n, a[12], i, sum=0, max, min, max2, count=0, maxrun=1, currentrun=1, k, k1, temp, r, d, divcount=0;
float avg;
do {
	printf("Enter the number of activity readings (5 to 12 only): ");
		scanf("%d", &n);
	if (n < 5 || n > 12) {
		printf("Invalid input. Please enter again: ");
				}
	} while(n < 5 || n > 12);
printf("Enter %d readings from 0 through 1000: \n", n);
for (i = 0; i < n; i++) {
	do {
		printf("Reading %d: ", i+1);
			scanf("%d", &a[i]);
		if (a[i] < 0 || a[i] > 1000) printf("Invalid input. Please enter again: ");
		} while(a[i] < 0 || a[i] > 1000);
				}
printf("Original Readings:\n");
for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
				}
printf("\n");
max = a[0];
min = a[0];
for (i = 0; i < n; i++) {
	sum += a[i];
	if (a[i] > max) max = a[i];
	if (a[i] < min) min = a[i];
				}
avg = sum/n;
printf("Sum of readings is: %d\n", sum);
printf("Average of the readings is: %.2f\n", avg);
printf("Maximum: %d\n", max);
printf("Minimum: %d\n", min);
max2 = -1;
for (i = 0; i < n; i++) {
	if (a[i] > max2 && a[i] != max) max2 = a[i];
				}
if (max2 != -1) printf("Second largest reading is: %d\n", max2);
if (max2 == -1) printf("Second largest value doesn't exist\n");
for (i = 1; i < n-1; i++) {
	if (a[i] > a[i-1] && a[i] > a[i+1]) count++;
				}
printf("Number of local peaks is: %d\n", count);
for (i = 1; i < n; i++) {
	if (a[i] > a[i - 1]) {
		currentrun++;
		if (currentrun > maxrun) maxrun = currentrun;
				}
	else currentrun = 1;
				}
printf("The length of the longest increasing contiguous run is: %d\n", maxrun);
printf("Enter shift amount (positive for right and negative for left): ");
scanf("%d", &k);
k1 = (((k % n) + n) % n);
for (k = 0; k < k1; k++) {
	temp = a[n-1];
	for (i = n-1; i > 0; i--) {
		a[i] = a[i-1];
					}
	a[0] = temp;
				}
printf("Rotated array: ");
for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
				}
printf("\n");
printf("Enter the last two digits of your registration number: ");
scanf("%d", &r);
d = (r % 9) + 1;
for (i = 0; i < n; i++) {
	if (a[i] % d == 0) divcount++;
				}
printf("The value of d is: %d\n", d);
printf("The number of elements of the rotated array divisible by %d is: %d\n", d, divcount);
return 0;
}

