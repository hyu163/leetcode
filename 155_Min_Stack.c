#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int *data;
    int size;
    int maxSize;
    int min;    
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *m = (MinStack *) malloc(sizeof(MinStack));
    m->data = (int *) malloc(sizeof(int)*maxSize);
    m->maxSize = maxSize;
    m->min = INT_MAX;
    m->size = -1;
    return m;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->size < obj->maxSize-1){
        obj->size ++;
        obj->data[obj->size] = x;
        if (x < obj->min) 
                obj->min = x;
    }
    return;
}

void minStackPop(MinStack* obj) {
    if (obj->size >= 0){
        int x = obj->data[obj->size];
        obj->size--;
        
        if (obj->size < 0){
            obj->min = INT_MAX;
        }else{
            if (x <= obj->min){
                obj->min = obj->data[0];
                for (int i=1; i<=obj->size; i++){
                    if (obj->data[i] < obj->min){
                        obj->min = obj->data[i];
                    }
                }
            }
        }
    }
    return;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
    return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

int main(int argc, char * argv[]){
    struct MinStack* obj = minStackCreate(20);
    printf("getMin: %d\n", minStackGetMin(obj));
    minStackPush(obj, 1);
    printf("getMin: %d\n", minStackGetMin(obj));
    minStackPush(obj, 2);
    printf("TOP: %d\n", minStackTop(obj));
    printf("getMin: %d\n", minStackGetMin(obj));
    minStackPop(obj);
    printf("getMin: %d\n", minStackGetMin(obj));
    printf("TOP: %d\n", minStackTop(obj));
    minStackFree(obj);

}