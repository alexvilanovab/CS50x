#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void){
    float dollars;
    int cents;
    int coins = 0;

    printf("O hai! How much change is owed?\n");
    dollars = get_float();
    if(dollars <= 0){
        do{
            printf("How much change is owed?\n");
            dollars = get_float();
        }while(dollars <= 0);
    }

    cents = round(dollars * 100);

    while(cents >= 25){
        cents -= 25;
        coins++;
    }
    while(cents >= 10){
        cents -= 10;
        coins++;
    }
    while(cents >= 5){
        cents -= 5;
        coins++;
    }
    while(cents >= 1){
        cents -= 1;
        coins++;
    }

    printf("%i\n", coins);
}