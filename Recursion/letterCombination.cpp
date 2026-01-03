/*
PS :  Given a string consisting of digits from 2 to 9 (inclusive). Return all possible letter 
combinations that the number can represent.
Mapping of digits to letters is given in first example.

* The mapping of digits to letters is given as follows:
 * 2 -> "abc"
 * 3 -> "def"
 * 4 -> "ghi"
 * 5 -> "jkl"
 * 6 -> "mno"
 * 7 -> "pqrs"
 * 8 -> "tuv"
 * 9 -> "wxyz"
 * Note: 1 does not map to any letters.

TC: O(4^n)
SC: O(n)

example - 
Input : digits = "34"
Output : [ "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi" ]
*/

#include<bits/stdc++.h>
using namespace std;

//alises 
using v = vector<string>;

v ans;

v alpha = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void solve(string digits , int idx , int i , string s){
    //base condition - 
    if(idx == digits.size()){
        ans.push_back(s);
        return;
    }

    //convert string into integer
    int d = digits[idx] - '0';

    //Prunning condition
    if(i >= alpha[d].size()) return;

    //push letter in s - 
    s.push_back(alpha[d][i]);

    //again call
    solve(digits , idx+1 , 0 , s);

    // When it reaches to leaf node then backtrack 
    // Then pop from s
    s.pop_back();

    //again call
    solve(digits , idx , i + 1 , s);
}

int main(){
    string digits = "34";
    string s = "";

    solve(digits, 0, 0, s);

    // Display ans 
    for(auto x: ans) {
        cout << x << " ";
    }
}