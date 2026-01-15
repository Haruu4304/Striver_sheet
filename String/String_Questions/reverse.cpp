/*
PS : reverse a string without using reverse function
IP : string
OP : string
Analysis : 
TC -> O(n)
SC -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

//global declaration
string s = "hello";
string rev = ""; //to store reverse string

void reverseString(string s){
    //traverse it and strore in another string
    for(int i=s.size()-1; i>=0; i--){
        rev.push_back(s[i]); //O(n)
    }
}

int main(){
    reverseString(s);

    //display the string
    for(auto s : rev){
        cout << s << " ";
    }
}