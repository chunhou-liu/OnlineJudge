#include <cmath>
using namespace std;


class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N+1];
        dp[0]=dp[1]=false;
        for(int i=2;i<=N;++i){
            dp[i]=false;
            for(int j=1;j<i && !dp[i];++j){
                if(i%j==0)dp[i]=dp[i] || !dp[i-j];
            }
        }
        return dp[N];
    }
};