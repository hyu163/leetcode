#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int i = 0;
    int n[100];
    printf("x:%d\n", x);

    if (x<0) return false;
    
    while (1){
        n[i++] = x%10;
        x = x / 10;
        if (x==0) break;
    }

    int j = 0;
    if (i%2 == 0){
        //even number: check
        printf("even %d\n", i);
        for (j=0; j<i/2; j++){
            printf("%d %d\n", n[j], n[i-1-j]);
            if (n[j] != n[i-1-j])
                return false;
        }
    }else{
        printf("odd %d\n", i);
        //odd number: check
        for (j=0; j<(i-1)/2; j++){
            printf("%d %d\n", n[j], n[i-1-j]);
            if (n[j] != n[i-1-j]){
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char * argv[]){
    bool r;
    r = isPalindrome(atoi(argv[1]));
    printf("%d\n", r);
    return 0;
}