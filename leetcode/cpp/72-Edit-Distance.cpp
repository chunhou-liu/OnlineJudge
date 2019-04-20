#include <string>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        int* dp = new int[n+1], *prev = new int[n+1];
        for(int i=0;i<=n;++i)dp[i]=prev[i]=i;
        for(int i=1;i<=m;++i){
            dp[0] = i;
            for(int j=1;j<=n;++j){
                if(word1[i-1]==word2[j-1])dp[j]=prev[j-1];
                else dp[j] = min(dp[j-1], min(prev[j], prev[j-1]))+1;
            }
            swap(dp, prev);
        }
        int ans = prev[n];
        delete[] dp;
        delete[] prev;
        return ans;
    }
};