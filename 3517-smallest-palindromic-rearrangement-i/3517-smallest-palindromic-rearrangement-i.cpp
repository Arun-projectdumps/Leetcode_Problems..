class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        string ans;
        char middle = '\0';

        // 1. Find odd character
        for (auto [key, count] : freq) {
            if (count % 2 != 0) {
                middle = key;
                break;
            }
        }

        // 2. Build left half
        for (auto [key, count] : freq) {
            int half = count / 2;

            for (int i = 0; i < half; i++) {
                ans += key;
                freq[key]--;
            }
        }

        // 3. Add middle
        if (middle != '\0') {
            ans += middle;
            freq[middle]--;
        }

        // 4. Build right half
        for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
            char key = it->first;
            int count = it->second;

            for (int i = 0; i < count; i++) {
                ans += key;
            }
        }

        return ans;  // ← missing
    }
};