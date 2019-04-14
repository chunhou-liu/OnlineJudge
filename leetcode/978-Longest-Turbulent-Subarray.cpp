#include <vector>
using namespace std;


class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()==1)return 1;
        int n=A.size();
        int dp[n], ans=1;
        dp[0]=1;dp[1]=A[0]==A[1]?1:2;
        for(int i=2;i<n;++i){
            if(A[i-1]<A[i] && A[i-1]<A[i-2] || A[i-1]>A[i] && A[i-1]>A[i-2])dp[i]=dp[i-1]+1;
           else dp[i]= A[i]==A[i-1]?1:2;
           ans = max(ans, dp[i]);
       }                
       return ans;
    }
};