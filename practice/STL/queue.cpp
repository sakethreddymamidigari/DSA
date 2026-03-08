#include<bits/stdc++.h>
using namespace std;
void queue1(){
    queue<int> q1;
    q1.push(1); //{1}
    q1.push(2); //{1,2}
    q1.emplace(3); //{1,2,3}
    q1.back()+=5; //{1,2,8}
    cout<<q1.back()<<endl; //8
    cout<<q1.front()<<endl; //1
    q1.pop(); //{2,8}
    cout<<q1.front()<<endl; // 2
}
int main(){
    queue1();
}