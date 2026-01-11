/*
PS : here we have to search that string word present in that board.
analysis -
tc = n * 4^l
sc = O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

//alises - 
using v = vector<char>;
using vv = vector<v>;

//global variables
int m = 3, n = 4;

vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};

string word = "ABCB";

bool solve(int i, int j, int p) {
    // base case
    if (p == word.size()) return true;

    // boundary + mismatch check
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[p])
        return false;

    // mark visited
    char temp = board[i][j];
    board[i][j] = '#';

    // OR (||) → if ANY direction returns true
    bool found =
        solve(i, j + 1, p + 1) ||  // Right
        solve(i + 1, j, p + 1) ||  // Down
        solve(i, j - 1, p + 1) ||  // Left
        solve(i - 1, j, p + 1);    // Up

    // backtrack
    board[i][j] = temp;

    return found;
}

int main() {
    bool ans = false;

    for (int i = 0; i < m && !ans; i++) {
        for (int j = 0; j < n && !ans; j++) {
            ans = solve(i, j, 0);
        }
    }

    cout << (ans ? "TRUE" : "FALSE") << endl;
}
