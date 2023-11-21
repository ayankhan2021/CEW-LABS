#include <stdio.h>
#include <string.h>

int searching(int *arr,int size,int val){
    for (int i=0; i<size; i++){
        if (*(arr+i)== val){
            return i;
        }
    }
    return -1;
}
int main(){
    int a;
    printf("Enter the size of array.");
    scanf("%d", &a);
    int myarr[a];
    printf("Enter the %dth element.\n");
    for(int i=0;i<=a-1;i++){
    printf("Element %d:", i+1);
    scanf("%d", &myarr[i]);
    }
    int key;
    printf("Enter the element you want to search.");
    scanf("%d", &key);
    int b = searching(myarr, a, key);

    if (b != -1) {
        printf("Element %d found at index %d.\n", key, b);
    }
    else {
        printf("Element %d not found in the array.\n", key);
    }
}
