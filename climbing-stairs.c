/*************************************************************************
    > File Name: climbing-stairs.c
# File Name:    climbing-stairs.c
# Author:       taofeiyang
# 递归(leetcode上测试用例超时)
# https://leetcode-cn.com/problems/climbing-stairs/
# Created Time: 2021年04月19日 星期一 11时10分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n){
    if (1 == n) {
        return 1;
    }
    if (2 == n) {
        return 2;
    }
    return climbStairs(n-1) + climbStairs(n-2);
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
