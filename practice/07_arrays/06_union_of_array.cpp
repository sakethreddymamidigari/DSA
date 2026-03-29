// printing the union of two sorted arrays
#include<bits/stdc++.h>
using namespace std;
void unionOfArrays1(vector<int> arr1, vector<int> arr2,vector<int> &res, int n1,int n2){
    // Brute force approach using set data structure to avoid duplicates
    // TC: O(n1logn1 + n2logn2) + O(n1+n2)
    // O(2*(n1+n2))
    set<int> st;
    for(int i=0;i<n1;i++) st.insert(arr1[i]);   // O(n1logn1)
    for(int i=0;i<n2;i++) st.insert(arr2[i]);   // O(n2logn2)
    for(auto it:st) res.push_back(it);          // O(n1+n2)

}

void unionOfArrays2(vector<int> arr1, vector<int> arr2,vector<int> &res, int n1,int n2){
    // optimal solution using two pointer approach without any extra space
    // TC:O(n1+n2)
    // SC:O(n1+n2)
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(res.size()==0 || res.back()!=arr1[i]) res.push_back(arr1[i]);
            i++;
        }
        else{
            if(res.size()==0 || res.back()!=arr2[j]) res.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        if(res.back()!=arr1[i]) res.push_back(arr1[i]);
        i++;
    }
    while(j<n2){
        if(res.back()!=arr2[j]) res.push_back(arr2[j]);
        j++;
    }

}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> arr1(n1);
    for(int i=0;i<n1;i++) cin>>arr1[i];
    vector<int> arr2(n2);
    for(int i=0;i<n2;i++) cin>>arr2[i];
    vector<int> res;
    unionOfArrays2(arr1,arr2,res,n1,n2);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";

}