#include <stdio.h>
#include <stdlib.h>

int main() {
    double P[2][2];
    
    printf("Enter the transition matrix (e.g. 0.7 0.3 0.4 0.6 for a 2x2 matrix):\n");
    scanf("%lf %lf %lf %lf", &P[0][0], &P[0][1], &P[1][0], &P[1][1]);

    printf("Transition matrix:\n");
    printf("%f %f\n", P[0][0], P[0][1]);
    printf("%f %f\n", P[1][0], P[1][1]);

    double x, y;
    printf("Enter the current state matrix (e.g. 1 0 for state 1):\n");
    scanf("%lf %lf", &x, &y);

    int n;
    printf("Enter the number of steps to generate:\n");
    scanf("%d", &n);

    printf("State sequence probabilities:\n");
    printf("%f %f\n", x, y);
    for(int i = 1; i <= n; i++) {
        double new_x = P[0][0] * x + P[0][1] * y;
        double new_y = P[1][0] * x + P[1][1] * y;

        // Normalize the probabilities to ensure their sum is 1
        double sum = new_x + new_y;
        if (sum != 0) {
            new_x /= sum;
            new_y /= sum;
        }

        printf("%f %f\n", new_x, new_y);

        x = new_x;
        y = new_y;
    }

    return 0;
}
