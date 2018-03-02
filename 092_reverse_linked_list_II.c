#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

void dump(struct ListNode * head) {
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {

    if (m==n || m<0 || n<0 || m>n){
        return head;
    }

    struct ListNode tmpnode;

    struct ListNode *p;
    struct ListNode *next;

    struct ListNode *m_pre;
    struct ListNode *m_p;
    struct ListNode *n_p;
    struct ListNode *n_next;

    struct ListNode *result;

    int idx;

    tmpnode.next = NULL;
    p = head;
    idx = 1;
    
    while(true) {
        printf("idx: %d ", idx);
        if (idx==m-1){ //when m>1
            printf("pre_m ");
            m_pre = p;
            p = p->next;
            idx ++;
        }else if (idx >= m && idx<=n) {
            if (idx == m) {
                printf("m ");
                if (m == 1){
                    printf(", m_pre is null");
                    m_pre = NULL;
                    m_p = p;
                }else {
                    m_p = p;
                }
            }else if (idx==n){
                printf("n ");
                n_p = p;
            }

            struct ListNode *next = p->next;
            p->next = tmpnode.next;
            tmpnode.next = p;
            p = next; 
            idx++;

            if (idx==m) m_p->next = NULL;

        }else if (idx==n+1){
            printf("n_next, do connect");
            n_next = p;
            m_p->next = n_next; //connect
            idx++;
        }else{
            p = p->next;
            idx++;
        }

        printf("\n");
        dump(tmpnode.next);

        if (idx>n+1) 
            break;
    }


    //rearrange head
    if (m_pre == NULL){
        result = tmpnode.next;
    }else{
        result = head;
        m_pre->next = tmpnode.next;
    }

    printf("result: ");
    dump(result);
    //rearrange tail
    //m_p->next = n_next;

    return result;
}


int main(int argc, char * argv[]){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i;
    
    struct ListNode *head;
    struct ListNode *tail;
    head = NULL;
    tail = NULL;
    struct ListNode *node;
    struct ListNode *result;
    for (i=0; i<15; i++){
        node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->val = a[i];
        if (head == NULL){
            head = node;
            tail = node;
            tail->next = NULL;
        }else {
            tail->next = node;
            tail = node;
            tail->next = NULL;
        }
    }

    dump(head);
    head = reverseBetween(head, atoi(argv[1]), atoi(argv[2]));
    dump(head);

    //freee nodes
    while(head){
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}