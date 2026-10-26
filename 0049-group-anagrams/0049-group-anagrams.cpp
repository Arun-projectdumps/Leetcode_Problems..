class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> gA;
        unordered_map<string, vector<int>> mp;

        if (strs.empty()) {
            return gA;
        }

        for (int x = 0; x < strs.size(); x++) {
            string key = strs[x];
            sort(key.begin(), key.end());

            mp[key].push_back(x);
        }

        for (auto& pair : mp) {
            vector<string> group;

            for (int j = 0; j < pair.second.size(); j++) {
                group.push_back(strs[pair.second[j]]);
            }

            gA.push_back(group);
        }

        return gA;
    }
};