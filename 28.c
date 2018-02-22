#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int len_h;
    int len_n;
    int i;

    len_h = strlen(haystack);
    len_n = strlen(needle);

    if (len_h > len_h) return -1;
    
    i = 0;
    while(1){

        if (strncmp(haystack+i, needle, len_n)==0) 
            return i;
        
        i++;

        if (i > len_h-len_n) break;
    }

    return -1;

}

int main(int argc, char * argv[]){
    int i=0;
    i = strStr(argv[1], argv[2]);
    printf("%d\n", i);
    return 0;
}