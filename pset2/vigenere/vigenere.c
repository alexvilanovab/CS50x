#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./vigenere k\n");
        exit(1);
    }
    
    string k = argv[1];
    for(int i = 0; i < strlen(k); i++){
        if(!isalpha(k[i])){
            printf("k must be composed entirely of alphabetical characters\n");
            exit(1);
        }
    }
    printf("plaintext: ");
    string p = get_string();
    
    printf("ciphertext: ");
    int kindex = 0;
    char kchar;
    int kvalue;
    for(int i = 0; i < strlen(p); i++){
        if(isalpha(p[i])){
            kchar = k[kindex % strlen(k)];
            kindex++;
            if(isupper(kchar)){
                kvalue = kchar - 65;
            }else{
                kvalue = kchar - 97;
            }
            
            if(isupper(p[i])){
                printf("%c", (p[i] - 65 + kvalue) % 26 + 65);
            }else{
                printf("%c", (p[i] - 97 + kvalue) % 26 + 97);
            }
        }else{
            printf("%c", p[i]);
        }
    }
    
    printf("\n");
}