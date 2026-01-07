/*
PS : Permutation
IP = string of letters
OP = all possible arrangements
TC = O(n!)
SC = O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// aliases
using v = vector<string>;

// global declarations
string str = "ABC";
vector<bool> sel = {false, false, false};
string res;          // stores one permutation
v ans;               // stores all permutations
int n = str.size();

// function
void perm(int k){
    // Base Case
    if(k == n){
        ans.push_back(res);
        return;
    }

    // Try all characters
    for(int i = 0; i < n; i++){
        if(sel[i] == false){
            res[k] = str[i];   // place character
            sel[i] = true;     // mark selected
            perm(k + 1);
            sel[i] = false;    // backtrack
        }
    }
}

int main(){
    res.resize(n);
    perm(0);

    // display result
    for(auto result : ans){
        cout << result << endl;
    }
}
