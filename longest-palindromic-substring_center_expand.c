/*************************************************************************
    > File Name: longest-palindromic-substring.c
# File Name:    longest-palindromic-substring.c
# Author:       mist-river
# https://leetcode-cn.com/problems/longest-palindromic-substring/
# 中心扩展
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
    int length = strlen(s);
    if (1 == length) {
        return s;
    }
    int index = 0;
    int maxlen = 1;
    int i, len1, len2, templen;
    for (i=0; i<length; i++) {
        len1 = palindromeLen(s, length, i, i);
        if (s[i] == s[i+1]) {
            len2 = palindromeLen(s, length, i, i+1);
        } else {
            len2 = 0;
        }
        templen = len1 > len2 ? len1 : len2;
        if (templen > maxlen) {
            maxlen = templen;
            index = i - (maxlen-1)/2;
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
