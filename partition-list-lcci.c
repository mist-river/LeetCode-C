/*************************************************************************
    > File Name: partition-list-lcci.c
# File Name:    partition-list-lcci.c
# Author:       mist-river
# https://leetcode-cn.com/problems/partition-list-lcci/
# Created Time: 2021年04月17日 星期六 18时06分38秒
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

typedef struct ListNode * list;

struct ListNode* partition(struct ListNode* head, int x){  
    list temp = head;
    list ls = malloc(sizeof(struct ListNode));
    list gs = malloc(sizeof(struct ListNode));
    list le = ls;
    list ge = gs;
    gs->next = NULL;
    ls->next = NULL;
    if (temp == NULL || temp->next == NULL) {
        return head;
    }
    while (temp != NULL) {
        if (temp->val < x) {
            le->next = temp;
            le = le->next;
        } else {
            ge->next = temp;
            ge = ge->next;
        }
        temp = temp->next;
    }
    le->next = gs->next;
    ge->next = NULL;
    temp = ls->next;
    free(ls);
    free(gs);
    return temp;
}

int main() {
    int i;
    //初始化链表
    struct ListNode * head, * temp;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head;
    for (i=2; i>0; i--) {
        struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = 1;
        n->next = NULL;
        temp->next = n;
        temp = temp->next;
    }
    head = partition(head->next, 4);
    //遍历链表
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}
