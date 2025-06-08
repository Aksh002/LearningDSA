#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node* next;
    Node(int data1,Node* link1){
        data=data1;
        next=link1;
    }
    
};