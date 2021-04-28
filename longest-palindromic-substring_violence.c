/*************************************************************************
    > File Name: longest-palindromic-substring.c
# File Name:    longest-palindromic-substring.c
# Author:       mist-river
# https://leetcode-cn.com/problems/longest-palindromic-substring/
# 暴力穷举
# Created Time: 2021年04月20日 星期二 09时52分08秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *s, int i, int j) {
    if (j == i+1) {
        if (s[i] == s[j]) {
            return 1;
        } else {
            return 0;
        }
    }
    while (i<=j) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

char * longestPalindrome(char * s){
    int i,j,maxlen,templen,index;
    int length = strlen(s);
    if (1 == length) {
        return s;
    }
    index = 0;
    maxlen = 1;
    for(i=0; i<length-1; i++) {
        for(j=length-1 ; j>i; j--) {
            if (j-i+1 <= maxlen) {
                break;
            }
            if(isPalindrome(s, i, j) && j-i+1 > maxlen) {
                printf("%d,%d\n",i,j);
                maxlen = j-i+1;
                index = i;
            }
        }
    }
    s[index+maxlen] = '\0';
    return s+index;
}

void main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(-1);
    }
    char *s = argv[1];
    char *ret = longestPalindrome(s);
    printf("%s\n", ret);
}
