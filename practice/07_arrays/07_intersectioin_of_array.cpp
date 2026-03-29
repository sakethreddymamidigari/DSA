// printing the intersection to sorted arrays
#include<bits/stdc++.h>
using namespace std;
void intersectionOfArrays1(vector<int> arr1, vector<int> arr2,vector<int> &res, int n1,int n2){
    // Brute force approach
    // TC:O(n1*n2)
    // SC:O(n2)
    vector<int> vs(n2,0);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j] && vs[j] == 0){
                res.push_back(arr2[j]);
                vs[j]=1;
                break;
            }
            if(arr2[j]>arr1[i]) break;
        }
    }

}

void intersectionOfArrays2(vector<int> arr1, vector<int> arr2,vector<int> &res, int n1,int n2){
    // Optimal solution
    // TC: O(n1+n2)
    // SC: O(1)
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]) i++;
        else if(arr1[i]>arr2[j]) j++;
        else{
            res.push_back(arr1[i]);
            i++;
            j++;
        }
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
    intersectionOfArrays2(arr1,arr2,res,n1,n2);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";

}