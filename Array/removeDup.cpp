/*
PS : Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each 
unique element appears only once.
Return the number of unique elements in the array.
Input: nums = [0, 0, 3, 3, 5, 6]
Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

//alises
using v = vector<int>;

//global declaration
v arr = {0 , 0 , 3 , 3, 5 , 6 , 6, 7};
int n = arr.size();

int removeDuplicates(vector<int> arr){

    //base condition
    if(arr.size() == 0) return 0;
    
    int i = 0;

    for(int j=1; j<n; j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main(){
    cout << removeDuplicates(arr) <<endl;
}