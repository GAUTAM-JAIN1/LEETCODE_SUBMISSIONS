class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || i < 0 || j < 0 || j >= n || grid[i][j] == 1 ||
            visited[i][j] == 1)
            return;
        visited[i][j] = 1;
        dfs(i + 1, j, grid, visited);
        dfs(i - 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
        dfs(i, j + 1, grid, visited);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            dfs(i, 0, grid, visited);
            dfs(i, n - 1, grid, visited);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, grid, visited);
            dfs(m - 1, j, grid, visited);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && visited[i][j] != 1) {
                    ans++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return ans;
    }
};