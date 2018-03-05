#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct {
    struct ListNode head;
    int size;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack * s = (MyStack *) malloc(sizeof(MyStack));
    s->head.next = NULL;
    s->size = 0;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    struct ListNode * node;
    node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = obj->head.next;
    obj->size++;
    obj->head.next = node;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ret;

    struct ListNode *node;
    node = obj->head.next;
    ret = node->val;
    obj->size--;
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

int myStackSize(MyStack* obj){
    return obj->size;
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


typedef struct {
    MyStack *s1;
    MyStack *s2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue* q = (MyQueue *)malloc(sizeof(MyQueue));
    q->s1 = myStackCreate(maxSize);
    q->s2 = myStackCreate(maxSize);
    return q;    
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    myStackPush(obj->s1, x);
    return;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int ret;
    while(myStackSize(obj->s1)>1){
        int temp = myStackPop(obj->s1);
        myStackPush(obj->s2, temp);
    }
    ret = myStackPop(obj->s1);
    while(myStackSize(obj->s2)>0){
        int temp = myStackPop(obj->s2);
        myStackPush(obj->s1, temp);
    }
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int ret;
    while(myStackSize(obj->s1)>1){
        int temp = myStackPop(obj->s1);
        myStackPush(obj->s2, temp);
    }
    ret = myStackTop(obj->s1);
    while(myStackSize(obj->s2)>0){
        int temp = myStackPop(obj->s2);
        myStackPush(obj->s1, temp);
    }
    return ret;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return myStackEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    myStackFree(obj->s1);
    myStackFree(obj->s2);
    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
int main(int argc, char * argv[]){
    int param_2, param_3;
    struct MyQueue* obj = myQueueCreate(10);
    myQueuePush(obj, 10);
    myQueuePush(obj, 20);
    myQueuePush(obj, 30);
    myQueuePush(obj, 40);
    param_2 = myQueuePop(obj);
    printf("POP: %d\n", param_2);

    param_3 = myQueuePeek(obj);
    printf("PEEK: %d\n", param_3);

    param_2 = myQueuePop(obj);
    printf("POP: %d\n", param_2);

    param_3 = myQueuePeek(obj);
    printf("PEEK: %d\n", param_3);

    bool param_4 = myQueueEmpty(obj);
    printf("EMPTY: %d\n", param_4);

    myQueueFree(obj);
    return 0;
}