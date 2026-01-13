/*
PS : Given an array of integers nums, return the value of the largest element in the array
Example 1
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6
Analsis - 
TC - O(n)
SC - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

//alises 
using v = vector<int>;

//global declaration
v nums = {3 , 3 ,6 , 1};
int n = nums.size();
int ans = nums[0];

void solve(int n){
    //to traverse whole array
    for(int i=1; i<n; i++){
        //here we will check 
        if(nums[i] > ans){
            ans = nums[i];
        }
    }
}

int main(){
    solve(n);
    cout << "Largest element : " << ans << " ";
}