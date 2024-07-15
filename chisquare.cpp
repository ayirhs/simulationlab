#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#define NUM_BINS 10 // number of bins for chi-square test 
int main() { 
int num_random, i; 
double rand_num, expected_frequency, chi_square, chi_critical; 
int observed_frequency[NUM_BINS] = {0}; 
// Ask user for total number of numbers 
printf("Enter total number of numbers: "); 
scanf("%d", &num_random);
double num_sequence[num_random]; 
// Ask user for the number sequence 
printf("Enter the numbers (between 0 and 1):\n"); 
for (i = 0; i < num_random; i++) { 
scanf("%lf", &num_sequence[i]); 
} 
// Count the frequencies in bins 
for (i = 0; i < num_random; i++) { 
if (num_sequence[i] >= 0 && num_sequence[i] < 1) { 
observed_frequency[(int)(num_sequence[i] * NUM_BINS)]++; 
} else { 
printf("Number %f out of range [0, 1). Exiting.\n", num_sequence[i]); 
return 1; 
} 
} 
// Calculate expected frequency and chi-square value 
expected_frequency = (double) num_random / NUM_BINS; 
chi_square = 0.0; 
for (i = 0; i < NUM_BINS; i++) { 
chi_square += pow(observed_frequency[i] - expected_frequency, 2) / expected_frequency;
} 
// Ask user for the critical value of chi-square at the given significance level 
printf("\nEnter the critical value of chi-square: "); 
scanf("%lf", &chi_critical); 
// Print results 

printf("\n\nChi-square value: %f\n", chi_square); 
if (chi_square > chi_critical) { 
printf("The numbers do not pass the chi-square test at the given significance level.\n"); 
printf("Null hypothesis rejected: The distribution is not uniform.\n"); 
} else { 
printf("The numbers pass the chi-square test at the given significance level.\n"); 
printf("Null hypothesis accepted: The distribution is uniform.\n"); 
} 
return 0; 
}
