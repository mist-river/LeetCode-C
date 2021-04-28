/*************************************************************************
    > File Name: remove-duplicates-from-sorted-list.c
# File Name:    remove-duplicates-from-sorted-list.c
# Author:       mist-river
# https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
# Created Time: 2021年04月16日 星期五 21时01分49秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return head;
    }
    struct ListNode *temp;
    temp = head;
    while (temp->next != NULL) {
        if (temp->val == temp->next->val) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    int i;
    //初始化链表
    struct ListNode * head, * temp;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head;
    for (i=1; i<8; i++) {
        struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = i/2 + 1;
        n->next = NULL;
        temp->next = n;
        temp = temp->next;
    }
    head = deleteDuplicates(head->next);
    //遍历链表
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}


