#include <stdio.h>
#include <stdlib.h>

// Node structure representing a term in the polynomial
typedef struct Node {
    int coefficient;  // Coefficient of the term
    int exponent;     // Exponent of the term
    struct Node* next;
}Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term in the polynomial in sorted order by exponent
void insertTerm(Node** poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exponent < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        Node* temp = *poly;
        while (temp->next != NULL && temp->next->exponent > exp) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exponent == exp) {
            temp->next->coefficient += coeff;  // Combine like terms
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to display the polynomial
void displayPolynomial(Node* poly) {
    while (poly != NULL) {
        printf("%d x^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            if (poly->next->coefficient > 0)
                printf(" + ");
            else
                printf(" - ");
        }
        poly = poly->next;
    }
    printf("\n");
}



// Adding 2 polynomials
void attach(int coeff,int exp,Node** ptr){
    // Creating a new node attaching it to the given pointer and then moving pointer to newNode
    Node *node=(Node*)malloc(sizeof(Node));
    node->coefficient=coeff;
    node->exponent=exp;
    (*ptr)->next=node;
    *ptr=node;
}
int compare(int a,int b){
    if (a==b) return 0;
    else if(a<b) return -1;
    else if(a>b) return 1;
}

Node* padd(Node *a,Node *b){

    Node* rear=(Node*)malloc(sizeof(Node));
    Node* head=rear;

    while(a && b){
        switch (compare(a->exponent,b->exponent))
        {
        case -1:
            attach(b->coefficient,b->exponent,&rear);
            b=b->next;
            break;

        case 0:
            int sum=a->coefficient+b->coefficient;
            if (sum) attach(sum,a->exponent,&rear);
            a=a->next;
            b=b->next;
            break;

        case 1:
            attach(a->coefficient,a->exponent,&rear);
            a=a->next;
            break;
        
        default:
            break;
        }
    }
    while(a){
        attach(a->coefficient,a->exponent,&rear);
        a=a->next;
    }
    while(b){
        attach(b->coefficient,b->exponent,&rear);
        b=b->next;
    }
    
    // Deleting dummy
    Node *dummy=head;
    head=head->next;
    free(dummy);

    return head;
}




// Multiplication 

struct Node* multiplyPolynomials(struct Node* header1, struct Node* header2) {
    struct Node* result = createNode(0, -1); // Header node for result
    struct Node* temp1 = header1->next;
    struct Node* temp2 = header2->next;

    while (temp1 != header1) {
        while (temp2 != header2) {
            int coeff = temp1->coefficient * temp2->coefficient;
            int exp = temp1->exponent + temp2->exponent;
            insertEnd(result, coeff, exp);
            temp2 = temp2->next;
        }
        temp2 = header2->next; // Reset temp2 to the start of the second polynomial
        temp1 = temp1->next;
    }

    return result;
}



//      Union and intersection:-- 

// Function to check if a node with given data exists in the list
int exists(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to perform the union of two sets
struct Node* unionLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;
    
    // Add all elements from the first list to the result
    while (temp != NULL) {
        insertEnd(&result, temp->data);
        temp = temp->next;
    }
    
    // Add elements from the second list if not already in the result
    temp = head2;
    while (temp != NULL) {
        if (!exists(result, temp->data)) {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

// Function to perform the intersection of two sets
struct Node* intersectionLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;
    
    // Find common elements in both lists
    while (temp != NULL) {
        if (exists(head2, temp->data)) {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}
