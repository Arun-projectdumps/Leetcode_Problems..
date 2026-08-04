class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = nums[0]; 
        int mn = nums[0];
        vector<int> arr;
        
        for(int i = 0 ;i < nums.size();i++){
            if(nums[i] < mn){
                mn = nums[i];
            }
            if(nums[i] > mx){
                mx = nums[i];
            }
            
        }
        for(int i = mn; i < mx ;i++){
            auto it = find(nums.begin(),nums.end(),i);
            if(it == nums.end()){
                arr.push_back(i);
            }

            
        }
        return arr;
    }
};