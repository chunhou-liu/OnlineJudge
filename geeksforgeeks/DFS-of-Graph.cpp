void dfs(int k, vector<int> nums[], bool visited[])
{
    
    visited[k]=true;
    cout << k << ' ';
    for(int i=0;i<nums[k].size();++i){
        if(!visited[nums[k][i]])dfs(nums[k][i], nums, visited);
    }
}