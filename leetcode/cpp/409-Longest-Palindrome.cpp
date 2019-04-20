#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> dp(256, 0);
        for(int i=0;i<s.size();++i){
            ++dp[s[i]];
        }
        int ans = 0;
        bool flag = false;
        for(int i=0;i<dp.size();++i){
            ans += dp[i]/2*2;
            if(dp[i]%2==1)flag=true;
        }
        return ans+(flag?1:0);
    }
};