#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;    // We are basically defining another variable of type Node, which is a pointer 
} Node;

/*
// Another way

struct Node1{
    int data;
    struct Node1 *next;
};
//struct Node *temp=... and sttruct Node *head=NULL inside main fxn
*/

// Function to create a new node 
Node* createNode(int data) {
    Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(Node** head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

//Function to insert a new element at the end of the singly linked list
void append(Node **head,int a){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->next=NULL;
    temp->data=a;

    if (*head==NULL){
        *head=temp;
        return;
    }
    Node *temp2=*head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}

void insertion(Node **head,int pos,int data){
    int i;
    Node *temp=*head;
    if (*head==NULL || pos==1){
        Node *node=(Node*)malloc(sizeof(Node));
        node->data=data;
        node->next=*head;
        *head=node;
        printf("Element inserted at start of the list as list was empty ");

        //append(head,data) could be used too
        return;
    }
    for(i=0;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("position out of index");
        return;
    }
    Node *node=(Node*)malloc(sizeof(Node));
    node->next=temp->next;
    node->data=data;
    temp->next=node;
}

// Function to delete the first node of the singly linked list
void deleteFromFirst(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(Node **head){
    if (*head==NULL){
        printf("Nothing to delete \n");
        return;
    }    
    Node *temp=*head;
    if (temp->next==NULL){
        *head=NULL;
        temp->next=NULL;
        free(temp);
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node *del=temp->next;
    temp->next=NULL;
    free(del);
}

void sel_deletion(Node **head,int pos){
    if (*head==NULL){
        printf("Nothing to delete \n");
        return;
    }
    if (pos==1){
        Node* temp = *head;
        *head = temp->next;
        free(temp);
    }
    Node *temp=*head;
    
    int i;
    for (i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if (temp==NULL || temp->next==NULL){
        printf("Position out of index");
        return;
    }
    Node *del=temp->next;
    temp->next=del->next;
    del->next=NULL;
    free(del);
}

void display(Node *head){
    if (head==NULL){
        printf("List is empty");
        return;
    }
    Node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

void rec_display(Node *temp){
    if(temp!=NULL){
        printf("%d -> ",temp->data);
        rec_display(temp->next);
        // Output = l1 -> l2 -> l3 -> l4
        /*
        rec_display(temp->next);
        printf("%d -> ",temp->data);
        // Output = l4 -> l3 -> l2 -> l1
        */
    }
}       // TC= O(N)

void create_at_once(Node **head,int a[],int n){
    int i;
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=a[0];
    node->next=NULL;
    *head=node;
    Node *last=node;
    for (i=1;i<n;i++){
        node=(Node*)malloc(sizeof(Node));
        node->data=a[i];
        node->next=NULL;
        last->next=node;
        last=node;        
    }
}

int main(){
    struct Node* head = NULL;
    
    insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head); 
    
    printf("Linked list after inserting the node:20 at the end \n");
    insertAtEnd(&head, 20);
    print(head); 
    
    printf("Linked list after inserting the node:5 at the end \n");
    insertAtEnd(&head, 5);
    print(head); 
    
    printf("Linked list after inserting the node:30 at the end \n");
    insertAtEnd(&head, 30);
    print(head); 
    
    printf("Linked list after inserting the node:15 at position 2 \n");
    insertAtPosition(&head, 15, 2);
    print(head);
    
    printf("Linked list after deleting the first node: \n");
    deleteFromFirst(&head);
    print(head); 
    
    printf("Linked list after deleting the last node: \n");
    deleteFromEnd(&head);
    print(head); 
    
    printf("Linked list after deleting the node at position 1: \n");
    deleteAtPosition(&head, 1);
    print(head); 

    return 0;
}

// Operations :-

int countNodesIterative(Node *head) {
    int count = 0;
    Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Recursive method to count the number of nodes
int countNodesRecursive(Node *head) {
    // Base case: if the node is NULL, return 0
    if (head == NULL) {
        return 0;
    }

    // Recursive case: 1 + count of nodes in the rest of the list
    return 1 + countNodesRecursive(head->next);
}

// Iterative function to calculate the sum of node data
int sumOfNodesIterative(Node *head) {
    int sum = 0;
    Node *temp = head;

    while (temp != NULL) {
        sum += temp->data;  // Add the data of each node to the sum
        temp = temp->next;  // Move to the next node
    }

    return sum;
}

// Recursive function to calculate the sum of node data
int sumOfNodesRecursive(Node *head) {
    if (head == NULL) {
        return 0;  // Base case: return 0 if the list is empty
    }

    return head->data + sumOfNodesRecursive(head->next);  // Recursive call
}

// Iterative metho to find max element in LL
int findMaxIterative(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return -1; // or some error code
    }

    int max = head->data; // Initialize max with the first element
    Node *current = head->next;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data; // Update max if a larger value is found
        }
        current = current->next; // Move to the next node
    }
    
    return max;
}

// Recursive approach to find max element in LL
int findMaxRecursive(Node *head) {
    // Base case: if the list is empty
    if (head == NULL) {
        return -1; // or some error code
    }
    
    // Base case: if we reach the last node
    if (head->next == NULL) {
        return head->data; // Return the last node's data
    }

    // Recursive case: get the maximum of the rest of the list
    int maxInRest = findMaxRecursive(head->next);
    
    // Return the maximum between the current node and the maximum of the rest
    return (head->data > maxInRest) ? head->data : maxInRest;
}

// Reversing a Linked lists
Node* invert(Node *lead)
{
    Node *middle, *trail;
    middle = NULL;
    while (lead) {
        trail = middle;
        middle = lead;
        lead = lead->next;
        middle->next = trail;

    }
    return middle;
}