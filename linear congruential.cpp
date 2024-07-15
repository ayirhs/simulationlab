#include <stdio.h> 
#define MAX 50 
int main() { 
int i, n, a, seed, c, m, r[MAX]; 
printf("How many random numbers you want to generate: "); 
scanf("%d", &n); 
printf("Enter value of a: "); 
scanf("%d", &a); 
printf("Enter value of c: "); 
scanf("%d", &c); 
printf("Enter value of m: "); 
scanf("%d", &m); 
printf("Enter seed value: "); 
scanf("%d", &r[0]); 
// Check the value of c and print the corresponding message 
if (c != 0) { 
printf("c is not equal to 0   -> Mixed Congruential Method \n"); 
} else { 
printf("c=0  -> Multiplicative Congruential Method \n"); 
} 
for (i = 1; i <= n; i++) { 
r[i] = (a * r[i - 1] + c) % m; 
} 
printf("The random numbers are:\n"); 
for (i = 1; i <= n; i++) { 
printf("%f\n", (float)r[i] / m); 
} 
return 0; 
} 

