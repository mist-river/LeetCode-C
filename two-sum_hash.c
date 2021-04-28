/*************************************************************************
    > File Name: two-sum.c
# File Name:    two-sum.c
# Author:       jintao5
# https://leetcode-cn.com/problems/two-sum/
# Created Time: 2021年04月13日 星期二 22时54分39秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

struct my_hash {
    int k;            /* we'll use this field as the key */
    int v;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_hash *hashTable = NULL;

struct my_hash *find(int num) {
    struct my_hash *h;

    HASH_FIND_INT(hashTable, &num, h);
    return h;
}

void insert(int k, int v) {
    struct my_hash* i = find(k);
    if (i == NULL) {
        struct my_hash* tmp = malloc(sizeof(struct my_hash));
        tmp->k = k, tmp->v = v;
        HASH_ADD_INT(hashTable, k, tmp);
    } else {
        i->v = v;
    }
}

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    hashTable = NULL;
    int i, j;
    int *arr;
    *returnSize = 0;
    for (i=0; i<numsSize; i++) {
        struct my_hash *item = find(target - nums[i]);
        if (item != NULL && item->v != i) {
            int *ret = malloc(sizeof(int) * 2);
            ret[0] = i;
            ret[1] = item->v;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    return arr;
}

int main (int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return -1;
    }
    int nums[] = {-10, 7, 19, 15};
    int target = atoi(argv[1]);
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;
    int *res;
    res = twoSum(nums, numsSize, target, &returnSize);
    int i;
    for (i=0; i<returnSize; i++) {
        printf("%d\n", res[i]);
    }
}
