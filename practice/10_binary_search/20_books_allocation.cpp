/*  
    given an n sized array books where books[i] is the no.of pages in iTh book and m students
    allocate the n books to m students such that max pages alloacated to a single student is minimum
    each student should get atleast 1 book

    Input:
    n=5 m=4
    books=[25 46 28 49 24]

    Output:
    71
    
    Best way to achive min is:
    student1=25+46>71
    student2=28
    student3=48
    student4=24

*/

#include<bits/stdc++.h>
using namespace std;

pair<int,int> maxAndSum(vector<int> books, int n){
    int maxi=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,books[i]);
        sum+=books[i];
    }
    return {maxi,sum};
}

int noOfStudents(vector<int> books, int n,int maxi){
    int students=1, last=0;
    for(int i=0;i<n;i++){
        if(last+books[i]<=maxi) last+=books[i];
        else{
            students++;
            last=books[i];
        }
    }
    return students;
}

int minPagesAllocated(vector<int> books, int n, int m){
    pair<int,int> maxSum= maxAndSum(books,n);
    int low=maxSum.first, high=maxSum.second;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(noOfStudents(books,n,mid)>m) low=mid+1;
        else high=mid-1;
    }
    return low;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> books(n);
    for(int i=0;i<n;i++) cin>>books[i];
    cout<<minPagesAllocated(books,n,m);
}