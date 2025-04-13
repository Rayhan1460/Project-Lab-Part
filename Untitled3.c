//QL-1
#include <stdio.h>
#include <stdlib.h>
struct node {// Structure for BST node
int data;
struct node *left;
struct node *right;
};
struct node* createNode(int value) {// Function to create a new node
struct node* newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = value;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
struct node* insert(struct node* root, int value) {// Function to insert a node in BST
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}
void searchWithSteps(struct node* root, int value) {// Function to search a value in BST
if (root == NULL) {
printf("Value %d not found in BST.\n", value);
return;
}
printf("Current node: %d", root->data);
if (root->data == value) {
printf(" → Found the value!\n");
return;
} else if (value < root->data) {
printf(" → %d < %d, moving left\n", value, root->data);
searchWithSteps(root->left, value);
} else {
printf(" → %d > %d, moving right\n", value, root->data);
searchWithSteps(root->right, value);
}
}
void inorder(struct node* root) { // Inorder traversal (left-root-right)
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
int main() {
struct node* root = NULL;
int numbers[] = {26, 45, 72, 29, 108, 120, 86, 99, 52, 135};// Mr. Arif's selected numbers
int size = sizeof(numbers) / sizeof(numbers[0]);
for (int i = 0; i < size; i++) { // Insert all numbers into BST
root = insert(root, numbers[i]);
}
printf("BST created with Mr. Arif's numbers:\n");
printf("Inorder traversal (sorted order): ");
inorder(root);
printf("\n\n");
int searchValue;// User interaction for searching values
char choice;
do {
printf("\nEnter a value to search in the BST: ");
scanf("%d", &searchValue);
printf("\nSearching for %d in the BST:\n", searchValue);
searchWithSteps(root, searchValue);
printf("\nDo you want to search another value? (y/n): ");
scanf(" %c", &choice); // Note the space before %c to consume newline
} while (choice == 'y' || choice == 'Y');
printf("\nThank you for using the BST search program!\n");
return 0;
}
