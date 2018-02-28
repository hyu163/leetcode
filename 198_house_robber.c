#include <stdio.h>

int solve(int* nums, int index){
    if (index<0){
        return 0;
    }
    int a;
    int b;

    a=nums[index]+solve(nums, index-2);
    b=solve(nums, index-1);

    if (a>=b) 
        return a;
    else
        return b;
}

int rob(int* nums, int numsSize){
    return solve(nums, numsSize-1);
}

int main(int argc, char * argv[]){
    int a[]={0,1,2,3,4,9,10,20,0,20};
    int result;
    result = rob(a, 10);
    printf("%d\n", result);
    return 0;
}