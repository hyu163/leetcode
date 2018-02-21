#include <stdio.h>
#include <stdlib.h>

//1-3999
//M 1000
//MM 2000
//MMM 3000

//C 100
//CC 200 
//CCC 300 
//CD 400 *
//D 500
//DC 600
//DCC 700
//DCCC 800
//CM 900 *

//10 X
//20 XX
//30 XXX
//40 XL *
//50 L
//60 LX
//70 LXX
//80 LXXX
//90 XC *

//1 I
//2 II
//3 III
//4 IV *
//5 V
//6 VI
//7 VII
//8 VIII
//9 IX *

// I=1 V=5 X=10 L=50 C=100 D=500 M=1000

// all in desending order except these * marked values
// these values need adjustment

int romanToInt(char* s) {
    char * p = s;
    int result = 0;

    int value = 0;
    int value_pre = 0;

    while (*p != 0){

        switch (*p){
        case 'I': 
            value = 1;
            break;
        case 'V': 
            value = 5;
            break;
        case 'X': 
            value = 10;
            break;
        case 'L': 
            value = 50;
            break;
        case 'C': 
            value = 100;
            break;
        case 'D': 
            value = 500;
            break;
        case 'M': 
            value = 1000;
            break;
        default: 
            return -1;
        }

        result += value;

        //adjustment
        if (value > value_pre){
            result -= 2*value_pre;
        }

        value_pre = value;
        p++;
    }

    return result;
}

int main(int argc, char * argv[]){
    printf("%d\n", romanToInt(argv[1]));
    return 0;
}