//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct node NODE;
typedef NODE* NodePtr;

int main(int argc, const char * argv[]) {

    int c = 5;
    struct node a, b, d, e, f;
    NodePtr head, tmp;

    a.value = c;
    a.next = &b;
    head = &a;
    b.value = head->value + 3; // 8
    b.next = &d;
    d.value = 11;
    d.next = NULL;

    printf("%d\n", head->value);// 5
    printf("%d\n", head->next->value);// 8
    printf("%d\n", head->next->next->value);// 11

    e.value = 2;
    e.next = head;
    head = &e;

    f.value = 6;
    f.next = &b;
    a.next = &f;

    printf("Print using while loop\n");
    tmp = head;
    while (tmp) {
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

    printf("Create nodes by malloc\n");
    int i, n = 5;
    NodePtr mhead, temp;
    mhead = (NodePtr)malloc(sizeof(NODE));
    temp = mhead;

    for (i = 0; i < n; i++) {
        temp->value = 7 + i * 2;
        temp->next = (NodePtr)malloc(sizeof(NODE));
        temp = temp->next;
        
    }

    tmp = mhead;
    while (tmp) {
        printf("%5d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

    /* Free*/
    tmp = mhead;
    while (tmp) {
        NodePtr next = tmp->next;
        printf("Freeing %d\n", tmp->value);
        free(tmp);
        tmp = next;
    }

    return 0;
}
