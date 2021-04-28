/*************************************************************************
    > File Name: palindrome-number.c
# File Name:    palindrome-number.c
# Author:       mist-river
# https://leetcode-cn.com/problems/palindrome-number/
# Created Time: 2021年04月12日 星期一 16时01分23秒
 ************************************************************************/

#include <stdio.h>
typedef int bool;

bool isPalindrome(int x){  
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return 0;
    }
    int p = 0;
    while (x > p) {
        p = p * 10 + x % 10;
        x = x / 10;
    }
    return x == p || x == p / 10;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return -1;
    }
    bool res;
    int n = atoi(argv[1]);
    res = isPalindrome(n);
    printf("%d\n", res);
}
