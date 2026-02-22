/*
PS : Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, 
leaving the other elements in the same relative order.

If the size of queue is smaller than the given k , then return the original queue.
*/

#include <bits/stdc++.h>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    if (k > q.size()) return q;

    stack<int> st;
    int n = q.size();

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back to queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining (n-k) elements to back
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    q = reverseFirstK(q, k);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}