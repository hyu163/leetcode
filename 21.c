#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * m;
    struct ListNode * t;
    
    m = NULL;
    t = NULL;
    while(1){

        if ((l1==NULL) && (l2==NULL)){
            break;
        }

        if ((l1!=NULL) && (l2!=NULL)){
            if (l1->val < l2->val){
                if (m==NULL){
                    m = l1;
                    t = l1;
                }else{
                    t->next = l1;
                    t = l1;
                }
                l1 = l1->next;
            }else if (l1->val > l2->val){
                if (m==NULL){
                    m = l2;
                    t = l2;
                }else{
                    t->next = l2;
                    t = l2;
                }
                l2 = l2->next;
            }else{ // equal
                if (m==NULL){
                    m = l1;
                    t = l1;
                    l1 = l1->next;
                    t->next = l2;
                    t = l2;
                    l2 = l2->next;                    
                }else{
                    t->next = l1;
                    t = l1;
                    l1 = l1->next;
                    t->next = l2;
                    t = l2;
                    l2 = l2->next;
                }
            }
        }else if ((l1==NULL) && (l2!=NULL)) {
            if (m==NULL){
                m = l2;
                t = l2;
            }else{
                t->next = l2;
                t = l2;
            }
            l2 = l2->next;
        }else if ((l1!=NULL) && (l2==NULL)){
            if (m==NULL){
                m = l1;
                t = l1;
            }else{
                t->next = l1;
                t = l1;
            }
            l1 = l1->next;
        }
        
        t->next = NULL;

    }

    return m;
}

int main(int argc, char * argv[]){

    int a[3] = {1,2,4};
    int b[3] = {1,3,4};
    
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
   
    int i = 0;
    struct ListNode * p = NULL;
    struct ListNode * tail = NULL;
    
    for (i=0; i<3; i++){
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

    for (i=0; i<3; i++){
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

    p = mergeTwoLists(l1,l2);
   
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}