/*************************************************************************
    > File Name: longest-palindromic-substring.c
# File Name:    longest-palindromic-substring.c
# Author:       taofeiyang
# https://leetcode-cn.com/problems/longest-palindromic-substring/
# 动态规划
# Created Time: 2021年04月20日 星期二 09时52分08秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s){
    int length = strlen(s);
    if (1 == length) {
        return s;
    }
    int parr[length][length];
    int i, j, len;
    for (i=0; i<length; i++) {
        parr[i][i] = 1;
    }
    int maxlen = 1;
    int start = 0;
    for (len=2; len<=length; len++) {
        //i < length - len + 1
        for(i = 0; i < length; i++) {
            j = i + len - 1;
            if (j >= length) {
                break;
            }
            if ((parr[i+1][j-1] == 1 && s[i] == s[j]) || (len <= 3 && s[i] == s[j])) {
                parr[i][j] = 1;
                if (len > maxlen) {
                    maxlen = len;
                    start = i;
                }
            } else {
                parr[i][j] = 0;
            }
        }
    }
    char *ret = malloc((maxlen+1) * sizeof(char));
    strncpy(ret, s+start, maxlen);
	//不以'\0'终止，leetcode上报堆溢出
    ret[maxlen] = '\0';
    return ret;
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
