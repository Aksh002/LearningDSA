#include <bits/stdc++.h>
using namespace std;

//                                                                      Declaration
/*
// Struct way(Not used jada)
struct Node{
    int data;
    Node *next;

    // Constructors
    Node(int x){
        data=x;
    }
};
*/

class Node{
    public:
    int data;
    Node *next;

    // Constructors
    public:
    Node(int x){
        data=x;
    }
    Node(int x, Node *next1){
        data=x;
        next=next1;
    }
};

//                                                      Array_To_LinkedList
Node *ArrToLL(vector<int>&arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i=1;i<arr.size();i++){
        Node *temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    } 
    return head;
}

//                                                      Traversal
void traverse(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

