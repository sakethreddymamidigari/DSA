#include<bits/stdc++.h>
using namespace std;
void stack1(){
    // TC =O(1)
    stack<int> st;
    st.push(1);  // {1}
    st.push(2);  // {2,1}
    st.push(3);  // {3,2,1}
    st.push(4);  // {4,3,2,1}
    st.push(5);  // {5,4,3,2,1}
    st.emplace(6); // {6,5,4,3,2,1}
    cout<<st.top()<<endl; //prints 6
    st.pop(); // {5,4,3,2,1}
    cout<<st.size();
}
int main(){
    stack1();
}