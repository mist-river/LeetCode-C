/*************************************************************************
    > File Name: remove-duplicates-from-sorted-array.c
# File Name:    remove-duplicates-from-sorted-array.c
# Author:       mist-river
# https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
# Created Time: 2021年04月18日 星期日 10时23分35秒
 ************************************************************************/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int i, j;
    for (i = 0; i< numsSize-1; i++) {
        if(nums[i] == nums[i+1]) {
            printf("删除%d\n", nums[i]);
            for(j=i+1; j< numsSize; j++) {
                nums[j-1] = nums[j];
            }
            numsSize--;
            i--;
        }
    }
    return numsSize;
}

int main() {
    int i;
    int arr[] = {1,1,2,2,3,3,4,4};
    int ret = removeDuplicates(arr, 8);
    for (i = 0; i< ret; i++) {
        printf("%d\n", arr[i]);
    }
}
