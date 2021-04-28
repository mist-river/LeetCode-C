/*************************************************************************
    > File Name: lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.c
# File Name:    lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.c
# https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
# Author:       mist-river
# Created Time: 2021年04月08日 星期四 18时19分57秒
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

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode * temp1, *temp2;
    temp1 = head;
    temp2 = head;
    int count = 0;
    do {
        count++;
        if (k <= count - 1) {
            temp2 = temp2->next;
        }
    } while ((temp1 = temp1->next) != NULL);
    return temp2;
}

int main() {
    int i;
    //初始化链表
    struct ListNode * head, * temp,  * node;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head;
    for (i=1; i<6; i++) {
        struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = i;
        n->next = NULL;
        temp->next = n;
        temp = temp->next;
    }
    node = getKthFromEnd(head, 2);
    printf("%d\n", node->val);
}
