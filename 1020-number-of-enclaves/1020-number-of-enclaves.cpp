
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 ||
            visited[i][j] == 1)
            return;

        visited[i][j] = 1;

        dfs(i - 1, j, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
        dfs(i, j + 1, grid, visited);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int j = 0;
        for (int i = 0; i < m; i++) {
            if (grid[i][j] == 1)
                dfs(i, j, grid, visited);
        }

        j = n - 1;
        for (int i = 0; i < m; i++) {
            if (grid[i][j] == 1)
                dfs(i, j, grid, visited);
        }

        int x = 0;
        for (int j = 0; j < n; j++) {
            if (grid[x][j] == 1)
                dfs(x, j, grid, visited);
        }

        x = m - 1;
        for (int j = 0; j < n; j++) {
            if (grid[x][j] == 1)
                dfs(x, j, grid, visited);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
};
