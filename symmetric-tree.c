/*************************************************************************
    > File Name: symmetric-tree.c
# File Name:    symmetric-tree.c
# https://leetcode-cn.com/problems/symmetric-tree/
# Author:       mist-river
# Created Time: 2021年04月14日 星期三 17时05分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define bool int

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check(struct TreeNode *p, struct TreeNode *q) {
    if (!p && !q) {
        return 1;
    }
    if (!p || !q) {
        return 0;
    }
    return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
}


bool isSymmetric(struct TreeNode* root){
    return check(root->left, root->right);
}

//以层级顺序构造二叉树
int insertLevelOrder(int *arr, struct TreeNode *node, int arrSize, int i) {
    if (i >= arrSize) {
        return -1;
    }
    node->val = arr[i];
    node->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    insertLevelOrder(arr, node->left, arrSize, 2*i+1);
    node->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    insertLevelOrder(arr, node->right, arrSize, 2*i+2);
    return 0;
}

int main(void) {
    struct TreeNode node;
    int arr[7] = {1,2,2,3,4,4,3};
    int ret = insertLevelOrder(arr, &node, 7, 0);
    if (0 == ret) {
        printf("二叉树初始化成功！\n");
    }
    ret = isSymmetric(&node);
    printf("%d\n", ret);
}
