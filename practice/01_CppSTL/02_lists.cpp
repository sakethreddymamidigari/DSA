#include<bits/stdc++.h>
using namespace std;
void list1(){
    list<int> ls;
    ls.push_back(2); //{2}
    ls.emplace_back(4); //{2,4}
    ls.push_front(5); //{5,2,4}
    // push_front and emplace_front in list is cheaper than insert in vector in terms of TC
     cout<<size(ls);
}
int main(){
    list1();
}