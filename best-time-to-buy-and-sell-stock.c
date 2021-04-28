/*************************************************************************
    > File Name: best-time-to-buy-and-sell-stock.c
# File Name:    best-time-to-buy-and-sell-stock.c
# Author:       taofeiyang
# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
# Created Time: 2021年04月19日 星期一 13时17分35秒
 ************************************************************************/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 1) {
        return 0;
    }
    int i;
    int min = prices[0];
    int profit = 0;
    for (i=1; i<pricesSize; i++) {
        if (prices[i] < min) {
            min = prices[i];
        } else if(prices[i] - min > profit) {
            profit = prices[i] - min;
        }
    }
    return profit;
}

void main() {
    int arr[6] = {7,1,5,3,6,4};
    int ret = maxProfit(arr, 6);
    printf("%d\n", ret);
}
