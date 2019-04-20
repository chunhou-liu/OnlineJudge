import java.util.Arrays;

class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length==0)return 0;
        int[] dp1 = new int[nums.length], 
              dp2 = new int[nums.length];
        Arrays.fill(dp1, 1);
        Arrays.fill(dp2, 1);
        int ans = 1;
        for(int i=1;i<nums.length;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp1[i] = Math.max(dp2[j]+1, dp1[i]);
                }else if(nums[i]<nums[j]){
                    dp2[i] = Math.max(dp1[j]+1, dp2[i]);
                }
                ans = Math.max(ans, dp1[i]);
                ans = Math.max(ans, dp2[i]);
            }
        }
        return ans;
    }
}