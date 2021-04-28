/*************************************************************************
    > File Name: best-time-to-buy-and-sell-stock-ii.c
# File Name:    best-time-to-buy-and-sell-stock-ii.c
# Author:       mist-river
# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
# Created Time: 2021年04月21日 星期三 20时19分34秒
 ************************************************************************/
#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int i;
    int ret = 0;
    for(i=0; i<pricesSize-1; i++) {
        if (prices[i] < prices[i+1]) {
            ret += prices[i+1] - prices[i];
        }
    }
    return ret;
}

void main() {
    int arr[6] = {7,1,5,3,6,4};
    int ret = maxProfit(arr, 6);
    printf("%d\n", ret);
}
