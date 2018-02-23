#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MyListNode {
    char val;
    int cnt;
    struct MyListNode * next;
};

char * countAndSay(int n) {
    //data using malloced string
    char * data;

    struct MyListNode * head;
    struct MyListNode * tail;
    struct MyListNode * cur;

    head = NULL;
    tail = NULL;
    cur = NULL;

    int pos=1;
    int i=0;
    int m=0;
    int total_len;
    //init data
    
    data = (char *) malloc(sizeof(char)*2);
    strcpy(data, "1");
    //printf("pos: %d data: %s len:%d\n", pos, data, strlen(data));

    if (n<=1) return data;

    pos = 2;

    while (pos <= n){

        //init head node using data[0]
        head = (struct MyListNode *) malloc(sizeof(struct MyListNode));
        tail = head;
        head->val = data[0];
        head->cnt = 1;
        tail->next = NULL;

        //run through data
        for (i=1; i<strlen(data); i++){
            if (data[i]==tail->val){
                tail->cnt++;
            }else{
                //new node
                cur = (struct MyListNode *) malloc(sizeof(struct MyListNode));
                cur->val = data[i];
                cur->cnt = 1;
                //add to list
                tail->next = cur;
                tail = cur;
                tail->next = NULL;
            }
        }
        free(data);

        //malloc new data space
        cur = head;
        while (cur!=NULL) {
            total_len += 1;
            cur = cur->next;
        }
        
        data = (char *) malloc((2*total_len+1)*sizeof(char));

        cur = head;
        m=0;
        while(cur!=NULL){
            data[m] = cur->cnt + 0x30;
            data[m+1] = cur->val;
            m+=2;
            cur = cur->next;
        }
        data[m]=0;

        //free list
        cur = head;
        struct MyListNode * p;
        while (cur!=NULL){
            p = cur->next;
            free(cur);
            cur = p;
        }
        head = NULL;
        tail = NULL;
        cur = NULL;
        
        //printf("pos: %d data: %s len:%d\n", pos, data, strlen(data));
        pos++;
    }

    return data;
}

int main(int argc, char * argv[]){
    char * result;
    int n = atoi(argv[1]);
    printf("%d\n",n);
    result = countAndSay(n);
    printf("%s\n", result);
    free(result);
}