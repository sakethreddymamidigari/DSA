/*
    given two sorted arrays find the median of the array
    TC: O(log(min(n1,n2)))
    SC: O(1)

    Input:
    6 4
    1 3 4 7 10 17
    2 3 6 15

    Output:
    5

    1 2 3 3 4 | 6 10 15 17
    (4+6)/2=>5
*/



#include<bits/stdc++.h>
using namespace std;

double medianOfTwoSortedArrays(vector<int> a, vector<int> b, int n1, int n2){
    if(n1>n2) return medianOfTwoSortedArrays(b,a,n2,n1);
    int low=0,high=n1;
    int left=(n1+n2+1)/2;
    while(low<=high){
        int mid1=(low+high)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;
        if(mid1<n1) r1=a[mid1];
        if(mid2<n2) r2=b[mid2];
        if(mid1>0)  l1=a[mid1-1];
        if(mid2>0)  l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            if((n1+n2)/2==1) return min(r1,r2);
            return ((double)(max(l1,l2)+min(r1,r2))/2.0);
        }
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;

    }
    return -1;
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0;i<n1;i++) cin>>a[i];
    for(int i=0;i<n2;i++) cin>>b[i];
    cout<<medianOfTwoSortedArrays(a,b,n1,n2);
}