class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> domainCountMap;
        for(auto &s:cpdomains){
            int empty_char_pos = s.find(' ');
            int count = stoi(s.substr(0, empty_char_pos));
            string website = s.substr(empty_char_pos+1);
            if(domainCountMap.find(website)==domainCountMap.end())domainCountMap[website]=0;
            domainCountMap[website]+=count;
            for(int i=empty_char_pos;i<s.size();++i){
            	if(s[i]=='.'){
            		string domain=s.substr(i+1);
            		if(domainCountMap.find(domain)==domainCountMap.end())domainCountMap[domain]=0;
            		domainCountMap[domain]+=count;
            	}
            }
        }
        vector<string> ans;
        for(map<string, int>::iterator i=domainCountMap.begin();i!=domainCountMap.end();++i){
        	ans.push_back(to_string(i->second)+" "+i->first);
        }
        return ans;
    }
};