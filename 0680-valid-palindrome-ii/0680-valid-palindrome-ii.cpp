class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return ispal(left + 1, right, s) ||
                       ispal(left, right - 1, s);
            }

            left++;
            right--;
        }

        return true;
    }

    bool ispal(int x, int y, string s) {
        while (x < y) {
            if (s[x] != s[y]) {
                return false;
            }

            x++;
            y--;
        }

        return true;
    }
};