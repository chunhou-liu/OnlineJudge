// class Solution {
// public:
//     vector<int> shortestToChar(string S, char C) {
//     	int n=S.size();
//     	vector<int> ans(n, INT_MAX);
//         set<int> cpos;
//         for(int i=0;i<n;++i)
//         	if(S[i]==C)cpos.insert(i);
//         for(int i=0;i<n;++i){
//         	for(set<int>::iterator j=cpos.begin();j!=cpos.end();++j){
//         		ans[i]=min(ans[i], abs(*j-i));
//         	}
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
    	int n=S.size();
    	vector<int> ans(n, INT_MAX);
    	int epos=-1;
    	for(epos=0;epos<n && S[epos]!=C;++epos);
    	for(int i=epos;i<n;++i){
    		if(S[i]==C){
    			ans[i]=0;epos=i;
    		}
    		ans[i]=i-epos;
    	}
    	for(epos=n-1;epos>=0 && S[epos]!=C;--epos);
    	for(int i=epos;i>=0;--i){
    		if(S[i]==C){epos=i;continue;}
    		ans[i]=min(ans[i], epos-i);
    	}
    	return ans;
    }
};