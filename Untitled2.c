/*QA: delete ‘XX’ from the linked list
xx = last sgpa +3.21
= 3.56+3.21
= 6.77
Code for Delete:*/
#include <stdio.h>
#include <stdlib.h>// Structure for a node in the linked list
struct Node {
float data;
struct Node* next;
}; // Function to create a new node
struct Node* createNode(float data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
} // Function to insert a node at the end of the list
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
} // Function to delete a node with given data
void deleteNode(struct Node** head, float data) {
if (*head == NULL) {
printf("List is empty\n");
return;
}
struct Node *temp = *head, *prev = NULL; // If head node itself holds the data to be

if (temp != NULL && temp->data == data) {
*head = temp->next;
free(temp);
printf("Node with value %.2f deleted successfully\n", data);
return;
}
// Search for the node to be deleted
while (temp != NULL && temp->data != data) {
prev = temp;
temp = temp->next;
}
// If data was not found in the list
if (temp == NULL) {
printf("Node with value %.2f not found in the list\n", data);
return;
} // Unlink the node from the list
prev->next = temp->next;
free(temp);
printf("Node with value %.2f deleted successfully\n", data);
} // Function to print the linked list
void printList(struct Node* head) {
struct Node* temp = head;
printf("Linked List: ");
while (temp != NULL) {
printf("%.2f", temp->data);
if (temp->next != NULL) {
printf(" -> ");
}
temp = temp->next;
}
printf(" -> NULL\n");
}
int main() {
struct Node* head = NULL;// Create the linked list (initial values)
insertEnd(&head, 10.5);
insertEnd(&head, 6.77); // This is 'XX' = SGPA + 3.21 (3.56 + 3.21)
insertEnd(&head, 15.7);
insertEnd(&head, 34.3);
printf("Initial ");
printList(head);
float valueToDelete;
printf("\nEnter the value you want to delete: ");
scanf("%f", &valueToDelete);
deleteNode(&head, valueToDelete);
printf("\nAfter deletion ");
printList(head);// Free the remaining memory
while (head != NULL) {
struct Node* temp = head;
head = head->next;
free(temp);
}
return 0;
}


