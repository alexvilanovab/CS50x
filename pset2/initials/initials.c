#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void){
    string name = get_string();
    
    if(name[0] != ' '){
        printf("%c", toupper(name[0]));
    }
    
    for (int i = 1; i < strlen(name); i++){
        if(name[i - 1] == ' ' && name[i] != ' '){
            printf("%c", toupper(name[i]));
        }
    }
    
    printf("\n");
}