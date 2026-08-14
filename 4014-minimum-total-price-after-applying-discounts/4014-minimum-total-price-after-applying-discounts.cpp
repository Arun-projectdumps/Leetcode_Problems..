class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double ans = 0;
        int temp = discounts.size() - 1;

        for (int i = prices.size() - 1; i >= 0; i--) {
            if (temp >= 0) {
                ans += prices[i] - (prices[i] * discounts[temp] / 100.0);
                temp--;
            } else {
                ans += prices[i];
            }
        }

        return ans;
    }
};