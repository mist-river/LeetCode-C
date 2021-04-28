/*
 *  1742. 盒子中小球的最大数量
 *  https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box/
 */
#include <stdio.h>
#include <string.h>

void main() {
	int num;
	num = countBalls(1, 1);
    printf("%d\n", num);
}
int countBalls(int lowLimit, int highLimit) 
{
    int i;
    int num=0,max,maxNum=0;
    int arr[46];
    memset(arr, 0, 46 * sizeof(*arr));
    num = calNum(lowLimit);
    max = num;
    arr[num] += 1;
    for(i=lowLimit + 1; i<=highLimit; i++) {
        num ++;
        if ((i % 10) == 0) {
            num -= calZero(i) * 9;
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

int calZero(int i) {
    int num = 0;
    while(i != 0) {
        if (i % 10 == 0) {
            num += 1;
            i = i/10;
        } else {
            break;
        }
    }
    return num;
}

int calNum(int i) {
    int num = 0;
    while(i != 0) {
        num += i%10;
        i = i/10;
    }
    return num;
}
