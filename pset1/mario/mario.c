#include <cs50.h>
#include <stdio.h>


int main(void){
    int height, blocks, spaces;
    
    do{
        printf("Height: ");
        height = get_int();
    }while(height > 23 || height < 0);
    
    for(int lines = 1; lines <= height; lines++){
        spaces = height - lines;
        blocks = lines;
        
        for(int i = 0; i < spaces; i++){
            printf(" ");
        }
        
        for(int i = 0; i < blocks; i++){
            printf("#");
        }
        
        printf("  ");
        
        for(int i = 0; i < blocks; i++){
            printf("#");
        }
        
        printf("\n");
    }
}