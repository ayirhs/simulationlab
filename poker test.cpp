#include <stdio.h> 
#include <math.h> 
int main() { 
int N; // Total number of three-digit numbers 
int observed_three_diff; // Observed frequency of numbers with three different digits
int observed_one_pair; // Observed frequency of numbers with exactly one pair of like digits 
int observed_three_like; // Observed frequency of numbers with three like digits 
double chi_square_critical; // Critical value for chi-square test 
// Taking input from the user 
printf("Enter the total number of three-digit numbers (N): "); 
scanf("%d", &N); 
printf("Enter the observed frequency of numbers with three different digits: "); 
scanf("%d", &observed_three_diff); 
printf("Enter the observed frequency of numbers with exactly one pair of like digits: "); 
scanf("%d", &observed_one_pair); 
printf("Enter the observed frequency of numbers with three like digits: "); 
scanf("%d", &observed_three_like); 
printf("Enter the critical value for the chi-square test: "); 
scanf("%lf", &chi_square_critical); 
// Probabilities based on the provided image 
double p_three_diff = 0.72; 
double p_one_pair = 0.27; 
double p_three_like = 0.01; 
// Expected frequencies based on the probabilities 
double expected_three_diff = N * p_three_diff; 
double expected_one_pair = N * p_one_pair; 
double expected_three_like = N * p_three_like; 
// Compute the chi-square statistic 
double chi_square = 0; 
chi_square += pow(observed_three_diff - expected_three_diff, 2) / expected_three_diff; 
chi_square += pow(observed_one_pair - expected_one_pair, 2) / expected_one_pair; 
chi_square += pow(observed_three_like - expected_three_like, 2) / expected_three_like;
// Print the results 
printf("Chi-square statistic: %f\n", chi_square); 
if (chi_square < chi_square_critical) { 
printf("The test passed (i.e., the numbers appear to be independent).\n"); 
} else { 
printf("The test failed (i.e., the numbers do not appear to be independent).\n"); 
} 
return 0; 
} 
