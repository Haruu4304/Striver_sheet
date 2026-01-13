/*
PS : Given an array of integers nums, return the second-largest element in the array. 
If the second-largest element does not exist, return -1.
Example 1
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation:
The largest value in nums is 8, the second largest is 7
*/

#include<bits/stdc++.h>
using namespace std;

//alises
using v = vector<int>;

//global declaration 
v arr = {10, 10 , 10  ,10};
int n = arr.size();
int largest = -1;
int secondLargest = 0;

void secondLar(int n){
    for(int i=0; i<n; i++){
        //condtion1 
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        //if not
        else if(arr[i] < largest && arr[i] > secondLargest){
            secondLargest = arr[i];
        }
    }
}

int main(){
    secondLar(n);

    cout << "The second largest element is : " << secondLargest;
}