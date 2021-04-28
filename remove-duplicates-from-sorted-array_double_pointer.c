/*************************************************************************
    > File Name: remove-duplicates-from-sorted-array.c
# File Name:    remove-duplicates-from-sorted-array.c
# Author:       taofeiyang
# https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
# Created Time: 2021年04月18日 星期日 10时23分35秒
 ************************************************************************/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int i;
    int j=1;
    for (i=1; i<numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main() {
    int i;
    int arr[] = {1,1,2,2,3,3,4,4};
    int ret = removeDuplicates(arr, 8);
    for (i = 0; i< ret; i++) {
        printf("%d\n", arr[i]);
    }
}
