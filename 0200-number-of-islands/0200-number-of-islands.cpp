class Solution { // TC : O(n*m) , SC: O(n*m)
public:
    void dfsHelper(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        // base case
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            vis[i][j] || grid[i][j] != '1') {
            return;
        }

        vis[i][j] = true;

        dfsHelper(i - 1, j, vis, grid); // top
        dfsHelper(i, j + 1, vis, grid); // right
        dfsHelper(i + 1, j, vis, grid); // bottom
        dfsHelper(i, j - 1, vis, grid); // left
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && vis[i][j] == false ){
                    islands++;
                    dfsHelper(i, j, vis, grid);  
                }
                
            }
        }
        return islands;
    }
};