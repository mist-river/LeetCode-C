/*************************************************************************
    > File Name: longest-palindromic-substring.c
# File Name:    longest-palindromic-substring.c
# Author:       mist-river
# https://leetcode-cn.com/problems/longest-palindromic-substring/
# 中心扩展 (从中间位置开始)
# Created Time: 2021年04月20日 星期二 09时52分08秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromeLen(char *s, int length, int i, int j) {
    if (i == j - 1 && s[i] != s[j]) {
        return 0;
    }
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

int palindromeLenAtI(char *s, int length, int i) {
    int len1,len2;
    len1 = palindromeLen(s, length, i, i);
    len2 = palindromeLen(s, length, i, i+1);
    return len2 > len1 ? len2 : len1;
}

char * longestPalindrome(char * s){
    int i, j, templen;
    int length = strlen(s);
    if (1 == length) {
        return s;
    }
    int index = 0;
    int maxlen = 1;
    int step;
    //i位置理论最长回文串
    int tlen = length;
    i = (length - 1)/2;
    if (length % 2 == 0) {
        step = 1;
    } else {
        step = -1;
    }
    j = 1;
    while (i>=0 && i<length) {
        printf("%d\n", i);
        templen = palindromeLenAtI(s, length, i);
        if (templen > maxlen) {
            maxlen = templen;
            index = i - (maxlen-1)/2;
        }
        if (maxlen >= tlen - 1) {
            break;
        }
        i = i + j * step;
        j++;
        step = 0 - step;
        tlen--;
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
