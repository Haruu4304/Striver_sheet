/*
nQueens Problem using backtracking - 
IP = int n(no of queens)
OP = all possible approaches
TC = n!
SC = n
*/

#include<bits/stdc++.h>
using namespace std;

// Aliases 
using v = vector<int>;
using vv = vector<v>;

// Global variables 
int n = 4;
vv ans;
v x(n + 1, 0);

//bounding condition code - 
bool valid(int k , int l){
    //we have to check 1 - k-1 queen places to check bounding
    for(int i=0; i<k; i++){
        if(x[i] == l || (i - x[i]) == (k - l) || (i + x[i]) == (k + l)){
            return false;
        }
    }
    return true;
}

void nQueen(int k){

    for(int i=1; i<=n; i++){
        //first it will check wheather any bounding condition 0
        if(valid(k , i)){
            //if it is valid then push in x array -
            x[k] = i;

            //if the queeen is last like 4 then no need to further call
            if(k == n){
                ans.push_back(x);
                return;
            }
            nQueen(k + 1);
        }
    } 
    
}

int main(){
    nQueen(1);
    // Display all solns 
    for(auto i: ans) {
        cout << "[";
        for(auto j: i) {
            cout << j << " ";
        }
        cout << "]," << endl;
    }
    return 0;
}