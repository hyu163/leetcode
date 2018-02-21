#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *h = NULL;
    struct ListNode *t = NULL;
    struct ListNode *p = NULL;

    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    int carry = 0;
    int c;

    p = l1;
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = l2;
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    while(1){

        if ( (p1!=NULL) && (p2!=NULL) ) {
            printf("1:%d 2:%d carry:%d\n", p1->val, p2->val, carry);
            c = p1->val + p2->val;
        }else if ( (p1==NULL) && (p2!=NULL)) {
            printf("1:- 2:%d carry:%d\n", p2->val, carry);
            c = p2->val;
        }else if ( (p1!=NULL) && (p2==NULL)) {
            printf("1:%d 2:- carry:%d\n", p1->val, carry);
            c = p1->val;
        }else if ( (p1==NULL) && (p2==NULL)) {
            printf("1:- 2:- carry:%d\n", carry);
            c = 0;
            if (carry == 0) 
                break;
        }

        c += carry;

        if (c>9){
            c = c % 10;
            carry = 1;
        }else{
            carry = 0;
        }

        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->val = c;
        p->next = NULL;

        if (h==NULL){
            h = p;
            t = p;
        }else{
            t->next = p;
            t = p;
        }

        if ( (p1==NULL) && (p2==NULL)) {
            break;
        }

        if (p1!=NULL){
            p1=p1->next;
        }
        
        if (p2!=NULL){
            p2=p2->next;
        }
    }

    return h;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    unsigned long long  a, b, c;
    int cnt;
    struct ListNode *p;
    
    a = 0;
    b = 0;
    c = 0;
    
    p = l1;
    cnt = 0;
    while (1){
        a += p->val * pow(10,cnt);
        p = p->next;
        cnt ++;
        if (p == NULL) break;
    }
    
    p = l2;
    cnt = 0;
    while (1){
        b += p->val * pow(10,cnt);
        p = p->next;
        cnt ++;
        if (p == NULL) break;
    }
    
    c = a + b;

    //create new list
    struct ListNode * head;
    struct ListNode * tail;
    
    head = NULL;
    tail = NULL;
    
    int v, r;

    while (1){
        v = c/10;
        r = c%10;
        
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->val = r;
        p->next = NULL;
        
        if ( head == NULL ){
            //first node
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
        
        if (v==0){
            break;
        }
        
        c = v;
    }
    
    return head; 
    
}

int main(){
    
    struct ListNode* l1;
    struct ListNode* l2;
    struct ListNode* l3;

    int a[2] = {9};
    int b[1] = {9};
    
    int i;
    struct ListNode * p;
    struct ListNode * tail;
    
    l1 = NULL;
    l2 = NULL;
    
    for (i=0; i<2; i++){
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->val=a[i];
        if (l1==NULL){
            l1 = p;
            tail = p;
            tail->next = NULL;
        }else{
            tail->next = p;
            tail = p;
            tail->next = NULL;
        }
    }
        
    for (i=0; i<1; i++){
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->val=b[i];
        if (l2==NULL){
            l2 = p;
            tail = p;
            tail->next = NULL;
        }else{
            tail->next = p;
            tail = p;
            tail->next = NULL;
        }
    }
    
    l3 = addTwoNumbers2( l1, l2);
    
    p = l3;
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    
    return 0;
}
