class Solution {
public:
    long long countWays(vector<int>& freq, int remaining, long long limit) {
        long long ways = 1;
        int used = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= freq[i]; j++) {
                used++;

                // Calculate combinations while avoiding overflow.
                if (ways > limit * j / used) {
                    return limit;
                }

                ways = ways * used / j;

                if (ways >= limit) {
                    return limit;
                }
            }
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        // Count all characters
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find middle character and convert frequencies
        // into frequencies needed for the left half.
        int middle = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = i;
            }

            freq[i] /= 2;
        }

        int halfLength = s.length() / 2;
        string left;

        // Construct kth lexicographically smallest
        // permutation of the left half.
        for (int pos = 0; pos < halfLength; pos++) {

            bool found = false;

            for (int i = 0; i < 26; i++) {

                if (freq[i] == 0) {
                    continue;
                }

                // Try this character at current position.
                freq[i]--;

                long long ways =
                    countWays(freq, halfLength - pos - 1, k);

                if (ways >= k) {
                    left += char('a' + i);
                    found = true;
                    break;
                }

                // kth permutation isn't in this block.
                // Skip the entire block.
                k -= ways;

                // Restore character and try next one.
                freq[i]++;
            }

            // No character could produce the kth permutation.
            if (!found) {
                return "";
            }
        }

        // Build full palindrome.
        string right = left;
        reverse(right.begin(), right.end());

        string ans = left;

        if (middle != -1) {
            ans += char('a' + middle);
        }

        ans += right;

        return ans;
    }
};