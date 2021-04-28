/*************************************************************************
    > File Name: climbing-stairs.c
# File Name:    climbing-stairs.c
# Author:       mist-river
# 动态规划 滚动数组
# https://leetcode-cn.com/problems/climbing-stairs/
# Created Time: 2021年04月19日 星期一 11时10分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n){
    int ret[3];
    if (1 == n) {
        return 1;
    }
    if (2 == n) {
        return 2;
    }
    int i;
    ret[0] = 1;
    ret[1] = 2;
    for (i=3; i<=n; i++) {
        ret[2] = ret[0] + ret[1];
        ret[0] = ret[1];
        ret[1] = ret[2];
    }
    return ret[2];
}

void main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(1);
    }
    int ret;
    ret = climbStairs(atoi(argv[1]));
    printf("%d\n", ret);
}
