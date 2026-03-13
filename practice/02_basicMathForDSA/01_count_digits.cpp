#include<bits/stdc++.h>
using namespace std;
// bruteforce
void countDigits1(int n){
    // printing the number of digits 
    //present in the given number
    int count=0;
    // runs for log10(n) times
    while (n>0){
        n=n/10;
        count++;

    }
    cout<<count;
}
// edge case approach
// runs for 1 time
void countDigits2(int n){
    int count=int(log10(n))+1;
     //value of log10(n)=no.of digits in n-(0.something)
     //ie the no.of digits in n =int(log10(n))+1
    cout<<count;
}
int main(){
    int n;
    cin>>n;
    countDigits2(n);
}
