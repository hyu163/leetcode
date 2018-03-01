#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **f;

#define MIN(a,b) ((a)<=(b))?(a):(b)

int dp(char * word2, char * word1, int n, int m){
    printf("+N:%d M:%d\n",n, m);
    if (n<0 || m<0){
        printf("N:%d M:%d %d (n<0||m<0)\n", n, m, 0);
        return 0;
    }

    if (n==0 && m==0){
        printf("N:%d M:%d %d (n==0&&m==0)\n", n, m, 0);
        return 0;
    }

    if (f[n][m] != -1) {
        printf("N:%d M:%d %d (found on f)\n", n, m, f[n][m]);
        return f[n][m];
    }

    if (word2[n-1] == word1[m-1]){
        //use diagnose
        f[n][m] = dp(word2, word1, n-1, m-1);
        printf("N:%d M:%d %d (w2[n-1]==w1[m-1])\n", n, m, f[n][m]);
    }else{
        int a,b,c, min;
        a = dp(word2, word1, n-1, m);
        b = dp(word2, word1, n-1, m-1);
        c = dp(word2, word1, n, m-1);
        min = MIN(a,MIN(b,c));

        f[n][m] = 1 + min;
        printf("N:%d M:%d %d (w2[n-1]!=w1[m-1]) a:%d b:%d c:%d min:%d \n", 
            n, m, f[n][m], a, b, c, min);
    }

    return f[n][m];
}

void dump(char * word1, char * word2){
    int i,j;
    printf("+- ");
    for (j=0; j<strlen(word1)+1; j++){
        printf("-- ");
    }
    printf("\n");

    printf("   ");
    printf("%2d ", 0);
    for (j=0; j<strlen(word1)+1; j++){
        printf("%2c ", word1[j]);
    }
    printf("\n");

    printf("+- ");
    for (j=0; j<strlen(word1)+1; j++){
        printf("-- ");
    }
    printf("\n");


    for (i=0; i<strlen(word2)+1; i++){
        if (i==0){
            printf("%2d ", 0);
        }else{
            printf("%2c ", word2[i-1]);
        }
        for (j=0; j<strlen(word1)+1; j++){
            printf("%2d ", f[i][j]);
        }
        printf("\n");
    }

    printf("+- ");
    for (j=0; j<strlen(word1)+1; j++){
        printf("-- ");
    }
    printf("\n");

}

int minDistance(char* word1, char* word2) {
    //from word1 to word2
    //word1:columns
    //word2:lines
    int i,j, result;

    if (strlen(word1)==0){
        return strlen(word2);
    }

    if (strlen(word2)==0){
        return strlen(word1);
    }

    f = (int **) malloc(sizeof(int *)*(strlen(word2)+1));
    for (i=0; i<strlen(word2)+1; i++){
        f[i] = (int *) malloc(sizeof(int)*(strlen(word1)+1));
        for (j=0; j<strlen(word1)+1; j++){
            f[i][j] = -1;
        }
    }

    //init zero lines
    for (j=0; j<strlen(word1)+1; j++){
        f[0][j] = j;
    }
    for (i=0; i<strlen(word2)+1; i++){
        f[i][0] = i;
    }

    dump(word1, word2);

    result = dp(word2, word1, strlen(word2), strlen(word1));
    
    dump(word1, word2); 
    return result;

}

int main(int argc, char * argv[]){
    int result;
    char word1[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef";
    char word2[] = "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg";
    result = minDistance(word1, word2);
    printf("%d\n", result);
    return 0;
}