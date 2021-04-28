/*************************************************************************
    > File Name: maximum-repeating-substring.c
# File Name:    maximum-repeating-substring.c
# Author:       mist-river
# https://leetcode-cn.com/problems/maximum-repeating-substring/
# Created Time: 2021年04月06日 星期二 22时10分05秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sequence> <word>\n", argv[0]);
        return -1;
    }
    int res;
    char *sequence, *word;
    sequence = argv[1];
    word = argv[2];
    res = maxRepeating(sequence, word);
    printf("%d\n", res);
}

int maxRepeating(char * sequence, char * word){
    int i, flag, len, count = 0, max = 0, pos;
    char *s;
    char *w;
    int sequenceLen = strlen(sequence);
    int wordLen = strlen(word);
    if (0 == wordLen || wordLen > sequenceLen) {
        return 0;
    }
    for (i=0; i<= sequenceLen - wordLen; i++) {
        s = sequence;
        w = word;
        s += i;
        pos = 0;
        count = 0;
        while ((pos += wordLen) <= sequenceLen) {
            w = word;
            len = wordLen;
            flag = 1;
            while(len --) {
                if (*(s++) != *(w++)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                count++;
            } else {
                break;
            }
        }
        if (count > max) {
            max = count;
        }
    }
    return max;
}
