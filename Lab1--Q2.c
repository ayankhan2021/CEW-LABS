#include <stdio.h>

int main(){
    float h, w, perimeter, area;

    printf("Enter the height of rectangle: ");
    scanf("%f", &h);

    printf("Enter the width of rectangle: ");
    scanf("%f", &w);

    perimeter = 2*(h + w);

    area = h*w;

    printf("Perimeter of the rectangle: %.2f units\n", perimeter);
    printf("Area of the rectangle: %.2f square units\n", area);

    return 0;
}
