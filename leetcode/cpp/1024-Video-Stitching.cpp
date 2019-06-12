#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), cmp);
        vector<int> dp(clips.size(), INT_MAX);
        for(int i=0; i<dp.size(); ++i){
            if(clips[i][0]==0)dp[i]=1;
            else{
                for(int j=0; j<i; ++j){
                    if(dp[j]!=-1 && clips[i][0]<=clips[j][1] && dp[j]+1<=dp[i]){
                        dp[i] = dp[j]+1;
                    }
                }   
                if(dp[i]==INT_MAX)dp[i]=-1;
            }
        }
        int cur = INT_MAX;
        for(int i=0; i<dp.size(); ++i){
            if(clips[i][1]>=T && dp[i]!=-1 && dp[i]<cur)cur=dp[i];
        }
        return cur==INT_MAX?-1:cur;
    }
    static bool cmp(vector<int>& a, vector<int> &b){
        return (a[1] < b[1]) || (a[1]==b[1] && a[0]<b[0]);
    }
};