class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int real = nums.size() * (nums.size() + 1) / 2;
        return (real - accumulate(nums.begin(),nums.end(),0));
    }
};