class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cp[26] = {0};
        vector<int> ans;
        
        // Count p
        for (int x : p) {
            cp[x - 'a']++;
        }

        int window[26] = {0};
        int m = p.size();

        // Sliding window
        for (int i = 0; i < s.size(); i++) {
            window[s[i] - 'a']++;

            if (i >= m)
                window[s[i - m] - 'a']--;

            if (i >= m - 1) {
                bool same = true;

                for (int j = 0; j < 26; j++) {
                    if (window[j] != cp[j]) {
                        same = false;
                        break;
                    }
                }

                if (same)
                    ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};