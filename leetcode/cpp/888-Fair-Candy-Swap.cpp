class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans(2, 0);
        int sum_a = 0, sum_b = 0;
        for(auto i : A)sum_a += i;
        for(auto i : B)sum_b += i;
        for(auto i : A)
            for(auto j : B)
                if(sum_a-sum_b = 2*(i-j)){
                    ans[0]=i;ans[1]=j;
                    return ans;
                }
        return ans;
    }
};