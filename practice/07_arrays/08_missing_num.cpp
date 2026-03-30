#include<bits/stdc++.h>
using namespace std;
int missingNum1(vector<int> arr, int n){
    // Brute force
    // TC: O(n^2)
    // SC: O(1)
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if (flag==0)  return i;
    }
    return -1;
}

int missingNum2(vector<int> arr, int n){
    // Better solution using frequency array
    // TC: O(2n)
    // SC: O(n)
    vector<int> freq(n+1,0);
    for(int i=0;i<n-1;i++) freq[arr[i]]=1;
    for(int i=1;i<=n;i++){
        if(freq[i]==0) return i;
    }
    return -1;
}

int missingNum3(vector<int> arr, int n){
    // Optimal solution calculating total
    // inefficient when n is very higher
    // TC: O(n)
    // SC: O(1)
    int sum1=n*(n+1)/2;
    int sum2=0;
    for(int i=0;i<n-1;i++){
        sum2+=arr[i];
    }
    return sum1-sum2;
}

int missingNum4(vector<int> arr, int n){
    // Optimal solution using XOR
    // TC: O(n)
    // SC: O(1)
    int XOR1=0,XOR2=0;
    for(int i=1;i<=n;i++) XOR1^=i;
    for(int i=0;i<n-1;i++) XOR2^=arr[i];
    return XOR1^XOR2;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n-1);
    for(int i=0;i<n-1;i++) cin>>arr[i];
    cout<<missingNum4(arr,n);

}