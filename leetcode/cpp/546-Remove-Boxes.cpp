#include <vector>
using namespace std;


class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[n][n][n+1];
        // dp[i][j][k]: max score we can get from boxes[i] to boxes[j] with boxes[i] repeat k times on the left
        for(int i=0;i<n;++i){
            for(int k=0;k<=n;++k)
                dp[i][i][k]=k*k;
            for(int j=0; j<i; ++j)
                for(int k=0; k<=n; ++k)
                    dp[i][j][k] = 0;
        }
        for(int i=n-1; i>=0; --i){
            for(int j=i+1; j<n; ++j){
                for(int k=0; k<=i+1; ++k){
                    dp[i][j][k] = k*k + dp[i+1][j][1];
                    for(int p=i+1; p<=j; ++p){
                        if(boxes[p]==boxes[i]){
                            dp[i][j][k] = max(dp[i][j][k], dp[i+1][p-1][1]+dp[p][j][k+1]);
                        }
                    }
                }
            }
        }
        return dp[0][n-1][1];
    }
};