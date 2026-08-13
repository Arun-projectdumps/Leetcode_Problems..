class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> st(nums.begin(),nums.end());
        int lstreak = 0;
        int streak = 1;
        for(int x : st){
            if(st.find(x-1) == st.end()){
                int current = x;
                streak = 1;
                while(st.find(current+1) != st.end()){
                    current++;
                    streak++;

                }
                lstreak = max(lstreak,streak);
            }
        }
        return lstreak;
    }
};