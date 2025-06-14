#include <bits/stdc++.h>
using namespace std;

// The slow-fast pointer method used in the mergeSort implementation is a classic technique for finding the middle of a linked list.
struct Node{
    int data;
    struct Node *next;

    Node(int x){
        data=x;
        next=NULL;
    };
};

int main(Node *head){
    
        return 0;
}

void mid(Node *head){
    Node *slow = head;      // Slow pointer starts at the head
    Node *fast = head->next; // Fast pointer starts at the second node

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Slow moves one step
        fast = fast->next->next;    // Fast moves two steps
    }
    Node* mid = slow->next;         // Mid is the start of the right half
    slow->next = NULL;              // Disconnect the left half
}
