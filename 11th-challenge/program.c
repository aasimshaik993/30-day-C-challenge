#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay);
void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays, int *totalExcess, int *spikeDays, int *alertDays);
void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES], int spikeByZone[ZONES], int alertByZone[ZONES]);
void rankZones(int excessByZone[ZONES]);
void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES]);

const char* getZoneName(int zoneIndex){
switch(zoneIndex){
case 0: return "Academic Block";
case 1: return "Hostel";
case 2: return "Library";
case 3: return "Cafeteria";
case 4: return "Sports Complex";
default: return "Invalid";
}
}

int main(){
int usage[ZONES][DAYS], dailyTarget[ZONES], excessByZone[ZONES] = {0}, overLimitByZone[ZONES] = {0}, spikeByZone[ZONES] = {0}, alertByZone[ZONES] = {0}, reportGenerated = 0, choice=0;
printf("--- WATERWISE ---\n");
inputWaterData(usage, dailyTarget);
while(choice != 5){
printf("PROGRAM MENU:\n");
printf("1. Display water data\n");
printf("2. Generate audit report\n");
printf("3. Rank zones by excess\n");
printf("4. Conservation actions\n");
printf("5. Exit\n");
printf("Enter option: ");
scanf("%d", &choice);
if(choice == 1){
displayWaterData(usage, dailyTarget);
}
else if(choice == 2){
generateAuditReport(usage, dailyTarget, excessByZone, overLimitByZone, spikeByZone, alertByZone);
reportGenerated = 1;
}
else if(choice == 3){
if(reportGenerated == 1) rankZones(excessByZone);
else printf("Please generate the ausit report first.\n");
}
else if(choice == 4){
if(reportGenerated == 1) displayConservationActions(overLimitByZone, spikeByZone, excessByZone);
else printf("Please generate the audit report first.\n");
}
else if(choice == 5){
printf("Exiting the program.\n");
}
else printf("Invalid option. Enter number between 1 and 5.\n");
}
return 0;
}

void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]){
int value;
for(int i=0; i<ZONES; i++){
printf("Enter data for %s:\n", getZoneName(i));
printf("Enter daily target (100 to 50000 litres): ");
scanf("%d", &dailyTarget[i]);
while(dailyTarget[i]<100 || dailyTarget[i]>50000){
printf("Invalid target. Enter again: ");
scanf("%d", &dailyTarget[i]);
}
for(int j=0; j<DAYS; j++){
printf("Day %d consumption (0 to 50000 litres): ", j+1);
scanf("%d", &usage[i][j]);
while(usage[i][j]<0 || usage[i][j]>50000){
printf("Invalid reading. Enter again: ");
scanf("%d", &usage[i][j]);
}
}
printf("\n");
}
}

void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]){
printf("WEEKLY WATER CONSUMPTION\n");
for(int i=0; i<ZONES; i++){
printf("ZONE: %s\n", getZoneName(i));
printf("DAILY TARGET: %d litres\n", dailyTarget[i]);
for(int j=0; j<DAYS; j++){
printf("Day %d: %d litres\n", j+1, usage[i][j]);
}
}
}

void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay){
*total = 0;
*peakUsage = *zoneUsage;
*peakDay = 1;
for(int i=0; i<DAYS; i++){
*total += *(zoneUsage + i);
if(*(zoneUsage + i) > *peakUsage){
*peakUsage = *(zoneUsage + i);
*peakDay = i+1;
}
}
*average = (float)(*total)/DAYS;
}

void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays, int *totalExcess, int *spikeDays, int *alertDays){
int current, isOver, isSpike;
*overLimitDays = 0;
*totalExcess = 0;
*spikeDays = 0;
*alertDays = 0;
for(int i=0; i<DAYS; i++){
current = *(zoneUsage + i);
isOver = 0;
isSpike = 0;
if(current > dailyTarget){
isOver = 1;
(*overLimitDays)++;
*totalExcess += (current - dailyTarget);
}
if(i > 0 && current > *(zoneUsage + i - 1) * 1.40){
isSpike = 1;
(*spikeDays)++;
}
if(isOver == 1 || isSpike == 1){
(*alertDays)++;
}
}
}

void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES], int spikeByZone[ZONES], int alertByZone[ZONES]){

int total, peakUsage, peakDay;
float average;
for(int i=0; i<ZONES; i++){
calculateZoneStats(&usage[i][0], &total, &average, &peakUsage, &peakDay);
detectWaterAlerts(&usage[i][0], dailyTarget[i], &overLimitByZone[i], &excessByZone[i], &spikeByZone[i], &alertByZone[i]);
printf("ZONE: %s\n", getZoneName(i));
printf("Total: %d L\n", total);
printf("Average: %.2f L\n", average);
printf("Peak: %d L (Day %d)\n", peakUsage, peakDay);
printf("Over limit days: %d\n", overLimitByZone[i]);
printf("Spike days: %d\n", spikeByZone[i]);
printf("Alerts: %d\n", alertByZone[i]);
printf("Total excess: %d L\n", excessByZone[i]);
}
}

void rankZones(int excessByZone[ZONES]){
int rank, max_excess = 0;
for(int i=0; i<ZONES; i++){
if(excessByZone[i] > max_excess){
max_excess = excessByZone[i];
}
}
if(max_excess == 0) printf("All zones are within their targets.\n");
else{
printf("Highest excess %d L: ", max_excess);
for(int i=0; i<ZONES; i++){
if(excessByZone[i] == max_excess){
printf("%s\n", getZoneName(i));
}
}
}
printf("RANKINGS: \n");
for(int i=1; i<=ZONES; i++){
for(int j=0; j<ZONES; j++){
rank = 1;
for(int k=0; k<ZONES; k++){
if(excessByZone[k] > excessByZone[j]){
rank++;
}
}
if(rank == i){
printf("Rank %d: %s (%d L)\n", i, getZoneName(j), excessByZone[j]);
}
}
}
}

void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES]){
for(int i=0; i<ZONES; i++){
printf("ZONE: %s (excess: %d L)\n", getZoneName(i), excessByZone[i]);
if(spikeByZone[i] > 0) printf("Check for a leak or unexpected use.\n");
if(overLimitByZone[i] >= 3) printf("Prioritise a water audit and reduction plan.\n");
if(overLimitByZone[i] == 1 || overLimitByZone[i] == 2) printf("Monitor those days and inspect taps or valves.\n");
if(overLimitByZone[i] == 0 && spikeByZone[i] == 0) printf("Maintain current good practices.\n");
}
}
