

#include<bits/stdc++.h>
using namespace std;

int ninjaTraining1(vector<vector<int>> &points,int last,int day,vector<vector<int>> &dp){
    // Memoization
    // TC: O(n*3*3)
    // SC: O(n+n*4)
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(points[0][i],maxi);
            }
        }
        return maxi;
    }
    
    if(dp[day][last]!=-1) return dp[day][last];

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int gain=points[day][i]+ ninjaTraining1(points,i,day-1,dp);
            maxi=max(gain,maxi);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining2(vector<vector<int>> &points,int n,vector<vector<int>> &dp){
    // Tabulation
    // TC: O(n*4*3)
    // SC: O(n*4)
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int gain=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(gain,dp[day][last]);
                }
            }
        }
    }
    return dp[n-1][3];
}

int ninjaTraining3(vector<vector<int>> &points,int n,vector<int> &prev){
    // Space Optimization
    // TC: O(n*4*3)
    // SC: O(4)
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int>(3));
    for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin>>points[i][j];
    // vector<vector<int>> dp(n,vector<int>(4,-1));  // for Memoization and Tabulation
    // cout<<ninjaTraining(points,3,n-1,dp);   // Memoization
    // cout<<ninjaTraining2(points,n,dp);  // Tabulation
    vector<int> prev(4);    // For Space Optimization
    cout<<ninjaTraining3(points,n,prev);
}