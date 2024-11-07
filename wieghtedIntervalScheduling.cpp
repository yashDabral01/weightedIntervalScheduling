#include<bits/stdc++.h>
using namespace std;
class Jobs{
    public:
    int start;
    int end;
    int profit;

    Jobs(int s = 0,int e = 0,int p=0){
        this->start = s;
        this->end = e;
        this->profit = p;
    }
};
bool compareByFinishTime(const Jobs &a, const Jobs &b) {
    return a.end < b.end;
}
class Solution {
public:
    void compartible(vector<Jobs>& jobs,vector<int>&C){
        C[0] = 0;
        int n = jobs.size();
        for(int i = 1;i<n;i++){
            int temp = 0;
            for(int j = 0; j <i ; j++){
                if( jobs[i].start >= jobs[j].end){
                    temp++;
                }
            }
            C[i] = temp;
        }
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Jobs>jobs(n);
        vector<int>dp(n+1);
        for(int i = 0; i<n ;i++){
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        sort(jobs.begin(), jobs.end(), compareByFinishTime);
        vector<int>C(n,0);
        compartible(jobs,C);

        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            dp[i] = max(dp[C[i-1]]+ jobs[i-1].profit,dp[i-1]);
        }
        return dp[n];
    }
};
int main(){
    vector<int>startTime = {1,2,3,3};
    vector<int>endTime = {3,4,5,6};
    vector<int>profit = {50,10,40,70};
    
    return 0;
}