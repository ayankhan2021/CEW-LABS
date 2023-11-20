#include <stdio.h>
int swap(int *a, int *b);

int main(){
    int x = 10;
    int y = 20;
    printf("The unswapped numbers are %d , %d\n", x, y);
    int *ptr1 = &x;
    int *ptr2 = &y;
    swap(ptr1, ptr2);
    printf("The swapped numbers are %d , %d", x, y);


}
int swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


