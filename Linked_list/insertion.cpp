/*
Linked List : it is a linear data structure.
in this each element is known as node 
in node -> data and next pointer that is pointing towards the next node
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

//method 1 : insert at beginning
void insertAtBeg(int data){
    Node *temp = new Node(); 
    temp -> data = data;
    temp -> next = head;
    head = temp;
}

//insert at middle of int given index
Node *insertAtMid(int x , int idx){

    //base condition
    if(idx == 1){
        insertAtBeg(x);
    }else if(idx < 0){
        return NULL;
    }

    Node *temp = new Node();
    temp -> data = x;
    temp -> next = NULL;

    //create pointers
    Node *ptr1 = NULL;
    Node *ptr2 = NULL;

    //ptr1 
    ptr1 = head;

    int i=0;
    while(i < idx-1){
        ptr2 = ptr1;
        ptr1 = ptr1 -> next;
        i++;
    }

    ptr2 -> next = temp;
    temp -> next = ptr1;

    return head;
}

//insert At last 
void insertAtLast(int x){
    Node *temp = new Node();
    temp -> data = x;
    temp -> next = NULL;

    Node *ptr = head;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = temp;
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
    // traverse();

    // //insert at beginning
    // cout <<endl << "Insert at beginning" << endl;
    // insertAtBeg(15);
    // traverse();

    //insert at mid
    // head = insertAtMid(6 , 3);
    // traverse();

    //insert at last 
    insertAtLast(20);
    traverse();
}