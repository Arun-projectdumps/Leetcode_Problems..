class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int key : nums){
            if(us.find(key) != us.end()){
                return true;
            }
            us.insert(key);
        }
        return false;
    }
};