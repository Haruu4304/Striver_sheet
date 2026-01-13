/*
PS : Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order(ascending order)
or else false.
Example 1
Input : nums = [1, 2, 3, 4, 5]
Output : true
Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.
*/

#include<bits/stdc++.h>
using namespace std;

//alises
using v = vector<int>;

//global declaration -
v arr = {1,1 , 1 , 2 , 3 , 2};
int n = arr.size();
bool ans = false;

void isSorted(int n){
    //to traverse full loop
    for(int i=0; i<n; i++){
        //to check ascending order i <= i+1
        if(arr[i] <= arr[i+1]) {
            ans = true;
        }
    }
    ans = false;
}

int main(){
    isSorted(n);

    cout << "Is the array is sorted ??? " << ans << " ";
}