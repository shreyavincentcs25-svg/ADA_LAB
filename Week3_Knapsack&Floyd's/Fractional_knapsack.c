#include <stdio.h>
int main() {
    int n;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    int p[n], w[n];
    float x[n], ratio[n];
    printf("Enter profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    int M;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);
    float P = 0;
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)p[i] / w[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                int t1 = p[i];
                p[i] = p[j];
                p[j] = t1;
                int t2 = w[i];
                w[i] = w[j];
                w[j] = t2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (w[i] <= M) {
            x[i] = 1;
            M = M - w[i];
            P = P + p[i];
        } else {
            x[i] = (float)M / w[i];
            P = P + p[i] * x[i];
            M = 0;
            break;
        }
    }
    printf("\nFractions taken (x[i]):\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\nMaximum Profit = %.2f\n", P);
    return 0;
}