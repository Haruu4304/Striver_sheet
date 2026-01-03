/*
PS : Given an integer array nums, which can have duplicate entries, provide the power set.

Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.
*/

#include<bits/stdc++.h>
using namespace std;

set<vector<int>> result;

void solve(vector<int> nums , vector<int> op){
    //base condition 
    if(nums.size() == 0){
        result.insert(op);
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;
    op2.push_back(nums[0]);
    nums.erase(nums.begin() + 0);
    if(op1.back() != op2.back()){
        solve(nums , op1);
    }
    solve(nums , op2);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    vector<int> op;
    solve(nums , op);
    return vector<vector<int>>(result.begin(), result.end());;
}

int main(){
    vector<int> nums = {1 , 2 , 2};
    subsetsWithDup(nums);


    for(auto subset : result){
        cout << "[ ";
        for(int x : subset){
            cout << x << " ";
        }
        cout << "]" << endl;
    }
}