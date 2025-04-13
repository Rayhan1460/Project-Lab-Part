//QB: Reverse using stack
#include <stdio.h>
#include <stdlib.h>// Structure for a node in the linked list
struct Node {
    float data;
    struct Node* next;
};// Structure for a stack node
struct Stack {
    float data;
    struct Stack* next;
};// Function to create a new node for linked list
struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
            printf("Memory allocation failed\n");
    exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}// Function to push an element onto the stack
void push(struct Stack** top, float data) {
    struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
    if (newStackNode == NULL) {
            printf("Stack overflow\n");
    return;
    }
    newStackNode->data = data;
    newStackNode->next = *top;
    *top = newStackNode;
}// Function to check if stack is empty
int isEmpty(struct Stack* top) {
    return top == NULL;
}// Function to pop an element from the stack
float pop(struct Stack** top) {
    if (isEmpty(*top)) {
            printf("Stack underflow\n");
    return -1;
    }
    struct Stack* temp = *top;
    *top = (*top)->next;
    float popped = temp->data;
    free(temp);
    return popped;
}// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, float data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
            *head = newNode;
    return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
        }
        temp->next = newNode;
}// Function to print the linked list in original order
void printList(struct Node* head) {
struct Node* temp = head;
printf("Linked List (Original Order): ");
while (temp != NULL) {
printf("%.1f", temp->data);
if (temp->next != NULL) {
printf(" -> ");
}
temp = temp->next;
}
printf(" -> NULL\n");
}// Function to print the linked list in reverse order using stack
void printReverseUsingStack(struct Node* head) {
struct Stack* top = NULL;
struct Node* temp = head;// Push all elements onto the stack
while (temp != NULL) {
push(&top, temp->data);
temp = temp->next;
}
printf("Linked List (Reverse Order using Stack): ");// Pop elements from stack and print
while (!isEmpty(top)) {
printf("%.1f", pop(&top));
if (!isEmpty(top)) {
printf(" <- ");
}
}
printf(" <- NULL\n");
}
int main() {
struct Node* head = NULL;// Create the linked list
insertEnd(&head, 10.5);
insertEnd(&head, 6.21); // 'XX' in your example
insertEnd(&head, 15.7);
insertEnd(&head, 34.3);
printf("Initial ");
printList(head);// Display in reverse order using stack
printReverseUsingStack(head);// Free the memory
while (head != NULL) {
struct Node* temp = head;
head = head->next;
free(temp);
}
return 0;
}

