/*
 *  1742. 盒子中小球的最大数量
 *  https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box/
 */
#include <stdio.h>
#include <string.h>

void main() {
	int num;
	num = countBalls(1, 100000);
    printf("%d\n", num);
}
int countBalls(int lowLimit, int highLimit) 
{
    int i,temp;
    int num=0,max=0,maxNum=0;
    int arr[46];
    memset(arr, 0, 46 * sizeof(*arr));
    for(i=lowLimit; i<=highLimit; i++) {
		num = 0;
        temp = i;
        while(temp != 0) {
            num += temp%10;
            temp=temp/10;
        }
        arr[num] += 1;
        if (num > max) {
            max = num;
        }
    }
    for (i=1;i<=max;i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    return maxNum;   
}
