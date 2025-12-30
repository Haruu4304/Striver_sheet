/*
PS : Given an integer n, return all binary strings of length n that do not contain consecutive 1s. 
Return the result in lexicographically increasing order.

A binary string is a string consisting only of characters '0' and '1'.
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int ones , int zeros , int n , string op){

    vector<string> result;

    //base condition - 
    if(n == 0){
        cout << op << " ";
        result.push_back(op);
        return result;
    }

    if(ones > zeros){
        string op1 = op;
        op1.push_back('0');
        solve(ones , zeros+1 , n-1 , op1);
    }else{
        string op1 = op;
        op1.push_back('0');
        solve(ones , zeros+1 , n-1 , op1);

        if(op.empty() || op.back() == '0'){
            string op2 = op;
            op2.push_back('1');
            solve(ones+1 , zeros , n-1 , op2);
        }
    }
}

vector<string> generateBinaryStrings(int n){
    return solve(0 , 0 , n , "");
}

int main(){
    int n = 3;
    generateBinaryStrings(n);
    return 0;
}