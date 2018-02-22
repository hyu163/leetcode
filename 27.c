#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = 0;
    int j = 0; //loop index
    if (numsSize==0) return 0;

    i = 0;
    while(1){
        if (i==numsSize){
            break;
        }

        n=nums[i];
        if (n==val){
            //shink
            for (j=i; j<numsSize-1; j++){
                nums[j] = nums[j+1];
            }
            numsSize --;
        }else{
            i++;
        }
    }

    return numsSize;

}

int main(int argc, char * argv[]){
    int a[6]={1,1,2,3,3,4};

    int i;
    for (i=0; i<6; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    int result = removeElement(a, 6, 3);
    printf("result: %d\n", result);

    for (i=0; i<result; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;

}