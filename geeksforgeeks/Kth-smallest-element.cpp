#include <cstdio>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

// TLE
int quickSelect(int nums[], int start, int end, int k){
    int ppos = start + rand() % (end-start+1);
    swap(nums[start], nums[ppos]);
    int pivot=nums[start], low=start, high=end;
    while(low<high){
        while(low<high && nums[high]>=pivot)--high;
        nums[low]=nums[high];
        while(low<high && nums[low]<=pivot)++low;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    if(low-start+1==k)return pivot;
    else if(low-start+1<k)return quickSelect(nums, low+1, end, k-low+start-1);
    return quickSelect(nums, start, low-1, k);
}


int main(){
    int T;scanf("%d", &T);
    int nums[100000];
    for(int t=0;t<T;++t){
        int N;scanf("%d", &N);
        for(int i=0;i<N;++i)scanf("%d", &nums[i]);
        int K;scanf("%d", &K);
        printf("%d\n", quickSelect(nums, 0, N-1, K));
    }
}