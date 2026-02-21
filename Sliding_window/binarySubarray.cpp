/*
PS : Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.
*/
#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal){
    int count = 0 , sum = 0;
    int i =0, j=0;

    //base condition
    while(j < nums.size()){
        //basic calculation
        sum = sum + nums[j];

        if(sum == goal){
            count++;
        }
        //shrink the window
        else if(sum > goal){
            while(sum > goal){
                sum = sum - nums[i];
                i++;
            }
        }
        j++;
    }
    return count;
}

int main(){
    vector<int> nums = {1,1,0,1,0,0,1};
    int goal = 3;
    int result = numSubarraysWithSum(nums , goal);

    cout << "Result : " << result;
}