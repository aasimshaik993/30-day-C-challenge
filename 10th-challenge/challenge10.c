#include <stdio.h>
#define ZONES 5
#define DAYS 7

void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]){
int i, j;
for(i=0; i<ZONES; i++){
printf("Enter data for zone %d:\n", i+1);
for(j=0; j<DAYS; j++){
do{
printf("Temperature for day %d (10 - 50): ", j+1);
scanf("%f", &temp[i][j]);
if(temp[i][j]<10 || temp[i][j]>50) printf("Invalid temperature. Enter again. \n");
}while(temp[i][j]<10 || temp[i][j]>50);
do{
printf("Humidity for day %d (0 - 100%): ", j+1);
scanf("%f", &humidity[i][j]);
if(humidity[i][j]<0 || humidity[i][j]>100) printf("Invalid humidity. Enter again. \n");
}while(humidity[i][j]<0 || humidity[i][j]>100);
do{
printf("AQI for day %d (0 - 500): ", j+1);
scanf("%d", &aqi[i][j]);
if(aqi[i][j]<0 || aqi[i][j]>500) printf("Invalid AQI. Enter again. \n");
}while(aqi[i][j]<0 || aqi[i][j]>500);
}
}
}

void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]){
int i, j;
for(i=0; i<ZONES; i++){
printf("ZONE %d: ", i+1);
switch(i){
case 0: printf("Academic Block\n"); break;
case 1: printf("Hostel\n"); break;
case 2: printf("Library\n"); break;
case 3: printf("Cafeteria\n"); break;
case 4: printf("Sports arena\n"); break;
}
for(j=0; j<DAYS; j++){
printf("DAY: %d, TEMPERATURE: %.2f, HUMIDITY: %.2f, AQI: %d\n", j+1, temp[i][j], humidity[i][j], aqi[i][j]);
}
}
}

void calculateAverage(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], float avgTemp[ZONES], float avgHumidity[ZONES], int avgAqi[ZONES]){
int i, j;
for(i=0; i<ZONES; i++){
float temp_sum=0, humidity_sum=0, AQI_sum=0;
for(j=0; j<DAYS; j++){
temp_sum+=temp[i][j];
humidity_sum+=humidity[i][j];
AQI_sum+=aqi[i][j];
}
avgTemp[i]=(temp_sum/DAYS);
avgHumidity[i]=(humidity_sum/DAYS);
avgAqi[i]=(AQI_sum/DAYS);
}
char zoneNames[]= {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports area"};
for(i=0; i<ZONES; j++){
printf("ZONE: %s, AVERAGE TEMPERATURE: %.2f, AVERAGE HUMIDITY: %.2f, AVERAGE AQI: %d\n", zoneNames[i], avgTemp[i], avgHumidity[i], avgAqi[i]);
}
}

void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], int riskDays[ZONES]){
int i, j;
char zoneNames[]= {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports area"};
for(i=0; i<ZONES; i++){
riskDays[i]=0;
for(j=0; j<DAYS; j++){
if(aqi[i][j]>150 || temp[i][j]>35.0 || humidity[i][j]>80.0) riskDays[i]++;
}
printf("%s: %d risk days\n", zoneNames[i], riskDays[i]);
}
}

void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAqi[ZONES], float greenIndex[ZONES]){
int i;
char zoneNames[]= {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports area"};
for(i=0; i<ZONES; i++){
float aqiScore=100.0-(avgAqi[i]/5.0);
if(aqiScore<0) aqiScore=0;
float temptemp=avgTemp[i]-25.0;
if(temptemp<0) temptemp=0;
float tempScore=100.0-(4.0*temptemp);
if(tempScore<0) tempScore=0;
float temphumidity=avgHumidity[i]-50.0;
if(temphumidity<0) temphumidity=0;
float humidityScore=100.0-(2.0*temphumidity);
if(humidityScore<0) humidityScore=0;
greenIndex[i]=(0.4*aqiScore)+(0.3*tempScore)+(0.3*humidityScore);
printf("ZONE NAME: %s, GREEN INDEX: %.2f\n", zoneNames[i], greenIndex[i]);
}
}

void displayRanking(float greenIndex[ZONES]){
int i, j, rank, ranks[ZONES];
char zoneNames[]= {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports area"};
for(i=0; i<ZONES; i++){
rank=1;
for(j=0; j<ZONES; j++){
if(greenIndex[j]>greenIndex[i]) rank++;
}
ranks[i]=rank;
}
for(i=0; i<ZONES; i++){
printf("ZONE: %s, GREEN INDEX: %.2f, RANK: %d\n", zoneNames[i], greenIndex[i], ranks[i]);
}
}

void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAqi[ZONES], int riakDays[ZONES]){
int i;
char zoneNames[]= {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports area"};
for(i=0; i<ZONES; i++){
printf("ZONE: %s, Issue Observed: Avg AQI: %.2f, Avg Temp: %.2f, Avg Humidity: %.2f, Risk Days: %d\n", zoneNames[i], avgAqi[i], avgTemp[i], avgHumidity[i], riskDays[i]);
printf("Proposed action: ");
if(avgAqi[i]>150) printf("Reduce vehicle idling and improve ventilation\n");
if(avgTemp[i]>35) printf("Increase shade and green cover\n");
if(avgHumidity>80) printf("Check ventilation and remove stagnant water sources\n");
if(riskDays[i]>0) printf("Review the dates when risk was observed\n");
else printf("No risk detected. Continue monitoring\n");
}
}

int main(){
float temp[ZONES][DAYS], humidity[ZONES][DAYS], avgTemp[ZONES], avgHumidity[ZONES], avgAqi[ZONES], greenIndex[ZONES];
int aqi[ZONES][DAYS], riskDays[ZONES], dataReady=0, x;
do{
printf("PROGRAM MENU\n");
printf("1. Input data\n");
printf("2. Display Data\n");
printf("3. Zone averages\n");
printf("4. Detect Risk Days\n");
printf("5. Grren Index and Rankings\n");
printf("6. Recommendations\n");
printf("7. Exit\n");
printf("Enter your choice (1-7): ");
scanf("%d", &x);
switch(x){
case 1:
inputData(temp, humidity, aqi);
dataReady=1;
break;
case 2:
if(!dataReady) printf("Data has not been entered yet. Enter data first\n");
else displayData(temp, humidity, aqi);
break;
case 3:
if(!dataReady) printf("Data has not been entered yet. Enter data first\n");
else calculateAverage(temp, humidity, aqi, avgTemp, avghumidity, avgAqi);
break;
case 4:
if(!dataReady) printf("Data has not been entered yet. Enter data first\n");
else detectRiskZones(temp, humidity, aqi, riskDays);
break;
case 5:
if(!dataReady) printf("Data has not been entered yet. enter data first\n");
else{
calculateAverage(temp, humidity, aqi, avgTemp, avgHumidity, avgAqi);
computeGreenIndex(avgTemp, avgHumidity, avgAqi, greenIndex);
displayRanking(greenIndex);
}
break;
case 6:
if(!dataReady) printf("Data has not been entered yet. Enter data first\n");
else{
calculateAverage(temp, humidity, aqi, avgTemp, avgHumidity, avgAqi);
detectRiskZones(temp, humidity, aqi, riskDays);
displayRecommendations(avgTemp, avgHumidity, avgAqi, riskDays);
)
break;
case 7:
printf("Exiting program\n");
break;
default: printf("Invalid choice. Enter a number between 1 and 7\n");
}
}while(x!=7);
return 0;
}
