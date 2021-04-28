/*************************************************************************
  > File Name: can-place-flowers.c
# File Name:    can-place-flowers.c
# Author:       mist-river
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
    int i;
    if(flowerbed[1] == 0 && flowerbed[0] == 0) {
        flowerbed[0] = 1;
        n--;
        if (0 == n) {
            return 1;
        }
    }
    for (i=1; i<flowerbedSize-1; i++) {
        if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
            flowerbed[i] = 1;
            n--;
            if (0 == n) {
                return 1;
            }
        }
    }
    if(flowerbed[flowerbedSize-2]==0 && flowerbed[flowerbedSize-1] == 0) {
        flowerbed[flowerbedSize-1] = 1;
        n--;
        if (0 == n) {
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
    int flowerbed[5] = {0, 0, 1, 0, 0};
    n = atoi(argv[1]);
    bool ret = canPlaceFlowers(flowerbed, 5, n);
    printf("%d\n", ret);
}
