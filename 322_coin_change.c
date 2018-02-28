#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ** f;

int minimize_coins(int * coins, int idx, int amount){
    int a,b,c, min;

    if (amount == 0){
        return 0;
    }

    if (amount < 0){
        return -1;
    }

    if (idx < 0){
        return -1;
    }

    if (f[idx][amount] != -2){
        return f[idx][amount];
    }
    
    //select self, then self
    a = minimize_coins(coins, idx, amount-coins[idx]);
    if (a >= 0){
        a = a + 1;
    }
    
    min = a;

    //select self, then next
    b = minimize_coins(coins, idx-1, amount-coins[idx]);
    if (b>=0){
        b = b + 1;
        if (min > 0){
            if (min > b){
                min = b;
            }
        } else {
            min = b;
        }
    }

    //do not select self
    c = minimize_coins(coins, idx-1, amount);
    if ( c>=0 ) {
        if ( min > 0) {
            if (min>c) {
                min=c;
            }
        }else{
            min = c;
        }
    }

    //compare minimum of three values
    f[idx][amount] = min;

    return min;
}

void dump(int coinsSize, int amount){
    int j, i;
    
    for (j=0; j<amount+1; j++){
        printf("%3d ", j);
    }
    printf("\n");

    for (j=0; j<amount+1; j++){
        printf("%3c ", '-');
    }
    printf("\n");

    for (i=0; i<coinsSize; i++){
        for (j=0; j<amount+1; j++){
            printf("%3d ", f[i][j]);
        }
        printf("\n");
    }

}

int coinChange(int* coins, int coinsSize, int amount) {
    int result;
    if (amount == 0){
        return 0;
    }

    int i,j;
    f = (int **) malloc(sizeof(int *)*coinsSize);
    for (i=0; i<coinsSize; i++){
        f[i] = (int *) malloc(sizeof(int)*(amount+1));
    }

    for (i=0; i<coinsSize; i++){
        for (j=0; j<amount+1; j++){
            f[i][j] = -2;
        }
    }

    result = minimize_coins(coins, coinsSize-1, amount);

    dump(coinsSize, amount);

    return result;
}

int main(int argc, char * argv[]){
    int coins[] = {1,2,5};
    int amount = 11;
    int result;
    result = coinChange(coins, 3, amount);
    printf("%d\n", result);
    return 0;
}