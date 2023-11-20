#include <stdio.h>
#include <string.h>

int reversestr(char *str){
    int length = strlen(str);
    for (int i=length-1;i>=0;i--){
        printf("%c", *(str+i));
    }
}
int main(){
    char inputstring[50];
    printf("Enter a string:\n");
    fgets(inputstring,sizeof(inputstring),stdin);

    inputstring[strcspn(inputstring,"\n")] = '\0';
    reversestr(inputstring);
}
