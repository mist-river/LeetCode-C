/*************************************************************************
    > File Name: merge-two-sorted-lists.c
# File Name:    merge-two-sorted-lists.c
# https://leetcode-cn.com/problems/merge-two-sorted-lists/
# Author:       jintao5
# Created Time: 2021年04月11日 星期日 20时18分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode *list, *temp;
    list = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp  = list;
    struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (l1->val <= l2->val) {
        n->val = l1->val;
        n->next = NULL;
        temp->next = n;
        temp = temp->next;
        l1 = l1->next;
    } else if(l1->val > l2->val) {
        n->val = l2->val;
        n->next = NULL;
        temp->next = n;
        temp = temp->next;
        l2 = l2->next;
    }
    if (l1 == NULL) {
        temp->next = l2;
    } else if (l2 == NULL) {
        temp->next = l1;
    } else {
        temp->next = mergeTwoLists(l1, l2);
    }
    return list->next;
}

int main() {
    int i;
    //初始化链表1、链表2
    struct ListNode * head1, * temp1, * head2, * temp2, *list;
    head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp1 = head1;
    temp2 = head2;
    for (i=1; i<1; i++) {
        struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = i;
        n->next = NULL;
        temp1->next = n;
        temp1 = temp1->next;
    }
    for (i=2; i<1; i++) {
        struct ListNode *m = (struct ListNode *)malloc(sizeof(struct ListNode));
        m->val = i;
        m->next = NULL;
        temp2->next = m;
        temp2 = temp2->next;
    }
	list = mergeTwoLists(head1->next, head2->next);
    temp1 = list;
    while (temp1 != NULL) {
        printf("%d\n", temp1->val);
        temp1 = temp1->next;
    }
}
