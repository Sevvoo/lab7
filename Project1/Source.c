#include <stdio.h>
#include <math.h>

int countIntersectionPoints(double x1, double y1, double r1, double x2, double y2, double r2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Case: One circle inside the other
    if (distance + r2 <= r1 || distance + r1 <= r2)
        return 0;

    // Case: One circle outside the other
    if (distance >= r1 + r2)
        return 0;

    // Case: Identical circles
    if (distance == 0 && r1 == r2)
        return -1;

    // Case: Identical centers but different radii
    if (distance == 0 && r1 != r2)
        return 0;

    // Case: Tangent circles
    if (distance == r1 + r2 || distance == fabs(r1 - r2))
        return 1;

    // Case: Intersection of two circles
    return 2;
}

int main() {
    double x1, y1, r1, x2, y2, r2;

    printf("Enter the coordinates of the center and radius of the first circle (x1, y1, r1): ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);

    printf("Enter the coordinates of the center and radius of the second circle (x2, y2, r2): ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    int intersectionPoints = countIntersectionPoints(x1, y1, r1, x2, y2, r2);

    printf("Number of intersection points: %d\n", intersectionPoints);

    return 0;
}
