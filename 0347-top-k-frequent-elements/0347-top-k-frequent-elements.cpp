class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        map<int,vector<int>> sot;
        vector<int> ans;
        for(auto x : nums){
            freq[x]++;
        }
        for(auto x : freq){
            sot[x.second].push_back(x.first);
        }
        for(auto x = sot.rbegin(); x != sot.rend() ; x++){
            for(int i = 0 ; i < x->second.size(); i++){
                ans.push_back(x->second[i]);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};