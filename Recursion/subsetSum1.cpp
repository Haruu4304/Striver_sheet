/*
PS : Given an array nums of n integers. Return array of sum of all subsets of the array nums.

Output can be returned in any order.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> nums , int op){
    vector<int> result;
    //base condition - 
    if(nums.size() == 0){
       cout << op << endl;
       result.push_back(op);
       return result;
    }

    int op1 = op;
    int op2 = op + nums[0];
    nums.erase(nums.begin() + 0);
    solve(nums , op1);
    solve(nums , op2);
}

vector<int> subsetSums(vector<int> &nums){
    int op = 0;
    return solve(nums , op);
}

int main(){
    vector<int> nums = {2,3};
    subsetSums(nums);
    return 0;
}