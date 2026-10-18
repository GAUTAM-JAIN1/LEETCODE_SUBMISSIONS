
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0, j = 0;
        while (i >= 0 && i < m && j >= 0 && j < n) {
            if(grid[i][j]=='X') break;
            char ch = grid[i][j];
            grid[i][j] = 'X';
            if (ch == 'R') j++;
            else if (ch == 'L') j--;
            else if (ch == 'U') i--;
            else i++;

            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'X') {
                if (ch == 'R') j--;
                else if (ch == 'L') j++;
                else if (ch == 'U') i++;
                else i--;
                break;
            }
        }
        return {i, j};
    }
};
