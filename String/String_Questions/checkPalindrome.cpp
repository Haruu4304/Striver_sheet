/*
PS : Check a given string is palindrome or not
IP : String
OP : boolean

Time complexity -> O(n) 
Space complexity -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    string rev = s; //because reverse function return type is : void
    //step 1 : reverse a string
    reverse(rev.begin() , rev.end()); //O(n)

    //now traverse
    for(int i=0; i<s.size(); i++){
        if(s[i] == rev[i]){ 
            i++;
        }else{
            return false;
        }
    }

    return true;
}

int main(){
    string s = "hello";

    if(checkPalindrome(s)){
        cout << "This String is Palindrome";
    }else{
        cout <<"This String is not Palindrome";
    }
}