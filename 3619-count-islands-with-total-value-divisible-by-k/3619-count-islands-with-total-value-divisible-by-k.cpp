class Solution {
public:
    void dfs(int i, int j, int k, vector<vector<int>>& grid,
             vector<vector<int>>& visited, long long& sum) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == 1 ||
            grid[i][j] == 0)
            return;
        visited[i][j] = 1;
        sum += grid[i][j];
        dfs(i - 1, j, k, grid, visited, sum);
        dfs(i + 1, j, k, grid, visited, sum);
        dfs(i, j - 1, k, grid, visited, sum);
        dfs(i, j + 1, k, grid, visited, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && visited[i][j] == 0) {
                    long long sum = 0;
                    dfs(i, j, k, grid, visited, sum);
                    if (sum % k == 0)
                        ans += 1;
                }
            }
        }
        return ans;
    }
};