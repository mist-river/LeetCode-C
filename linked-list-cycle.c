/*************************************************************************
  > File Name: linked-list-cycle.c
# File Name:    linked-list-cycle.c
# Author:       mist-river
# https://leetcode-cn.com/problems/linked-list-cycle/
# 龟兔赛跑算法
# (v2-v1) * t = m * n - step
# step为初始步差 v2 v1分别代表兔子和乌龟的速度, t代表执行次数，m代表兔子在环路超越次数，n代表环路节点数
# 如果step为1 则必定有解
# Created Time: 2021年04月15日 星期四 20时39分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    if (head == NULL) {
        return 0;
    }
    slow = head;
    fast = head->next;
    while (fast != slow) {
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return 1;
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
    //形成环
    /*temp->next = head->next;*/
    bool ret = hasCycle(head->next);
    printf("%d\n", ret);
}

