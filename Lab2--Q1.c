//Write a C program to display the first n odd natural numbers and their sum using for, while and
//do-while loop.

#include <stdio.h>

int main() {
    int n, i=1;
    int sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);


//    Using For Loop:
    printf("The series is: ");
    for (i;n>=i; i+=2){
        printf("%d ", i);
        sum+=i;
    }
    printf("\nThe sum is : %d\n", sum);

//    Using While Loop

    while(n>=i){
        printf("%d ", i);
        sum+=i;
        i+=2;
    }
    printf("\nThe sum is : %d\n", sum);

//    Using Do-While Loop:

    do{
        printf("%d ", i);
        sum+=i;
        i+=2;
    }while(n>=i);

    printf("\nThe sum is : %d\n", sum);

    return 0;
}
