class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        vector<vector<string>> ans;
        for( int i=0;i<strs.size();i++){
            string original=strs[i];
            string copy= strs[i];
            sort(copy.begin(),copy.end());
            map[copy].push_back(original);

        }
        for(auto index:map){
            ans.push_back(index.second);

        }
        return ans;
    }
};