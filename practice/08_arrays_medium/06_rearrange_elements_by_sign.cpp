#include<bits/stdc++.h>
using namespace std;

void rearrengeElements(vector<int> &nums, int n){
    // Brute force
    // TC: O(2*n+n/2)
    // SC: O(n)
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    for(int i=0;i<pos.size();i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }
    return;
}

vector<int> rearrengeElements2(vector<int> nums, int n){
    // Optimal approch
    // TC: O(n)
    // SC: O(n)
    vector<int> ans(n);
    int pos=0;
    int neg=1;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            ans[pos]=nums[i];
            pos+=2;
        }
        else{
            ans[neg]=nums[i];
            neg+=2;
        }
    }
    return ans;
}

void rearrengeElements3(vector<int> &nums, int n){
    // if the Positives!=Negetives also handle even both are equal
    // O(2*n)
    // O(n)
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    int P=pos.size();;
    int N=neg.size();
    if(P>N){
        for(int i=0;i<N;i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }

        int j=2*N;
        for(int i=N;i<P;i++){
            nums[j]=pos[i];
            j++;
        }
    }

    else{
        for(int i=0;i<P;i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }

        int j=2*P;
        for(int i=P;i<N;i++){
            nums[j]=neg[i];
            j++;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    rearrengeElements3(nums,n);
    
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
}