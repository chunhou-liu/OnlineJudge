import java.util.Map;
import java.util.HashMap;
import javafx.util.Pair;

class Solution {
    private Map<Pair<Integer, Integer>, Boolean> dp = new HashMap<Pair<Integer, Integer>, Boolean>();
    public boolean canCross(int[] stones) {
        /*
            function(int[] stones, int ind, int k) -> return the next ind jump k units from stones[ind]
        */
        if(stones[1]!=1)return false;
        return canCross(stones, 1, 1);
    }
    private boolean canCross(int[] stones, int ind, int k){
        if(ind==stones.length-1)return true;
        if(k<=0)return false;
        if(stones[ind+1]>stones[ind]+k+1 || stones[stones.length-1]<stones[ind]+k-1)return false;
        Pair<Integer, Integer> p = new Pair<Integer, Integer>(ind, k);
        if(dp.containsKey(p))return dp.get(p);
        // jump k-1 unit
        int next_ind = next(stones, ind, k-1);
        boolean ans = false;
        if(k!=1)if(next_ind<stones.length && stones[next_ind]==stones[ind]+k-1)ans = ans || canCross(stones, next_ind, k-1);
        if(ans){
            dp.put(p, ans);
            return ans;
        }
        // jump k unit
        next_ind = next(stones, ind, k);
        if(next_ind<stones.length && stones[next_ind]==stones[ind]+k)ans = ans || canCross(stones, next_ind, k);
        if(ans){
            dp.put(p, ans);
            return ans;
        }
        // jump k+1 unit
        next_ind = next(stones, ind, k+1);
        if(next_ind<stones.length && stones[next_ind]==stones[ind]+k+1)ans = ans || canCross(stones, next_ind, k+1);
        dp.put(p, ans);
        return ans;
    }
    private int next(int[] stones, int ind, int k){
        if(k==0)return ind;
        int next_ind = ind+1;
        for(;next_ind<stones.length && stones[next_ind]<stones[ind]+k;++next_ind);
        if(next_ind<stones.length && stones[next_ind]==stones[ind]+k)return next_ind;
        return stones.length;
    }
}