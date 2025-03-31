#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int first;
    int second;
} Pair;

int main() {
    int n;
    scanf("%d", &n);
    
    Pair *coords = (Pair *)malloc(n * sizeof(Pair));
    if (coords == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        coords[i].first = x;
        coords[i].second = y;
    }

    int x, y, k;
    double points, pointsBelow, pointsDist, pointsAccum, pointsCurr, pointsRest;

    for (int i = 0; i < n; i++) {
        x = coords[i].first;
        y = coords[i].second;

        if (x == 0 && y == 0) {
            printf("1\n");
        } else if (x == -1 && y == 0) {
            printf("2\n");
        } else if (x == 0 && y == 1) {
            printf("3\n");
        } else if (x == 1 && y == 0) {
            printf("4\n");
        } else {
            if (y < 0 && (abs(x) <= 2 * abs(y))) {
                k = 1 - y;
                points = 4 * (k - 1) * (k - 1);
                pointsBelow = 4 * (k - 1) + 2;
                printf("%.0lf\n", points + pointsBelow - pointsBelow / 2 - x);
            } else if (x <= 0) {
                k = y - x;
                pointsAccum = 4 * (k - 1) * (k - 1);
                pointsCurr = 8 * k - 4;
                pointsDist = sqrt(pow(0 - x, 2) + pow(k - y, 2)) / sqrt(2);
                pointsBelow = 4 * (k - 1) + 2;
                pointsRest = (pointsCurr - pointsBelow) / 2;
                printf("%.0lf\n", pointsAccum + pointsBelow + pointsRest - pointsDist);
            } else if (x > 0) {
                k = y + x;
                pointsAccum = 4 * (k - 1) * (k - 1);
                pointsCurr = 8 * k - 4;
                pointsDist = sqrt(pow(0 - x, 2) + pow(k - y, 2)) / sqrt(2);
                pointsBelow = 4 * (k - 1) + 2;
                pointsRest = (pointsCurr - pointsBelow) / 2;
                printf("%.0lf\n", pointsAccum + pointsBelow + pointsRest + pointsDist);
            }
        }
    }
    
    free(coords);
    return 0;
}