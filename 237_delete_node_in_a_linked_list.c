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

void deleteNode(struct ListNode* node) {
    //cannot process tail node
    if (node->next == NULL){
        return;
    }

    //non-tail node
    while(node){
        node->val = node->next->val;
        if (node->next->next==NULL){
            node->next = NULL;
        }
        node = node->next;
    }

    return;
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
    deleteNode(&b);
    dump(&a);
    deleteNode(&e);
    dump(&a);

    return 0;
}