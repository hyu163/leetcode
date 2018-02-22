#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int n0 = 0;
    int n1 = 0;
    int j = 0; //loop index
    if (numsSize==0) return 0;

    n0 = nums[0];
    i = 1;    
    while(1){
        if (i==numsSize){
            break;
        }

        n1=nums[i];
        if (n1==n0){
            //shink
            for (j=i; j<numsSize-1; j++){
                nums[j] = nums[j+1];
            }
            numsSize --;
        }else{
            i++;
        }
        n0 = n1;
    }

    return numsSize;
}

int main(){
    int a[6]={1,1,2,3,3,4};

    int i;
    for (i=0; i<6; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    int result = removeDuplicates(a, 6);
    printf("result: %d\n", result);

    for (i=0; i<result; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;

}