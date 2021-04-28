/*************************************************************************
  > File Name: jump-gam.c
# File Name:    jump-gam.c
# Author:       mist-river
# Created Time: 2021年04月23日 星期五 17时53分17秒
 ************************************************************************/
#include <stdio.h>
#define bool int
int jump(int *nums, int i, int j) {   
    //distance为当前可以跳到的最远距离
    int distance = i + nums[i];
    //jumpTo为当前应该跳到的位置
    int jumpTo = distance;
    i=i+1;
    for(;i<=j;i++) {
        if(i + nums[i] > distance) {
            distance = i+nums[i];
            jumpTo = i;
        }
    }
    return jumpTo;
}

bool canJump(int* nums, int numsSize){
    int count=0;
    int i;
    int pos;
    for(i=0; i<numsSize;) {
        if (i+nums[i] >= numsSize-1) {
            return 1;
        }
        pos = jump(nums, i, i+nums[i]);
        if (0 == pos) {
            break;
        }
        i = pos;
        count++;
        if (count == numsSize-1 && i<numsSize-1) {
            return 0;
        }
    }
    if (i >= numsSize-1) {
        return 1;
    }
    return 0;
}




void main(int argc, char**argv) {
    int flowerbed[1] = {1};
    bool ret = canJump(flowerbed, 1);
    printf("%d\n", ret);
}
