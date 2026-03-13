#include<bits/stdc++.h>
using namespace std;
void maps1(){
    map<int, int> mpp;
    mpp[1]=2; // {(1:2)}
    mpp.insert({3,6});  // {(1:2),(3:6)}
    mpp.insert({2,1});   // {(1:2),(2:1),(3:6)}
    // map<pair<int,int>,int> mp; or map<int,pair<int,int>
    // stores <key,value> pairs
    // stores unique keys in sorted order

    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main(){
    maps1();
}