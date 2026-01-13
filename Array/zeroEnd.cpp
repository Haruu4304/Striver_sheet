/*
PS : Given an integer array nums, move all the 0's to the end of the array. The relative order of the other 
elements must remain the same.
This must be done in place, without making a copy of the array.
Example 1
Input: nums = [0, 1, 4, 0, 5, 2]
Output: [1, 4, 5, 2, 0, 0]
*/

#include<bits/stdc++.h>
using namespace std;

//alises
using v = vector<int>;

//global declaration
v arr = {0 , 1 , 4 , 0, 5,2};
int n = arr.size();

void movezerotoEnd(vector<int> &arr){
    int k = 0; //to store non-zero elements

    //step 1 :  now move forward these non-zero elemens
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[k++] = arr[i];
        }
    }

    //step 2 : now fill 0 
    while(k < n){
        arr[k++] = 0;
    }
}

int main(){
    movezerotoEnd(arr);

    //to display
    for(auto x : arr){
        cout << x << " ";
    }
}