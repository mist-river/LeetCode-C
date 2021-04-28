/*************************************************************************
    > File Name: two-sum.c
# File Name:    two-sum.c
# Author:       mist-river
# https://leetcode-cn.com/problems/two-sum/
# Created Time: 2021年04月13日 星期二 22时54分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *arr;
    arr = (int*)malloc( 2 * sizeof(int) ); 
    *returnSize = 0;
    for (i=0; i<numsSize; i++) {
        for (j=i+1; j<numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    return arr;
}

int main (int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return -1;
    }
    int nums[] = {2, 7, 11, 5};
    int target = atoi(argv[1]);
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;
    int *res;
    res = twoSum(nums, numsSize, target, &returnSize);
    int i;
    for (i=0; i<returnSize; i++) {
        printf("%d\n", res[i]);
    }
}
