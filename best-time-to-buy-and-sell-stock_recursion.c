/*************************************************************************
    > File Name: best-time-to-buy-and-sell-stock_recursion.c
# File Name:    best-time-to-buy-and-sell-stock_recursion.c
# Author:       taofeiyang
# 递归(纯粹为了练习下递归，该方法在leetcode上执行超时)
# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
# Created Time: 2021年04月19日 星期一 14时15分36秒
 ************************************************************************/

#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 1) {
        return 0;
    }
    return max(maxProfit(prices, pricesSize - 1), prices[pricesSize - 1] - minPrice(prices, pricesSize - 1));
}

int minPrice(int* prices, int pricesSize){
    if (pricesSize == 1) {
        return prices[0];
    }
    return min(prices[pricesSize - 1], minPrice(prices, pricesSize - 1));
}

void main() {
    int arr[6] = {7,1,5,3,6,4};
    int ret = maxProfit(arr, 6);
    printf("%d\n", ret);
}
