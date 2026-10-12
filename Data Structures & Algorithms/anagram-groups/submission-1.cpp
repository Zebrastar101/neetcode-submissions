class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> results;
        unordered_map<string,vector<string>> hash;
        for( string s: strs){
            vector<int> count (26,0);
            for(char c: s){
                count[c-'a']+=1;
            }
            string key;
            for(int i=0; i<count.size(); i++){
                key+=to_string(count[i])+',';
            }
            hash[key].push_back(s);
        }
        for(auto x: hash){
            results.push_back(x.second);
        }



        return results;
    }
};
