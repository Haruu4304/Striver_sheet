/**
 * PS: Word Break
 *
 * Problem:
 *   Given a string s and a dictionary of words,
 *   determine if s can be segmented into a sequence
 *   of dictionary words.
 *
 * IP:
 *   - string s
 *   - vector<string> wordDict
 *
 * OP:
 *   - true / false
 *
 * APPROACH:
 *   - Backtracking (DFS on string index)
 *   - At every index, try all possible cuts (substrings)
 *   - If a prefix exists in dictionary, recurse on remaining string
 *   - If any path reaches end of string → return true
 *
 * TC:
 *   - Exponential ~ O(2^n) (worst case)
 *
 * SC:
 *   - O(n)  (recursion stack)
 *
 * LEARNING:
 *   - String partitioning using backtracking
 *   - Difference between substring(find) search vs dictionary lookup(count)
 *   - unordered_set::count() -> O(1) bcoz it uses hash table internally 
 *       → returns 1 if word exists, else 0
 */

#include<bits/stdc++.h>
using namespace std;

//alises -
using v = vector<string>;

//global varibales -
string s = "applepineapple";

unordered_set<string> dict = {"apple"};

bool solve(int p , string s){
    //base condition -
    if(p == s.size()) return true;

    string temp = "";
    //to iterate it 
    for(int i=p; i<s.size(); i++){
        temp.push_back(s[i]);

        //now 
        if(dict.count(temp)){
            //now to check in deeper
            if(solve(i+1 , s)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cout << (solve(0 , s) ? "TRUE" : "FALSE") << " "; 

}