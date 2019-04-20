class Solution {
    public int minSwap(int[] A, int[] B) {
        if(A.length==0)return 0;
        int[]   dp1 = new int[A.length],
                dp2 = new int[A.length];
        Arrays.fill(dp1, Integer.MAX_VALUE);
        Arrays.fill(dp2, Integer.MAX_VALUE);
        dp1[0] = 0; dp2[0] = 1;
        for(int i=1;i<A.length;++i){
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                dp1[i]=Math.min(dp1[i], dp1[i-1]); // do not swap previously
                dp2[i]=Math.min(dp2[i], dp2[i-1]+1);
            }
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                dp1[i]=Math.min(dp1[i], dp2[i-1]); // swap previously
                dp2[i]=Math.min(dp2[i], dp1[i-1]+1);
            }
        }
        return Math.min(dp1[A.length-1], dp2[A.length-1]);
    }
}