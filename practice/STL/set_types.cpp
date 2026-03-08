#include<bits/stdc++.h>
using namespace std;
void set1(){
    // operations on set
    // a set is always sort and no duplicates
    // takes logarithmic time for all operations on set
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(4); // {1,2,4}
    st.insert(3); // {1,2,3,4}
    st.insert(8); // {1,2,3,4,8}
    
    // begin() end() rbegin() rend() size() empty() erase() and swap()
    // works same as in other cpp container

    // {1,2,3,4,8}
    auto it1=st.find(2);
    auto it2=st.find(4);
    st.erase(it1,it2);
    // erases 2 to 4 (2,3)
    // {1,4,8}
    for (int x:st){
        cout<<x<<" ";
    }
}
void multiSet(){
    // allows duplicates in sorted order
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.emplace(2); // {1,2}
    ms.insert(4); // {1,2,4}
    ms.insert(3); // {1,2,3,4}
    ms.insert(3); // {1,2,3,3,4}
    
    ms.erase(3); //erases all the occurances of 3 (1,2,4)
    for (int x:ms){
        cout<<x<<" ";
    }
}
void unset(){
    unordered_set<int> ust;
    // same as set but unordered unique elements
    // all operation are same as in set
    // except lower_bound() and upper_bound()
    // max operation takes O(1) time to execute
}
int main() {
    multiSet();
}