/*
PS : Remove nth node from end of the list 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
}*head = NULL;

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

Node *removeNthFromEnd(Node *head , int n){
    if(head == NULL){
        return NULL;
    }else if(n == 1){
        return 1;
    }

    Node *f = head;
    Node *l = head;

    int d = 0;
    while(d < n){
        if(l == NULL)   // if n > length
            return head;
        l = l->next;
        d++;
    }

    // if l becomes NULL → delete head
    if(l == NULL){
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while(l -> next != NULL){
        f = f-> next;
        l = l -> next;
    }
    Node *temp = f->next;
    f->next = f->next->next;
    delete temp;

    return head;
}

void traverse(Node *head){

    Node *ptr = head;

    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    insertElements(arr);
    traverse(head);

    cout << endl;

    head = removeNthFromEnd(head , 2);
    traverse(head);
}