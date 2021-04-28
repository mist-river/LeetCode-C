/*************************************************************************
    > File Name: swap-nodes-in-pairs.c
# File Name:    swap-nodes-in-pairs.c
# Author:       jintao5
# https://leetcode-cn.com/problems/swap-nodes-in-pairs/
# Created Time: 2021年04月13日 星期二 11时23分28秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode *temp = &dummyHead;
    while (temp->next != NULL && temp->next->next != NULL) {
        struct ListNode *node1 = temp->next;
        struct ListNode *node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead.next;
}

int main() {
    int i;
    //初始化链表
    struct ListNode * head, * temp;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head;
    for (i=1; i<8; i++) {
        struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = i;
        n->next = NULL;
        temp->next = n;
        temp = temp->next;
    }
    head = swapPairs(head->next);
    //遍历链表
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}

