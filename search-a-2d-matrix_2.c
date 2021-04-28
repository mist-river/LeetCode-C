/*************************************************************************
  > File Name: search-a-2d-matrix.c
# File Name:    search-a-2d-matrix.c
# Author:       taofeiyang
# https://leetcode-cn.com/problems/search-a-2d-matrix/
# leetcode中对于函数原型的定义相当具有迷惑性
# 两次二分查找
# Created Time: 2021年04月27日 星期二 10时27分32秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int min=0;
    int max=matrixSize * matrixColSize[0] - 1;
    int indexRow,indexColumn,pos;
    while(max >= min) {
        pos = (max+min)/2;
        indexRow = pos/matrixColSize[0];
        indexColumn = pos%matrixColSize[0];
        if (matrix[indexRow][indexColumn] == target) {
            return true;
        } else if(matrix[indexRow][indexColumn] > target) {
            max = pos-1;
        } else {
            min = pos+1;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return -1;
    }
    int m[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int colSize[3] = {4, 4, 4};
    printf("矩阵：\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    int *a[3] = {m[0], m[1], m[2]};
    int ret = searchMatrix(a, 3, colSize, atoi(argv[1]));
    printf("%d\n", ret);
}
