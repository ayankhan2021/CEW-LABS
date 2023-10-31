#include <stdio.h>

int main(){
    float height;

    printf("Enter your height (in cm):");
    scanf("%f", &height);

    if (height < 150){
        printf("Dwarf\n");
    } else if (height == 150){
        printf("Average\n");
    } else if (height >= 165) {
        printf("Tall\n");
    }
    return 0;

}
