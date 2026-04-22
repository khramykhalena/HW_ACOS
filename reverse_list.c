#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *push_back(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) return head;

    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) return new_node;

    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new_node;

    return head;
}

Node *reverse_list(Node *head) {
    Node *prev = NULL;
    Node *cur = head;

    while (cur != NULL) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void print_list(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next != NULL) printf(" ");
        cur = cur->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void) {
    Node *head = NULL;
    int x;

    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        head = push_back(head, x);
    }

    head = reverse_list(head);
    print_list(head);
    free_list(head);

    return 0;
}
