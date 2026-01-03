/*
PS : Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that 
the sum of all elements in the subsequence is equal to k.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int k, int sum = 0){

    // base condition
    if(nums.size() == 0){
        if(sum == k) return 1;
        else return 0;
    }

    int op = nums[0];

    int op1 = sum;        // exclude
    int op2 = sum + op;   // include

    nums.erase(nums.begin());

    // exclude call
    int left = solve(nums, k, op1);

    // include call 
    int right = 0;
    if(op2 <= k){
        right = solve(nums, k, op2);
    }

    return left + right;
}

int main(){
    vector<int> nums = {4 , 9 , 2 , 5 , 1};
    int k = 10;
    cout << solve(nums, k);
}
