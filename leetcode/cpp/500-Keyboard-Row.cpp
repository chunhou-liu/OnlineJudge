class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> ans;
        for(auto &s: words){
        	int prev_row=findCharPos(rows, s[0]);
        	bool flag=true;
        	for(int i=1;i<s.size();++i)
        		if(findCharPos(rows, s[i])!=prev_row){flag=false;break;}
        	if(flag)ans.push_back(s);
        }
        return ans;
    }
    int findCharPos(vector<string> &rows, char c){
    	for(int i=0;i<rows.size();++i){
    		if(rows[i].find(c)!=rows[i].npos)return i;
    	}
    	return -1;
    }
};