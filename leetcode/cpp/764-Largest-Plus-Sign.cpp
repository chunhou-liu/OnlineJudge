#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> nums(N, vector<int>(N, 1));
        for(auto &vec : mines){
            nums[vec[0]][vec[1]]=0;
        }
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        vector<int> cur(N, 0);
        //left
        for(int i=0;i<N;++i){
            cur[i]=nums[i][0];
            dp[i][0]=min(dp[i][0], cur[i]);
        }
        for(int j=1;j<N;++j){
            for(int i=0;i<N;++i){
                if(nums[i][j]==1)cur[i]+=1;
                else cur[i]=0;
                dp[i][j]=min(dp[i][j], cur[i]);
            }
        }
        // right
        for(int i=0;i<N;++i){
            cur[i]=nums[i][N-1];
            dp[i][N-1]=min(dp[i][N-1], cur[i]);
        }
        for(int j=N-2;j>=0;--j){
            for(int i=0;i<N;++i){
                if(nums[i][j]==1)cur[i]+=1;
                else cur[i]=0;
                dp[i][j]=min(dp[i][j], cur[i]);
            }
        }
        // top
        for(int i=0;i<N;++i){
            cur[i]=nums[0][i];
            dp[0][i]=min(dp[0][i], cur[i]);
        }
        for(int i=1;i<N;++i){
            for(int j=0;j<N;++j){
                if(nums[i][j]==1)cur[j]+=1;
                else cur[j]=0;
                dp[i][j]=min(dp[i][j], cur[j]);
            }
        }
        // bottom
        for(int i=0;i<N;++i){
            cur[i]=nums[N-1][i];
            dp[N-1][i]=min(dp[N-1][i], cur[i]);
        }
        for(int i=N-2;i>=0;--i){
            for(int j=0;j<N;++j){
                if(nums[i][j]==1)cur[j]+=1;
                else cur[j]=0;
                dp[i][j]=min(dp[i][j], cur[j]);
            }
        }
        // ans
        int ans = 0;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(nums[i][j]==1)ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};