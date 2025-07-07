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

Node* deleteNode(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            Node* delete = current;

            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
            else {
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                }
            }
            current = current->next;
            free(delete);
        }
        else {
            current = current->next;
        }
    }
    return head;
}

int main(void) {
    int x;
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

    printf("Moi ban nhap vao gia tri can xoa: ");
    scanf("%d", &x);

    head = deleteNode(head, x);

    printlist(head);
    return 0;
}