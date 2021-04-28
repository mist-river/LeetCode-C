/*************************************************************************
    > File Name: best-time-to-buy-and-sell-stock-ii.c
# File Name:    best-time-to-buy-and-sell-stock-ii.c
# Author:       mist-river
# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
# Created Time: 2021年04月21日 星期三 20时19分34秒
 ************************************************************************/
#include <stdio.h>

int maxProfit(int* prices, int pricesSize){  
    int i,ph,ps;
    //第0天持有收益
    ph = -prices[0];
    //第0天卖出(不持有)收益
    ps = 0;
    for (i=1; i<pricesSize; i++) {
        ph = ph > ps - prices[i] ? ph : ps - prices[i];
        ps = ps > ph + prices[i] ? ps : ph + prices[i];
    }
    return ps;
}

void main() {
    int arr[6] = {7,1,5,3,6,4};
    int ret = maxProfit(arr, 6);
    printf("%d\n", ret);
}
