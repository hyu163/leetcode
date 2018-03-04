#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

void dump(struct ListNode *head){
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return;
}

struct NodeInfo {
    struct ListNode *addr;
    int val;
    int cnt;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head==NULL || head->next == NULL){
        return head;
    }

    struct ListNode tmphead;
    struct ListNode *tail;
    tail = &tmphead;
    tail->next = NULL;
    
    //get one node
    struct NodeInfo ni;
    // head info
    ni.addr = head;
    ni.val = head->val;
    ni.cnt = 1;
    head = head->next;

    while (head){
        if (head->val == ni.val) {
            ni.cnt++;
        }else if (head->val != ni.val){
            if (ni.cnt == 1){
                tail->next = ni.addr;
                tail = tail->next;
                tail->next = NULL;
            }
            ni.addr = head;
            ni.val = head->val;
            ni.cnt = 1;
        }
        head = head->next;
    }

    //tail
    if (ni.cnt == 1){
        tail->next = ni.addr;
        tail = tail->next;
        tail->next = NULL;
    }

    return tmphead.next;  
}

int main(int argc, char * argv[]){
    struct ListNode a;
    struct ListNode b;
    struct ListNode c;
    struct ListNode d;
    struct ListNode e;
    struct ListNode f;
    struct ListNode g;

    a.val = 1;
    a.next = &b;

    b.val = 1;
    b.next = &c;

    c.val = 1;
    c.next = NULL;

    d.val = 3;
    d.next = &e;

    e.val = 5;
    e.next = &f;

    f.val = 6;
    f.next = &g;

    g.val = 7;
    g.next = NULL;

    dump(&a);
    struct ListNode* head;
    head =  deleteDuplicates(&a);
    dump(head);

    return 0;
}