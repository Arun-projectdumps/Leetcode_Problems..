class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre;
        pre.push_back(nums[0]);
        vector<int>post (nums.size(),0);
        post[nums.size()-1] = nums[nums.size()-1];
        vector<int>ans (nums.size());
        //finding out all the prefixes 
        for(int x = 1; x < nums.size(); x++){
            pre.push_back(nums[x]*pre[x-1]);
        }
        //finding all the postfixes
        for(int x = nums.size()-2; x >=0 ;x--){
            post[x] = (nums[x]*post[x+1]);
        }
        //settling the edges cases of start and end 
        ans[0] = post[1];
        ans[nums.size()-1] = pre[nums.size()-2];
        //
        for(int i = 1 ; i < nums.size()-1;i++){
            ans[i] = pre[i-1]*post[i+1];
        }
        pre.clear();
        pre.shrink_to_fit();
        post.clear();
        post.shrink_to_fit();
        return ans;
    }
};