/*
PS : check whether the string2 is present in string 1
IP : string
OP : bool
*/

#include<bits/stdc++.h>
using namespace std;

//global declaration
string s1 = "abcd";
string s2 = "dcab";

bool isRotation(string s1 , string s2){
    //step 1 : first check the size whether they are equal
    if(s1.size() != s2.size()){
        return false;
    }

    //step 2 : 
    string temp = s1 + s1; //now it have temp = abcdabcd

    //step 3 : 
    return (temp.find(s2) != string::npos); //if find then it will return index else npos

}

int main(){
    if(isRotation(s1 , s2)){
        cout << "TRUE" ;
    }else{
        cout << "FALSE";
    }
}