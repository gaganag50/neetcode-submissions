class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        int i = 0;
        for(auto it: strs) {
            sort(it.begin(), it.end());
            mp[it].push_back(strs[i]);
            i++;
        }
        vector<vector<string>> answer;
        for(auto it: mp) {
            answer.push_back(it.second);
        }
        return answer;
    }
};
