/*************************************************************************
    > File Name: lcp22.c
# File Name:    lcp22.c
# Author:       mist-river
# https://leetcode-cn.com/problems/ccw6C7/
# LCP 22. 黑白方格画
# Created Time: 2021年04月08日 星期四 17时11分30秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n> <k>\n", argv[0]);
        return -1;
    }
    int res;
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    res = paintingPlan(n, k);
    printf("%d\n", res);
}

int paintingPlan(int n, int k){  
    int i, j, count = 0;
    if (0 == k || k == n*n) {
        return 1;
    }
    if (k < n) {
        return 0;
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i * n + j * n - i * j == k) {
                printf("%d, %d\n", i, j);
                count += cni(n, i) * cni(n, j);
            }
        }
    }
    return count;
}

int cni(int n, int i) {
    if (0 == i || n == i) {
        return 1;
    }
    int res = 1, p;
    for (p = 0; p < i; p++) {
        res *= n;
        n--;
    }
    for (; i>1; i--) {
        res /= i;
    }
    return res;
}
