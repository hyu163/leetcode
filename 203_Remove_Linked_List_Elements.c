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

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode tempnode;
    tempnode.next = head;
    struct ListNode *ptr;
    ptr = &tempnode;

    while(head){
        if (head->val == val){
            ptr->next = head->next;
            head = ptr->next;
        }else{
            ptr = ptr->next;
            head = head->next;
        }
    }
    return tempnode.next;
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

    b.val = 2;
    b.next = &c;

    c.val = 3;
    c.next = &d;

    d.val = 4;
    d.next = &e;

    e.val = 5;
    e.next = &f;

    f.val = 6;
    f.next = &g;

    g.val = 7;
    g.next = NULL;

    dump(&a);
    struct ListNode* head;
    head =  removeElements(&a, 7);
    dump(head);

    return 0;
}