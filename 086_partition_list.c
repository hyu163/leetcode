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

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode less_head;
    struct ListNode *less_tail;
    struct ListNode greate_head;
    struct ListNode *greate_tail;
    struct ListNode *next;
    less_head.next = NULL;
    less_tail = &less_head;
    greate_head.next = NULL;
    greate_tail = &greate_head;

    while (head){
        if (head->val < x){
            less_tail->next = head;
            less_tail = head;
        }else{
            greate_tail->next = head;
            greate_tail = head;
        }
        head = head->next;
    }
    less_tail->next = greate_head.next;
    greate_tail->next = NULL;
    return less_head.next;
}


int main(int argc, char * argv[]){
    struct ListNode a;
    struct ListNode b;
    struct ListNode c;
    struct ListNode d;
    struct ListNode e;
    struct ListNode f;
    struct ListNode g;

    a.val = 4;
    b.val = 5;
    c.val = 3;
    d.val = 1;
    e.val = 2;
    f.val = 6;
    g.val = 7;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = NULL;

    struct ListNode * result;
    dump(&a);
    result = partition(&a, 3);
    dump(result);

    return 0;
}