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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head==NULL || head->next == NULL){
        return head;
    }

    struct ListNode * ptr = head->next;
    struct ListNode * pre = head;
    while(ptr){
        if (pre->val == ptr->val){
            pre->next = ptr->next;
        }else{
            pre = pre->next;
        }
        ptr=ptr->next;
    }
    return head;
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

    c.val = 3;
    c.next = &d;

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