/*
PS : Given an array of integers nums of unique elements. Return all possible subsets (power set) 
of the array.

Do not include the duplicates in the answer.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void solve(vector<int> ip ,vector<int> op){
    if(ip.size() == 0){
        result.push_back(op);
        return;
    }

    vector<int> op1 = op; //exclude
    vector<int> op2 = op; //include

    op2.push_back(ip[0]);
    ip.erase(ip.begin()); //remove that input
    solve(ip , op1);
    solve(ip , op2);
}

vector<vector<int>> powerSet(vector<int> &nums){
    vector<int> op;
    solve(nums , op);
    return result;
}


int main(){
    vector<int> nums = {1,2};
    powerSet(nums);

    for(auto subset : result){
        cout << "{ ";
        for(int x : subset){
            cout << x << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}