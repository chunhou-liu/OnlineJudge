class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> dp(A);
        for(int i=1;i<A.size();++i)dp[i]+=dp[i-1];
        int sum = 0;
        for(auto i : A)sum+=i;
        for(int i=0;i<A.size();++i){
            if(sum==3*dp[i]){
                for(int j=i+1;j<A.size();++j)
                    if(dp[j]==2*(sum-dp[j]))return true;
            }
        }
        return false;
    }
};