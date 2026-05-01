#include<bits/stdc++.h>
using namespace std;

bool checkStrings(string &s1, string &s2){
    if(s1.size()!=1+s2.size()) return false;
    int f=0,s=0;
    while(f<s1.size()){
        if(s<s2.size() && s1[f]==s2[s]){
            f++;
            s++;
        }
        else f++;
    }
    if(f==s1.size() && s==s2.size()) return true;
    return false;
}

bool comp(string &s1, string &s2){
    return (s1.size()<s2.size());
}


int main(){
    int n;
    cin>>n;
    vector<string> strings(n);
    for(int i=0;i<n;i++) cin>>strings[i];

    vector<int> dp(n,1);
    int maxi=1;
    sort(strings.begin(),strings.end(),comp);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(checkStrings(strings[i],strings[j]) && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
            }
        }
        maxi=max(maxi,dp[i]);
    }
    cout<< maxi;
}