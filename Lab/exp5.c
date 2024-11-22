//single link list
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* createNode(int new_data) {
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory is not allocated ");
        exit(0);
    }
    newnode->data = new_data;
    newnode->next = NULL;
    return newnode;
}

void insertNodeFromHead(node **head, int data_) {
    node* newnode = createNode(data_);
    newnode->next = *head;
    *head = newnode;   
}

void insertNodeFromEnd(node **head, int data_) {
    node* newnode = createNode(data_);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertNodeATSpecificPos(node **head, int data_, int pos) {
    node* newnode = createNode(data_);
    if (pos == 0) {  
        newnode->next = *head;
        *head = newnode;
        return;
    }
    node* temp = *head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteNode(node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void push_at_beginning(node **stack, int data) {
    insertNodeFromHead(stack, data);
}

void push_at_end(node **stack, int data) {
    insertNodeFromEnd(stack, data);
}

void push_at_position(node **stack, int data, int pos) {
    insertNodeATSpecificPos(stack, data, pos);
}

void pop(node **stack) {
    if (*stack == NULL) {
        printf("Underflow\n");
        return;
    }
    deleteNode(stack);
}

void printStack(node *stack) {
    node *x = stack;
    while (x != NULL) {
        printf("%d\t", x->data);
        x = x->next;
    }
    printf("\n");
}

void peek(node *stack) {
    if (stack != NULL) {
        printf("Top: %d\n", stack->data);
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    node *head = NULL;
    insertNodeFromHead(&head, 10);
    insertNodeFromHead(&head, 20);
    insertNodeFromEnd(&head, 30);
    insertNodeATSpecificPos(&head, 25, 2);

    printStack(head);
    
    peek(head);
    
    pop(&head);
    printStack(head);

    return 0;
}