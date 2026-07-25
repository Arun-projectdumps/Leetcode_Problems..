class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sig = 1;
        for(int i = 0 ; i < nums.size();i++)
        {
            
            if(nums[i] == 0)
            {
                return 0;
            }
            if(nums[i] < 0 && sig > 0){
                sig = -1;
            }
            else if(nums[i] > 0 && sig < 0){
                sig = -1;
            }
            else if(nums[i] < 0 && sig < 0 ){
                sig = +1;
            }
            else {
                sig = +1;
            }
        }
        return sig;
    }
};