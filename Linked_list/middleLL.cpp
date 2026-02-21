/*
PS : Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
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

//find the middle node
Node *middleNode(Node *head){
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
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
    vector<int> arr = {1, 2, 3 , 4 ,5 , 6};
    insertElements(arr);

    Node *result = middleNode(head);
    cout << result -> data;
}