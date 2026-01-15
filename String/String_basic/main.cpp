/*
lets see some basis of string
*/

#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string  s = "hello";

    //1. append
    s.append(" sir");
    // cout << s << endl;

    //2. push_back() and pop_back()
    s.push_back('a');
    // cout << s << endl;
    s.pop_back();
    // cout << s << endl;

    //3. substr() : this method is used to extract a part of a string and return it as a new string.
    string t = s.substr(2 , 4);
    // cout << t << endl;

    //4. find() -> it will return bool result 1 -> true , 0-> false
    // cout << s.find('e') << endl;

    //5. erase(pos , len) -> function is used to remove characters from a string.
    s.erase(2 , 3);
    // cout << s << endl;

    //6. insert(pos , string) -> 
    s.insert(2 , "harsha");
    // cout << s << endl;

    //7. replace(pos , len , string) -> 
    s.replace(2 , 6 , "tanaji");
    // cout << s << endl;

    //8. clear() -> 
    s.clear();
    // cout << s << endl;

    //9. empty()
    s.empty();

    //10. compare() -> it will return int 0= equal ,(<0) greater than 0 means s1 < s2 and (>0) s1 > s2
    string s1 = "hello";
    string s2 = "harsha";
    // cout << s1.compare(s2) ; // 1-> s1<s2

    //String Conversions -
    //1 String -> integer
    int x = stoi("123");
    cout << x << endl;

    //2. String -> long
    long l = stol("123");
    cout << l << endl;

    //3. String -> double
    double d = stod("123");
    cout << d << endl;

    //to string
    string ss = to_string(123);
    cout << ss << endl;
}   