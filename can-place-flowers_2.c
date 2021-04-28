/*************************************************************************
  > File Name: can-place-flowers.c
# File Name:    can-place-flowers.c
# Author:       mist-river
# https://leetcode-cn.com/problems/can-place-flowers/
# Created Time: 2021年04月22日 星期四 21时16分26秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define bool int

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    if (n == 0) {
        return 1;
    }
    if (n > (flowerbedSize+1)/2) {
        return 0;
    }
    if (flowerbedSize == 1) {
        if(flowerbed[0]==0) {
            return 1;
        } else {
            return 0;
        }
    }
    int i,m=0;
    int count=0;
    int flag = 0;
    for (i=0; i<flowerbedSize; i++) {
        if (i==0 || i==flowerbedSize-1) {
            if(flowerbed[i]==0) {
                flag += 1;
            }
        }
        if(flowerbed[i]==0) {
            count++;
        }
        if(flowerbed[i]==1 || i==flowerbedSize-1) {
            if(flag == 1) {
                m += count/2;
                flag = 0;
            } else if(flag == 2) {
                m += (count+1)/2;
                flag = 0;
            } else{
                m += (count-1)/2;
            }
            count = 0;
        }
        if (m >= n) {
            return 1;
        }
    }
    return 0;
}

void main(int argc, char**argv) {
    int n;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(1);
    }
    int flowerbed[3] = {0, 0, 0};
    n = atoi(argv[1]);
    bool ret = canPlaceFlowers(flowerbed, 3, n);
    printf("%d\n", ret);
}
