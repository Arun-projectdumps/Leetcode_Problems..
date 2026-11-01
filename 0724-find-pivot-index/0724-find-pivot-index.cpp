class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre (nums.size());
        vector<int> post (nums.size());
        pre[0] = nums[0];
        post[nums.size()-1] = nums[nums.size()-1];
        for(int i = 1 ; i < nums.size() ; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        for(int i = nums.size()-2; i >= 0 ; i--){
            post[i] = post[i+1]+nums[i];
        }   
        int i = 0;
        int j = nums.size()-1;
        for(int i = 0 ; i < nums.size(); i++){
            int rightsum = 0;
            int leftsum = 0;
            if(i > 0){
                leftsum = pre[i-1];

            }
            if(i < nums.size()-1){
                rightsum = post[i+1];
            }
            if(leftsum == rightsum){
                return i;
            }
        }
        return -1;
    }
};