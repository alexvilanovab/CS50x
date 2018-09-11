#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./caesar k\n");
        exit(1);
    }
    
    int k = atoi(argv[1]);
    printf("plaintext:  ");
    string p = get_string();
    
    printf("ciphertext: ");
    for(int i = 0; i < strlen(p); i++){
        if(isalpha(p[i])){
            if(isupper(p[i])){
                printf("%c", (p[i] - 65 + k) % 26 + 65);
            }else{
                printf("%c", (p[i] - 97 + k) % 26 + 97);
            }
        }else{
            printf("%c", p[i]);
        }
    }
    
    printf("\n");
}