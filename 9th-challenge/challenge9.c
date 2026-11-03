#include <stdio.h>
#define ROWS 5
#define COLS 8

void initializeSeats(int seats[ROWS][COLS]);
void displaySeats(int seats[ROWS][COLS]);
int bookSeat(int seats[ROWS][COLS], int row, int col);
int cancelSeat(int seats[ROWS][COLS], int row, int col);
int reserveGroup(int seats[ROWS][COLS], int groupSize);
void displayReport(int seats[ROWS][COLS]);

int main(){
int seats[ROWS][COLS], x=-1, row, col, group_size;
initializeSeats(seats);
printf("---SEATSMART---\n");
while(x != 0){
printf("Menu options: \n");
printf("1. Display seats\n");
printf("2. Book a seat\n");
printf("3. Cancel booking\n");
printf("4. Book seats for a group\n");
printf("5. Occupancy report\n");
printf("0. Exit program\n");
printf("Enter your choice: ");
scanf("%d", &x);
switch(x){
case 1:
displaySeats(seats);
break;
case 2:
bookSeat(seats, row, col);
break;
case 3:
cancelSeat(seats, row, col);
break;
case 4:
if(!reserveGroup(seats, group_size)) printf("Group booking failed because of the lack of consecutive seats\n");
break;
case 5:
displayReport(seats);
break;
}
}
return 0;
}

void initializeSeats(int seats[ROWS][COLS]){
int i, j;
for(i=0; i<ROWS; i++){
for(j=0; j<COLS; j++){
seats[i][j]=0;
}
}
}

void displaySeats(int seats[ROWS][COLS]){
int i, j;
printf("Display of seats (1=booked and 0=available):\n");
for(i=0; i<ROWS; i++){
for(j=0; j<COLS; j++){
printf("%d ", seats[i][j]);
}
printf("\n");
}
}

int bookSeat(int seats[ROWS][COLS], int row, int col){
printf("Enter row and seat number for booking: ");
scanf("%d %d", &row, &col);
if(seats[row-1][col-1]==0){
printf("Seat %d-%d booked successfully\n", row, col);
seats[row-1][col-1]=1;
displaySeats(seats);
}
else printf("Failed booking because seat is already boooked.\n");
}

int cancelSeat(int seats[ROWS][COLS], int row, int col){
printf("Enter row and seat number to cancel booking: ");
scanf("%d %d", &row, &col);
if(seats[row-1][col-1]==1){
printf("Booking of seat %d-%d has been cancelled successfully\n", row, col);
seats[row-1][col-1]=0;
displaySeats(seats);
}
else printf("Failed to cancel seat booking because seat wasn't booked in the first place\n");
}

int reserveGroup(int seats[ROWS][COLS], int group_size){
int i, j, free, k;
printf("Enter group size (2-8): ");
scanf("%d", &group_size);
if(group_size<2 || group_size>8){
printf("Invalid input. Group size must be between 2 and 8.\n");
return 0;
}
else{
for(i=0; i<ROWS; i++){
for(j=0; j<=COLS-group_size; j++){
free=1;
for(k=0; k<group_size; k++){
if(seats[i][j+k]!=0){
free=0;
break;
}
}
if(free==1){
for(k=0; k<group_size; k++){
seats[i][j+k]=1;
}
printf("%d seats from seat %d in row %d have been allocated\n", group_size, j+1, i+1);
printf("Group reservation successful\n");
displaySeats(seats);
return 1;
}
}
}
}
return 0;
}

void displayReport(int seats[ROWS][COLS]){
int total_seats=ROWS*COLS, total_booked_seats=0, i, j, total_free_seats=0;
for(i=0; i<ROWS; i++){
for(j=0; j<COLS; j++){
if(seats[i][j]==1) total_booked_seats++;
}
}
total_free_seats=total_seats-total_booked_seats;
float occupancy_percentage=((float)total_booked_seats/total_seats)*100;
printf("---OCCUPANCY REPORT---\n");
printf("Total booked seats: %d\n", total_booked_seats);
printf("Total free seats: %d\n", total_free_seats);
printf("Occupancy percentage: %.2f\n", occupancy_percentage);
}
