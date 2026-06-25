#include<iostream>
#include<vector>
#include <queue>
#include <climits>
using namespace std;
//dp memoization
int stairs(int n,vector<int> &dp){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    dp[n]=stairs(n-2,dp)+stairs(n-1,dp);
    return dp[n];
}
int main(){
    int n=4;
    vector<int> dp(n+1,-1);
    cout<<stairs(n,dp);
}