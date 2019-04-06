long long int floorSqrt(long long int x) {
    int low=0, high=x;
    while(low<=high){
        int mid = (low+high)/2;
        if(mid==x/mid)return mid;
        if(mid<x/mid)low=mid+1;
        else high=mid-1;
    }
    return high;
}