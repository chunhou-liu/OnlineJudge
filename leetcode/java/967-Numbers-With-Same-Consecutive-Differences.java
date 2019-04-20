class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        if(N==1)return new int[]{0,1,2,3,4,5,6,7,8,9};
        if(K==0){
            int[] arr = new int[9];
            for(int i=1;i<10;++i){
                for(int j=0;j<N;++j)arr[i-1]=arr[i-1]*10+i;
            }
            return arr;
        }
        List<Integer> ans = new ArrayList<>();
        for(int i=1;i<10;++i)fill(N-1, K, i, ans);
        if(N==1)ans.add(0);
        return ans.stream().mapToInt(i->i).toArray();
    }
    private void fill(int N, int K, int cur, List<Integer> ans){
        if(N==0){
            ans.add(cur);
            return;
        }
        int lowest = cur % 10;
        if(lowest+K<10){
            fill(N-1, K, cur*10+lowest+K, ans);
        }
        if(lowest-K>=0)fill(N-1, K, cur*10+lowest-K, ans);
    }
}