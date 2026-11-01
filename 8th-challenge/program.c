#include <stdio.h>

int main(){
int n, i, j, t;

printf("Enter grid size (3 to 6): ");
scanf("%d", &n);
while(n<3 || n>6){
printf("Invalid grid size. Enter again (3 to 6): ");
scanf("%d", &n);
}

int matrix[n][n];
for(i=0; i<n; i++){
for(j=0; j<n; j++){
printf("Enter risk score for cell (%d, %d): ", i+1, j+1);
scanf("%d", &matrix[i][j]);
while(matrix[i][j]<0 || matrix[i][j]>100){
printf("Invalid risk score. Enter again (0 to 100): ");
scanf("%d", &matrix[i][j]);
}
}
}

printf("The matrix is: \n");
for(i=0; i<n; i++){
for(j=0; j<n; j++){
printf("%d ", matrix[i][j]);
}
printf("\n");
}


printf("Enter warning threshold (0 to 100): ");
scanf("%d", &t);
while(t<0 || t>100){
printf("Invalid warning threshold value. Enter again (0 to 100): ");
scanf("%d", &t);
}

printf("ROW AND COLUMN ANALYSIS: \n");

int row_total[n], max_row_total=-1;
for(i=0; i<n; i++){
row_total[i]=0;
for(j=0; j<n; j++){
row_total[i] += matrix[i][j];
}
printf("Row %d total: %d\n", i+1, row_total[i]);
if(row_total[i] > max_row_total) max_row_total = row_total[i];
}
for(i=0; i<n; i++){
if(row_total[i] == max_row_total) printf("The row with highest total is: row %d\n", i+1);
}
printf("And the highest row total is: %d\n", max_row_total);

int column_total[n], max_column_total=-1;
for(j=0; j<n; j++){
column_total[j]=0;
for(i=0; i<n; i++){
column_total[j] += matrix[i][j];
}
printf("Column %d total: %d\n", j+1, column_total[j]);
if(column_total[j] > max_column_total) max_column_total = column_total[j];
}
for(j=0; j<n; j++){
if(column_total[j] == max_column_total) printf("The column with the highest total is: column %d\n", j+1);
}
printf("And the highest column total is: %d\n", max_column_total);

printf("FULL GRID ANALYSIS: \n");

int max_score=-1, t_count=0;
for(i=0; i<n; i++){
for(j=0; j<n; j++){
if(matrix[i][j] > max_score) max_score = matrix[i][j];
if(matrix[i][j] >= t) t_count++;
}
}
printf("Highest risk score: %d\n", max_score);
printf("Number of positions with highest risk score: ");
for(i=0; i<n; i++){
for(j=0; j<n; j++){
if(matrix[i][j] == max_score) printf("(%d, %d) ", i+1, j+1);
}
}
printf("Number of positions with score >= threshold score: %d\n", t_count);

printf("DIAGONAL ANALYSIS: \n");

int main_diagonal=0, secondary_diagonal=0;
for(i=0; i<n; i++){
main_diagonal += matrix[i][i];
secondary_diagonal += matrix[i][n-1-i];
}
printf("Sum of main diagonal elements: %d\n", main_diagonal);
printf("Sum of secondary diagonal elements: %d\n", secondary_diagonal);
if(main_diagonal == secondary_diagonal) printf("Diagonal totals are balanced\n");
else printf("Diagonal totals are not balanced\n");

printf("BOUNDARY ANALYSIS: \n");

int boundary_total=0;
for(i=0; i<n; i++){
for(j=0; j<n; j++){
if(i==0 || j==0 || i==n-1 || j==n-1) boundary_total += matrix[i][j];
}
}
printf("Total of all elements on the boundary: %d\n", boundary_total);

printf("NEIGHBOUR TRAVERSAL: \n");

int hotspot_count=0, x;
for(i=1; i<n-1; i++){
for(j=1; j<n-1; j++){
x = matrix[i][j];
if(x>=t && x>matrix[i-1][j] && x>matrix[i][j-1] && x>matrix[i+1][j] && matrix[i][j+1]){
printf("Local hotspot found at (%d, %d) with score: %d\n", i+1, j+1, x);
hotspot_count++;
}
}
}
if(hotspot_count==0) printf("No local hotspot has been found\n");

printf("FINAL CONCLUSION: \n");

if(hotspot_count>0) printf("CRITICAL\n");
else if(t_count>=n) printf("WARNING\n");
else printf("NORMAL\n");

return 0;
}












