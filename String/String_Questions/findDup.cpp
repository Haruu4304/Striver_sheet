/*
PS : find duplicate character
IP : string
OP : characters
Analysis : 
*/

#include <bits/stdc++.h>
using namespace std;

// aliases
using v = vector<char>;

// global declaration
string s = "harsha";
unordered_map<char, int> freq;
v ans;   // to store duplicate characters

void findDuplicates(string s) {
    for (char x : s) {
        freq[x]++;

        // add only when count is greater than 1(first time duplicate)
        if (freq[x] > 1) {
            ans.push_back(x);
        }
    }
}

int main() {
    findDuplicates(s);

    // display
    for (char x : ans) {
        cout << x << " ";
    }
}