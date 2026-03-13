#include<bits/stdc++.h>
using namespace std;
int hashArr[100000];
void hashKey(int n,int arr[],int c, int hashArr[]){
    for(int i=0;i<n;i++) hashArr[arr[i]]+=1;
    int num;
    while(c!=0){
        cin>>num;
        cout<<hashArr[num]<<" ";
        c--;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int c;
    cin>>c;
    hashKey(n,arr, c,hashArr);
}