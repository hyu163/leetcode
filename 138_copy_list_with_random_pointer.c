#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "uthash.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

struct HashElement{
    struct RandomListNode * key;
    struct RandomListNode * key1;
    UT_hash_handle hh;
};

struct HashElement *hash = NULL;

void dump(struct RandomListNode * head) {
    while(head){
        printf("%d(%d) ", head->label, head->random->label);
        head = head->next;
    }
    printf("\n");
    return;
}
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode new_head;
    struct RandomListNode *new_tail;
    
    new_head.next = NULL;
    new_tail = &new_head;

    //copy nodes
    while(head){
        //new node
        struct RandomListNode *node = (struct RandomListNode *) malloc(sizeof(struct RandomListNode));
        node->label = head->label;
        node->random = head->random;
        
        struct HashElement *d = NULL;
        HASH_FIND_PTR(hash, &(head), d);
        if (d == NULL){
            d = (struct HashElement *)malloc(sizeof(struct HashElement));
            d->key = head;
            d->key1 = node;
            HASH_ADD_PTR(hash, key, d);
        }

        new_tail->next = node;
        new_tail = node;

        head=head->next;
    }
    new_tail->next = NULL;

    //modify random
    struct RandomListNode *new_ptr;
    new_ptr = new_head.next;
    while (new_ptr) {
        struct HashElement *d = NULL;
        HASH_FIND_PTR(hash, &(new_ptr->random), d);
        if (d){
            new_ptr->random = d->key1;
        }else{
            new_ptr->random = NULL;
        }
        new_ptr = new_ptr->next;
    }

    return new_head.next;
}

int main(int argc, char * argv[]){
    struct RandomListNode a;
    struct RandomListNode b;
    struct RandomListNode c;
    struct RandomListNode d;
    struct RandomListNode e;
    struct RandomListNode f;
    struct RandomListNode g;

    a.label = 1;
    a.next = &b;
    a.random = &c;
    
    b.label = 2;
    b.next = &c;
    b.random = &a;

    c.label = 3;
    c.next = &d;
    c.random = &b;

    d.label = 4;
    d.next = &e;
    d.random = &a;

    e.label = 5;
    e.next = &f;
    e.random = &f;
    
    f.label = 6;
    f.next = &g;
    f.random = &c;

    g.label = 7;
    g.next = NULL;
    g.random = &d;



    struct RandomListNode * head;
    
    dump(&a);
    head = copyRandomList(&a);
    dump(head);

    return 0;
}