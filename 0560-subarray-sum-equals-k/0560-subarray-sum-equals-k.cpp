class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for (int x : nums) {
            prefixSum += x;

            // prefixSum - previousPrefix = k
            if (freq.count(prefixSum - k))
                ans += freq[prefixSum - k];

            freq[prefixSum]++;
        }

        return ans;
    }
};