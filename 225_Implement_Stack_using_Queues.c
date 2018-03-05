#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct {
    struct ListNode head;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack * s = (MyStack *) malloc(sizeof(MyStack));
    s->head.next = NULL;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    struct ListNode * node;
    node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = obj->head.next;

    obj->head.next = node;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ret;

    struct ListNode *node;
    node = obj->head.next;
    ret = node->val;
    
    obj->head.next = node->next;

    free(node);
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->head.next){
        return obj->head.next->val;
    }
    return 0;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->head.next == NULL){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    //free list
    while(obj->head.next){
        struct ListNode *next;
        next = obj->head.next->next;
        free(obj->head.next);
        obj->head.next = next;
    }
    free(obj);
}



/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */

 int main(int argc, char * argv[]){
    struct MyStack* obj = myStackCreate(10);
    myStackPush(obj, 11);
    myStackPush(obj, 22);
    myStackPush(obj, 33);
    
    int param_2 = myStackPop(obj);
    printf("POP %d\n", param_2);

    int param_3 = myStackTop(obj);
    printf("TOP %d\n", param_3);

    myStackPush(obj, 44);

    param_3 = myStackTop(obj);
    printf("TOP %d\n", param_3);


    bool param_4 = myStackEmpty(obj);
    printf("EMPTY: %d\n", param_4);
    
    myStackFree(obj);
    return 0;
 }
