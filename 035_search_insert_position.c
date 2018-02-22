#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int i;
    for (i=0; i<numsSize; i++){
        if (target <= nums[i]){
            return i;
        }
    }
    return numsSize;
}

int main(int argc, char * argv[]){
    int a[] = {1,3,5,6};
    int target = 5;
    int result;
    result = searchInsert(a, 4, 2);
    printf("%d\n", result);
    return 0;
}