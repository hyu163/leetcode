#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

void dump(struct ListNode * head) {
    while(head){
        printf("%p ", head);
        head = head->next;
    }
    printf("\n");
    return;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    while(headA){
        struct ListNode *p = headB;
        while(p){
            if (p == headA){
                return p;
            }
            p=p->next;
        }
        headA=headA->next;
    }
    return NULL;
}

int main(int argc, char * argv[]){
    struct ListNode a;
    struct ListNode b;
    struct ListNode c;
    struct ListNode d;
    struct ListNode e;
    struct ListNode f;
    struct ListNode g;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    e.next = &f;
    f.next = &g;
    g.next = &c;

    struct ListNode * result;
    result = getIntersectionNode(&a, &e);
    printf("result: %p\n", result);

    dump(&a);
    dump(&e);

    return 0;
}