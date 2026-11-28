class Solution {
public:
    int knapsack(vector<pair<int, int>>& final, int budget, int i, int minPrice,
                 vector<vector<int>>& dp) {
        int n = final.size();
        if (i == n)
            return budget / minPrice;

        if (dp[i][budget] != -1)
            return dp[i][budget];

        int pick = 0;
        if (budget >= final[i].first) {
            pick = final[i].second + knapsack(final, budget - final[i].first,
                                              i + 1, minPrice, dp);
        }
        int notpick = knapsack(final, budget, i + 1, minPrice, dp);

        return dp[i][budget] = max(pick, notpick);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(n, 0);
        int minPrice = INT_MAX;

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    copies[i]++;
                }
            }
        }
        vector<pair<int, int>> final;
        for (int i = 0; i < n; i++) {
            final.push_back({items[i][1], 1 + copies[i]});
        }
        vector<vector<int>> dp(n, vector<int>(budget + 1, -1));
        return knapsack(final, budget, 0, minPrice, dp);
    }
};