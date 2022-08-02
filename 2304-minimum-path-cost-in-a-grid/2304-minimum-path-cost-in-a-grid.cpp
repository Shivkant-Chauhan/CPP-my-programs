class Solution {
public:
    int dp[50][50];
    int helper(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int m, int n, int r, int c){
        if(r == m){
            return grid[r-1][c];
        }
        
        if(dp[r][c] != -1)  return dp[r][c];
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int x = grid[r-1][c]+moveCost[grid[r-1][c]][i]+helper(grid, moveCost, m, n, r+1, i);
            ans = min(ans, x);
        }
        
        return dp[r][c] = ans;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++){
            int x = helper(grid, moveCost, m, n, 1, i);
            ans = min(ans, x);
        }
        
        return ans;
    }
    
    
};