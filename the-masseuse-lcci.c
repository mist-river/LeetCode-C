/*************************************************************************
    > File Name: the-masseuse-lcci.c
# File Name:    the-masseuse-lcci.c
# Author:       taofeiyang
# 递归解法(LeetCode上时间超限)
# https://leetcode-cn.com/problems/the-masseuse-lcci/
# Created Time: 2021年04月22日 星期四 16时59分05秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int massageSum(int* nums, int numsSize, int status) {
    if (numsSize == 1) {
        if (status == 0) {
            return 0;
        } else {
            return nums[0];
        }
    }
    if (status == 1) {
        return massageSum(nums, numsSize-1, 0) + nums[numsSize-1];
    } else {
        return fmax(massageSum(nums, numsSize-1, 0), massageSum(nums, numsSize-1, 1));
    }
}

int massage(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    return fmax(massageSum(nums, numsSize, 0), massageSum(nums, numsSize, 1));
}

void main() {
    int arr[8] = {2,1,4,5,3,1,1,3};
    int ret = massage(arr, 8);
    printf("%d\n", ret);
}
