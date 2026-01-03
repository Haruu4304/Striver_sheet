/*
PS : Given n pairs of parentheses, write a function to generate all combinations of well-formed 
parentheses.
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int open , int close , string op){

    vector<string> result;

    if(open == 0 && close == 0){
        cout << op << " ";
        result.push_back(op);
        return result;
    }

    if(open > 0){
        string op1 = op;
        op1.push_back('(');
        solve(open-1 , close , op1);
    }
    
    if(close > open){
        string op1 = op;
        op1.push_back(')');
        solve(open , close-1 , op1);
    }

}

vector<string> generateParenthesis(int n){
    return solve(n , n , " ");
}

int main(){
    int n = 3;
    generateParenthesis(n);
    return 0;
}