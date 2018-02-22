#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Given a string containing just the characters
 '(', ')', '{', '}', '[' and ']', determine if 
 the input string is valid.

The brackets must close in the correct order, 
"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

bool isValid(char* s) {
    int len = strlen(s);

    char * n = (char *) malloc(sizeof(char)*len);
    int top = 0;
    int flag = 0;
    int i=0;

    for (i=0; i<strlen(s); i++){
        if (s[i]=='(' || s[i]=='[' || s[i]=='{'){
            n[top]=s[i];
            top++;
        }else if (s[i]==')'){
            if (top==0) {
                flag = 1; 
                break;
            }

            top --;

            if (n[top]!='('){
                flag = 1;
                break;
            }
        }else if (s[i]==']'){
            if (top==0) {
                flag = 1; 
                break;
            }
            
            top--;

            if (n[top]!='['){
                flag = 1;
                break;
            }
        }else if (s[i]=='}'){
            if (top==0) {
                flag = 1; 
                break;
            }
            
            top--;

            if (n[top]!='{'){
                flag = 1;
                break;
            }
        }else {
            flag = 1;
            break;
        }
    }

    free(n);

    if (flag == 1) return false;

    if (top!=0) return false;

    return true;

}

int main(int argc, char * argv[]){
    printf("%d\n", isValid(argv[1]));
    return 0;
}
