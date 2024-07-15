#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define DICE_SIDES 6 
// Function to roll a dice 
int roll_dice() { 
return (rand() % DICE_SIDES) + 1; 
} 
int main() { 
int num_rolls, i; 
// Seed the random number generator with the current time 
srand(time(NULL)); 
// Ask the user how many times they want to roll the dice
printf("Enter the number of times you want to roll the dice: "); 
scanf("%d", &num_rolls); 
printf("Rolling the dice %d times:\n", num_rolls); 
// Roll the dice the specified number of times 
for (i = 0; i < num_rolls; i++) { 
int result = roll_dice(); 
printf("Roll %d: %d\n", i + 1, result); 
} 
return 0; 
} 
