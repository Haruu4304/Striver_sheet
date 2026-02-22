/*
PS :  You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
*/

#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack <int> st;
    int n = tokens.size();

    for(int i=0; i<n; i++){
        
        //check for any operations
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
            int b = st.top(); //our top will be second operand
            st.pop();
            int a = st.top();
            st.pop();

            if(tokens[i] == "+") st.push(a + b);
            else if(tokens[i] == "-") st.push(a-b);
            else if(tokens[i] == "*") st.push(a*b);
            else st.push(a/b);
        }else{
            // If number
            st.push(stoi(tokens[i])); //string to interger
        }
    }
    return st.top();
}

int main(){
    vector<string> tokens = {"2","1","+","3","*"};
    int result = evalRPN(tokens);

    cout << "Result : " << result;
}