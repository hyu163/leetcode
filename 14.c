/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    int j=0;
    int flag = 0;
    char * result = "";

    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];

    for (i=0; i<strsSize; i++){
        if (strlen(strs[i])==0){
            return "";
        }
    }

    while (1){
        for (i=1; i<strsSize; i++){
            if (strs[0][j] != strs[i][j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) break;
        j++;
    }

    if (j==0) {
        return "";
    }else{
        result = (char *) malloc(sizeof(char)*(j+1));
        strncpy(result, strs[0], j);
        result[j]=0;
        return result;
    }
}

int main(int argc, char * argv[]){
    //TODO: testcase to be added
    return 0;
}