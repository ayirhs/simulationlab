#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
// Function to calculate D+ 
double dplus(double num[], double d1[], int length, double n) { 
for (int i = 0; i < length; i++) { 
d1[i] = ((i + 1) / n) - num[i]; 
} 
double d1max = d1[0]; 
for (int i = 0; i < length; i++) { 
if (d1max <= d1[i]) { 
d1max = d1[i]; 
} 
} 
return d1max; 
} 
// Function to calculate D- 
double dminus(double num[], double d2[], int length, double n) { 
for (int i = 0; i < length; i++) { 
d2[i] = num[i] - (i / n); 
} 
double d2max = d2[0]; 
for (int i = 0; i < length; i++) { 
if (d2max <= d2[i]) { 
d2max = d2[i]; 
} 
} 
return d2max; 
 
} 
// Kolmogorov-Smirnov Test function 
void kst(double num[], int length, double d_critical) { 
// Sorting the array 
for (int i = 0; i < length; i++) { 
for (int j = i + 1; j < length; j++) { 
if (num[i] > num[j]) { 
double temp = num[i]; 
num[i] = num[j]; 
num[j] = temp; 
} 
} 
} 
double d1[length]; 
double d2[length]; 
double n = (double) length; 
double d1max = dplus(num, d1, length, n); 
double d2max = dminus(num, d2, length, n); 
double d = (d1max > d2max) ? d1max : d2max; 
printf("D = %f\n", d); 
// Hypothesis Testing 
printf("D_critical = %f\n", d_critical); 
if (d > d_critical) { 
printf("Null hypothesis rejected.\n"); 
} else { 
printf("Null hypothesis accepted.\n"); 
} 

} 
int main() { 
printf("Kolmogorov Test\n"); 
int n; 
printf("Enter number of elements to compute for test: \t"); 
scanf("%d", &n); 
double num[n]; 
printf("Enter the elements:\n"); 
for (int i = 0; i < n; i++) { 
scanf("%lf", &num[i]); 
} 
double d_critical; 
printf("Enter the tabulated value of D_alpha: "); 
scanf("%lf", &d_critical); 
kst(num, n, d_critical); 
return 0; 
}
