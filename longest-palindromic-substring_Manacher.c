/*************************************************************************
    > File Name: longest-palindromic-substring.c
# File Name:    longest-palindromic-substring.c
# Author:       taofeiyang
# https://leetcode-cn.com/problems/longest-palindromic-substring/
# Manacher算法
# 较难理解!
# Created Time: 2021年04月20日 星期二 09时52分08秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromeLen(char *s, int length, int i, int j) {
    int len = j - i + 1;
    while (i>=1 && j+1<length) {
        if(s[i-1] == s[j+1]) {
            i--;
            j++;
            len += 2;
        } else {
            break;
        }
    }
    return len;
}

char * longestPalindrome(char * s){
    int i,templen,minlen=3;
    int length = strlen(s);
    int strlen = 2*length+1;
    int p[strlen];
    p[0] = 1;
    p[1] = 1;
    int j = 0;
    int right = 2;
    int maxlen = 3;
    int start = 0;
    int retlen = 1;
    if (1 == length) {
        return s;
    }
    char *str = (char*)malloc((strlen+1) * sizeof(char*));
    for (i=0; i<length; i++) {
        str[i*2] = '#';
        str[i*2 + 1] = s[i];
    }
    str[strlen-1] = '#';
    str[strlen] = '\0';
    for (i=2; i<2*length-1; i++) {
        if (i>=right) {
            templen = palindromeLen(str, strlen, i, i); 
        } else {
            minlen = p[2*j-i] > right-i ? right-i : p[2*j-i];
            templen = palindromeLen(str, strlen, i-minlen, i+minlen);
        }
        p[i] = (templen - 1)/2;
        if (i+(templen-1)/2 > right) {
            j = i;
            right = i+(templen-1)/2;
        }
        if (templen > maxlen) {
            maxlen = templen;
            start = (i-(templen-1)/2)/2;
            retlen = (maxlen-1)/2;
        }
    }
    s[start + retlen] = '\0';
    return s+start;
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
