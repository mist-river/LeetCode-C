/*************************************************************************
    > File Name: house-robber.c
# File Name:    house-robber.c
# Author:       taofeiyang
# https://leetcode-cn.com/problems/house-robber/
# Created Time: 2021年04月25日 星期日 17时39分33秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>

int rob(int* nums, int numsSize){
    if (numsSize == 1) {
        return nums[0];
    }
    int robi = nums[0];
    int nrobi = 0;
    int temp;
    for (int i=1; i<numsSize; i++) {
        temp = robi;
        robi = nrobi + nums[i];
        nrobi = fmax(temp, nrobi);
    }
    return fmax(robi, nrobi);
}

void main() {
    int nums[4] = {1,2,3,1};
    int ret = rob(nums, 4);
    printf("%d\n", ret);
}
