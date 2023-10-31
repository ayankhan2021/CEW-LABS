#include <stdio.h>

struct Distance {
    int ft; 
    int inch;
};

int main() {
    struct Distance d1, d2;

    printf("Enter the ft and inch of the first distance: ");
    scanf("%d %d", &d1.ft, &d1.inch);

    printf("Enter the ft and inch of the second distance: ");
    scanf("%d %d", &d2.ft, &d2.inch);

    int totalFeet = d1.ft + d2.ft;
    int totalInches = d1.inch + d2.inch;

    if (totalInches >= 12) {
        totalInches -= 12;
        totalFeet++;
    }

    printf("The total distance is: %d'%d\"\n", totalFeet, totalInches);

    return 0;
}
