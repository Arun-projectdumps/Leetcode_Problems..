class Solution {
public:
    int minimumPushes(string word) {

        // Cost assigned to each character.
        // 0 means the character hasn't been assigned a cost yet.
        int cost[26] = {0};

        int unique = 0;

        // ---------------- First 8 unique characters -> cost = 1 ----------------
        for (int i = 0; i < word.length() && unique < 8; i++) {

            int idx = word[i] - 'a';

            // Assign only if this character has not been assigned yet
            if (cost[idx] == 0) {
                cost[idx] = 1;
                unique++;
            }
        }

        unique = 0;

        // ---------------- Next 8 unique characters -> cost = 2 ----------------
        for (int i = 0; i < word.length() && unique < 8; i++) {

            int idx = word[i] - 'a';

            if (cost[idx] == 0) {
                cost[idx] = 2;
                unique++;
            }
        }

        unique = 0;

        // ---------------- Next 8 unique characters -> cost = 3 ----------------
        for (int i = 0; i < word.length() && unique < 8; i++) {

            int idx = word[i] - 'a';

            if (cost[idx] == 0) {
                cost[idx] = 3;
                unique++;
            }
        }

        unique = 0;

        // ---------------- Remaining characters -> cost = 4 ----------------
        for (int i = 0; i < word.length(); i++) {

            int idx = word[i] - 'a';

            if (cost[idx] == 0) {
                cost[idx] = 4;
            }
        }

        // ---------------- Calculate total pushes ----------------
        int ans = 0;

        for (char ch : word) {
            ans += cost[ch - 'a'];
        }

        return ans;
    }
};