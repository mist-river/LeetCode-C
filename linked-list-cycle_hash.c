/*************************************************************************
  > File Name: linked-list-cycle.c
# File Name:    linked-list-cycle.c
# Author:       mist-river
# https://leetcode-cn.com/problems/linked-list-cycle/
# Created Time: 2021年04月15日 星期四 20时39分17秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

typedef int bool;
typedef struct ListNode * keytype;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct my_hash {
    keytype k;            /* we'll use this field as the key */
    int v;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_hash *hashTable = NULL;

struct my_hash *find(keytype num) {
    struct my_hash *h;

    HASH_FIND_INT(hashTable, &num, h);
    return h;
}

void insert(keytype k, int v) {
    struct my_hash* tmp = malloc(sizeof(struct my_hash));
    tmp->k = k, tmp->v = v;
    HASH_ADD_INT(hashTable, k, tmp);
}

bool hasCycle(struct ListNode *head) {
    struct ListNode *temp;
    temp = head;
    while (temp != NULL) {
        struct my_hash *item = find(temp);
        if (item == NULL) {
            insert(temp, 1);
        } else {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
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
    temp->next = head->next;
    bool ret = hasCycle(head->next);
    printf("%d\n", ret);
}

