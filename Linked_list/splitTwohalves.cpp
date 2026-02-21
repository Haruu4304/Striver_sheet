#include<bits/stdc++.h>
using namespace std;

// Node structure
struct Node{
    int data;
    Node *next;
};

// Function to insert elements and make circular list
Node* insertElements(vector<int> &arr){

    if(arr.size() == 0)
        return NULL;

    Node *head = new Node();
    head->data = arr[0];
    head->next = NULL;

    Node *temp = head;

    for(int i = 1; i < arr.size(); i++){
        Node *ptr = new Node();
        ptr->data = arr[i];
        ptr->next = NULL;
        temp->next = ptr;
        temp = ptr;
    }

    // Make it circular
    temp->next = head;

    return head;
}

// Function to split circular linked list
pair<Node*, Node*> splitList(Node *head){

    if(head == NULL)
        return {NULL, NULL};

    if(head->next == head)   // Only one node
        return {head, NULL};

    Node *slow = head;
    Node *fast = head;

    // Find middle
    while(fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }

    // Even number of nodes
    if(fast->next->next == head){
        fast = fast->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next;

    // Make first half circular
    slow->next = head1;

    // Make second half circular
    fast->next = head2;

    return {head1, head2};
}

// Function to print circular list
void printCircular(Node *head){

    if(head == NULL){
        cout << "Empty\n";
        return;
    }

    Node *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

int main(){

    vector<int> arr = {1, 5, 7, 9, 10};

    Node *head = insertElements(arr);

    pair<Node*, Node*> result = splitList(head);

    cout << "First Circular List:\n";
    printCircular(result.first);

    cout << "Second Circular List:\n";
    printCircular(result.second);

    return 0;
}