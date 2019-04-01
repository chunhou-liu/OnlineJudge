class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return true;
        int low=0, high=min(num, 46340), mid, sq;
        while(low<=high){
            mid=(low+high)/2;sq=mid*mid;
            if(sq==num)return true;
            if(sq>num)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};