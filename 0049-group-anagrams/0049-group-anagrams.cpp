class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*this question was solved using hashmaps (key,value) 
        here we can use the sorted string, the sorted string of all anagram groups will be the same they can be used as a key and the value can have the data type vector<string> to store the actual groups  */
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(string i : strs){
            string ssorted = i;
            sort(ssorted.begin(),ssorted.end());
            mp[ssorted].push_back(i);
        }
        for(auto &x : mp){
            ans.push_back(move(x.second));
        }
        return ans;
      }
};