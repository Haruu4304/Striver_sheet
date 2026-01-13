/*
PS : Rotate elements towards left

Analysis - 
TC = O(n)
SC = O(1)
*/

#include<bits/stdc++.h>
using namespace std;

//alises
using v = vector<int>;

//global declaration
v arr = {1 , 2 , 3, 4 , 5};
v arr2 = {5 , 6 , 7 ,8 , 9};
int n = arr.size();
int m = arr2.size();

//why & - because we want changes should happen in same array
void rotateToLeftOne(vector<int> &arr){
    //store first element
    int temp = arr[0];

    //then to shift towards left
    for(int i = 1; i<n; i++){
        arr[i-1] = arr[i]; //store in left side
    }

    //at the end push that temp in last
    arr[n-1] = temp;
}

//based on k numbers we have to shift by k
void rotateToLeftk(vector<int> &arr2 , int k){
    int m = arr2.size();
    k = k%n; //to manage large k

   //step 1 : push till k elements in new array
   vector<int> elements;
   for(int i=0; i<k; i++){   //O(k)
    elements.push_back(arr2[i]); //push elements
   }

   //step 2 :  remove elements from arr 2
   arr2.erase(arr2.begin() , arr2.begin() + k); //O()

   //step 3 : now push back again into arr2
   for(int i=0; i<elements.size(); i++){ //O(k)
    arr2.push_back(elements[i]);
   }
}

int main(){
    rotateToLeftOne(arr);

    //to display - 
    for(auto x : arr){
        cout << x << " ";
    }
    cout << endl;

    //what if in input they will give you k numbers to move on left
    rotateToLeftk(arr2 , 3);
    //to display - 
    cout << "Now we are displaying another rotation of "<< endl;
    for(auto x : arr2){
        cout << x << " ";
    }
}