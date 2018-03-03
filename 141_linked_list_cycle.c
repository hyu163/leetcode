#define USING_FASTSLOW

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef USING_HASH
#include "uthash.h"
#endif 
struct ListNode {
    int val;
    struct ListNode *next;
};

#ifdef USING_HASH
struct HashElement{
    struct ListNode * key;
    UT_hash_handle hh;
};

struct HashElement *hash = NULL;

bool hasCycle(struct ListNode *head) {
    while (head) {
        struct HashElement *d = NULL;
        HASH_FIND_PTR(hash, &head, d);
        if (d != NULL) return true;
        
        d = (struct HashElement *)malloc(sizeof(struct HashElement));
        d->key = head;
        HASH_ADD_PTR(hash, key, d);

        head = head->next;
    }

    return false;
}
#endif

#ifdef USING_FASTSLOW
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast;
    struct ListNode *slow;
    fast = head;
    slow = head;
    while (fast&&slow){
        fast = fast->next;
        if (fast == NULL){
            return false;
        }else{
            fast = fast->next;
        }

        slow = slow->next;

        if (fast==slow){
            return true;
        }
    }
    return false;
}
#endif

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
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = NULL;

    bool result;
    result = hasCycle(&a);
    printf("result: %d\n", result);

    return 0;
}