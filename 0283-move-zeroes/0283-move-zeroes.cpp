class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0 ;
        int right = 1;
        while (right < nums.size() && left < nums.size()){
            if(nums[left] == 0 && nums[right] != 0){
                swap(nums[left],nums[right]);
                left++;
                right++;
            }
            else if (nums[left] == 0 && nums[right] == 0){
                right++;
            }
            else if (nums[left] != 0 && nums[right] == 0){
                left++;
                right++;
            }
            else if (nums[left] != 0 && nums[right] != 0){
                left++;
                right++;
            }
        }

    }   
};