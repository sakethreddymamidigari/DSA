#include<bits/stdc++.h>
using namespace std;

void print1(int i, int n){
    // printing the name for n time
    // O(n)
    if(i>n) return;
    cout<<"Saketh"<<endl;
    print1(i+1,n); //function call
    }

void print2(int i, int n){
    // printing 1 to n 
    // O(n)
    if(i>n) return;
    cout<<i<<endl;
    print2(i+1,n); //function call
}

void print3(int i, int n){  //i=n
    // printing n to 1
    // O(n)
    if(i<1) return;
    cout<<i<<endl;
    print3(i-1,n); //function call
}

void backTrack1(int i, int n){ //i=n
    // printing 1 to n i using backtracking
    // O(n)
    if(i<1) return; //i=n to 1
    backTrack1(i-1,n); //first calling function
    cout<<i<<endl; // then print
}

void backTrack2(int i, int n){ //i=n
    // printing n to 1 using backtracking
    // O(n)
    if(i>n) return; //i=1 to n
    backTrack2(i+1,n); //first calling function
    cout<<i<<endl; // then print
}

int main(){
    int i=1,n;
    cin>>n;
    backTrack2(i,n);
}