/*************************************************************************
  > File Name: jump-gam.c
# File Name:    jump-gam.c
# Author:       mist-river
# https://leetcode-cn.com/problems/jump-game/
# 简化版
# Created Time: 2021年04月23日 星期五 17时53分17秒
 ************************************************************************/
#include <stdio.h>
#define bool int
bool canJump(int* nums, int numsSize){
    int i;
    int right=0;
    for(i=0; i<numsSize; i++) {
        if(i<=right && i+nums[i] > right) {
            right = i+nums[i];
        }
    }
    if (right>=numsSize-1) {
        return 1;
    } else {
        return 0;
    }
}




void main(int argc, char**argv) {
    int flowerbed[1] = {1};
    bool ret = canJump(flowerbed, 1);
    printf("%d\n", ret);
}
