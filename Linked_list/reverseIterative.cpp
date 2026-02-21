/*
PS : Reverse a linked list by using iterative manner
*/

#include<bits/stdc++.h>
using namespace std;

//declare the node structure
struct Node{
    int data;
    Node *next;
}*head = NULL;

//insert the elements from array
void insertElements(vector<int> &arr){

    //base condition 
    if(arr.size() == 0){
        return;
    }

    Node *temp = NULL;

    //allocate memory
    head = new Node();
    head -> data = arr[0];
    head -> next = NULL;
    temp = head;

    for(int i=1; i<arr.size(); i++){
        Node *ptr = new Node(); //allocate memory
        ptr -> data = arr[i];
        ptr -> next = NULL;
        temp -> next = ptr;
        temp = ptr;
    }
}


//reverse in iterative way
Node *reverseIterative(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //pointers 
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

//traversing
void traverse(){
    //create one pointer 
    Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next; //move forward
    }
}

int main(){
    vector<int> arr = {1 , 5 , 7 ,9 ,10};
    insertElements(arr);

    head = reverseIterative(head);
    traverse();
}