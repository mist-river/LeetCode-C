/*************************************************************************
    > File Name: remove-nth-node-from-end-of-list.c
# File Name:    remove-nth-node-from-end-of-list.c
# Author:       jintao5
# https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
# Created Time: 2021年04月10日 星期六 21时02分24秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode * temp1, *temp2;
    temp1 = head;
    temp2 = head;
    int count = 0;
    do {
        count++;
        if (n <= count - 2) {
            temp2 = temp2->next;
        }
    } while ((temp1 = temp1->next) != NULL);
    if (n == count) {
        head = temp2->next;
    } else if (temp2->next != NULL) {
        temp2->next = temp2->next->next;
    }
    return head;
}

int main() {
    int i;
    //初始化链表
    struct ListNode * head, * temp;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head;
    for (i=1; i<2; i++) {
        struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = i;
        n->next = NULL;
        temp->next = n;
        temp = temp->next;
    }
    head = removeNthFromEnd(head, 1);
    //遍历链表
    temp = head;
    while ((temp = temp->next) != NULL) {
        printf("%d\n", temp->val);
    }
}

