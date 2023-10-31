#include <stdio.h>
int main(){
    int len, count;
    printf("Enter the length of an array: ");
    scanf("%d", &len);
    int arr[len];
    for(int i = 0; i<len; i++){
        printf("Enter element#%d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The unique elements in your array are:\n");
    for(int i = 0; i<len; i++){
        count = 0;
        for(int j = 0; j<len; j++)
            if(arr[i]==arr[j])
                count++;
        if(count==1){
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
