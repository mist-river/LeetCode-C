/*************************************************************************
    > File Name: the-masseuse-lcci.c
# File Name:    the-masseuse-lcci.c
# Author:       mist-river
# 递归解法(LeetCode上时间超限)
# https://leetcode-cn.com/problems/the-masseuse-lcci/
# Created Time: 2021年04月22日 星期四 16时59分05秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>

int massage(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int temp;
    int sum0 = 0;
    int sum1 = nums[0];
    int i;
    for(i=1;i<numsSize;i++) {
        temp = sum0;
        sum0 = fmax(sum0, sum1);
        sum1 = temp + nums[i];
    }
    return fmax(sum0, sum1);
}

void main() {
    int arr[8] = {2,1,4,5,3,1,1,3};
    int ret = massage(arr, 8);
    printf("%d\n", ret);
}
