#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
// Constants for the linear congruential generator 
#define A 1664525 
#define C 1013904223 
#define M 4294967296        
int main () { 
int num_points; 
// 2^32 
// Prompt the user for the number of sample points 
printf("Enter the number of sample points: ");  
scanf("%d", &num_points); 
unsigned int seed = 123456789; // Initial seed value 
int count_inside_circle = 0; 
for (int i = 0; i < num_points; i++) { 
// Linear Congruential Generator 
seed = (A * seed + C) % M; 
double x = (double)seed / (double)M;   
// Generate the second random number 
seed = (A * seed + C) % M; 
double y = (double)seed / (double)M; 
if (x * x + y * y <= 1.0) { 
count_inside_circle++; 
} 
} 
double pi_estimate = 4.0 * (double)count_inside_circle / (double)num_points; 
printf("Estimated value of Pi: %f\n", pi_estimate); 
return 0; 
} 

