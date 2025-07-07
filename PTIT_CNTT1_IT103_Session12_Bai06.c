#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho dong");
        return NULL;
    }
    newNode-> data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printlist(Node* head) {
    printf("NULL");
    while (head != NULL) {
        printf(" <--> %d", head->data);
        head = head->next;
    }
    printf(" --> NULL\n");
}

int getLength(Node* head) {
    int length = 0;
    struct Node* current = head;
    if (current == NULL) {
        return 0;
    }
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

Node* findMiddle(Node* head) {
    int length = getLength(head);
    if (length == 0) return NULL;

    int midIndex = length / 2;

    Node* current = head;
    for (int i = 0; i < midIndex; i++) {
        current = current->next;
    }

    return current;
}

int main(void) {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);

    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;

    printf("Phan tu nam o giua danh sach lien ket la: %d", findMiddle(head)->data);
    return 0;
}