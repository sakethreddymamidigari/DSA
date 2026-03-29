#include<bits/stdc++.h>
using namespace std;
void movingZeros1(vector<int> &arr,int n){
    // Brute force approach
    // TC: O(n+k+n-k) ==> O(2*n)
    // SC: O(k)
    vector<int> temp;
    for(int i=0;i<n;i++){                             // O(n)
        if(arr[i]!=0) temp.push_back(arr[i]);
    }
    for(int i=0;i<temp.size();i++) arr[i]=temp[i];    //O(k) k=no.of non-zero nums
    for(int i=temp.size();i<n;i++) arr[i]=0;          //O(n-k)
}

void movingZeros2(vector<int> &arr,int n){
    // Optimal solution using two pointer approach
    // TC: O(n)
    // SC: O(1)
    int i=-1;
    for(int j=0;j<n;j++){            //O(k) k=index of first zero
        if(arr[j]==0){
            i=j;
            break;
        }
    }
    if(i!=-1){
        for(int j=i+1;j<n;j++){     //O(n-k)
            if(arr[j]!=0){
                swap(arr[i],arr[j]);
                i++;
            }
        }
    }
}
int main(){
    int n,d;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    movingZeros2(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}