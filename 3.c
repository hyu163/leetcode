#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int i,j,k,n;
    int max_length = 0;
    int flag = 0;
    for (i=0; i<len; i++) {
        //find substring withou repeating char
        printf("++ i:%d %c\n", i, s[i]);
        flag = 0;
        
        for (j=i+1; j<len; j++){
            //s[j] current added character
            printf("   j:%d %c\n", j, s[j]);

            //check added character with pre chars
            n = 0;
            for (k=i; k<j; k++){
                printf("%c ", s[k]);
                if (s[j] == s[k]) {
                    printf("Same Exit\n");
                    flag = 1;
                    break;
                }else{
                    n++;
                }
            }

            n++;
            printf("%c // N:%d \n", s[j], n);

            if (n > max_length) 
                max_length=n;

            if (flag == 1) {
                break;
            }

        }
    }
    
    return max_length;
}

int main(int argc, char * argv[]){
    int n;
    n = lengthOfLongestSubstring(argv[1]);
    printf("%d\n", n);
    return 0;
}