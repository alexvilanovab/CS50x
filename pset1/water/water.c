#include <cs50.h>
#include <stdio.h>


int main(void){
    printf("Minutes: ");
    printf("Bottles: %i\n", get_int() * 192 / 16);
}