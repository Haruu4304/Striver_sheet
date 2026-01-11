/**
 * PS: Add Operators to Reach Target
 *
 * Problem:
 *   Given a string of digits and a target value,
 *   insert binary operators (+, -, *) between the digits
 *   so that the resulting expression evaluates to the target.
 *
 * IP:
 *   - string nums   (digits only, no spaces)
 *   - int target
 *
 * OP:
 *   - vector<string> of all valid expressions
 *
 * APPROACH:
 *   - Backtracking (DFS on index of string)
 *   - Start with first digit as initial expression
 *   - At each index, try inserting operators:
 *       +  → add current digit
 *       -  → subtract current digit
 *       *  → multiply current digit
 *   - Evaluate expression in left-to-right order
 *   - If end of string is reached and evaluation == target,
 *     store the expression
 *
 * TC:
 *   - O(3^n)  (three operator choices at each position)
 *
 * SC:
 *   - O(n)  (recursion stack + expression string)
 *
 * LEARNING:
 *   - Operator insertion using recursion
 *   - Expression building with backtracking
 *   - Difference between evaluation logic and expression generation
 *   - Importance of base condition in DFS
 */

#include <bits/stdc++.h>
using namespace std;

//global declaration - 
vector<string> ans;
string nums = "0232";
int target = 8;

void solve(int idx, string expr, int currVal, int prevVal) {
    // base case
    if (idx == nums.size()) {
        if (currVal == target) {
            ans.push_back(expr);
        }
        return;
    }

    int num = nums[idx] - '0';

    // Addition
    solve(idx + 1,
          expr + "+" + nums[idx],
          currVal + num,
          num);

    // Subtraction
    solve(idx + 1,
          expr + "-" + nums[idx],
          currVal - num,
          -num);

    // Multiplication
    solve(idx + 1,
          expr + "*" + nums[idx],
          currVal - prevVal + prevVal * num,
          prevVal * num);
}

int main() {
    // start with first digit
    solve(1, string(1, nums[0]), nums[0] - '0', nums[0] - '0');

    for (auto &s : ans) {
        cout << s << endl;
    }
}
