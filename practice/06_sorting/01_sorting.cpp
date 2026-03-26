#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    // O(n^n)
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }

}

void bobbleSort(int arr[], int n){
    //O(n^2)
    for(int i=n-1;i>=1;i--){
        for( int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    // O(n^2)
    for(int i=0;i<=n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
    }
    }
}
void mergeSort(int arr[],int n){

    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    insertionSort(arr, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}