#include <stdio.h>
#include <string.h>


int main(){
    int a;
    printf("Enter the size of array.");
    scanf("%d", &a);
    int myarr[a];
    int *ptr = &myarr;
    printf("Enter the %dth element.\n");

    for(int i=0;i<=a-1;i++){
        printf("Element %d:", i+1);
        scanf("%d", &(*(ptr+i)));
    }
    for (int i=0;i<=a-1;i++){
        printf("%d ", *(myarr+i));
    }
}
