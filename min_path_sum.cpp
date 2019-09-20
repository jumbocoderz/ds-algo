//   https://leetcode.com/problems/minimum-path-sum/

int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dp[n][m];
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-2;i>=0;--i)
            dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
        for(int j=m-2;j>=0;--j)
            dp[n-1][j]=grid[n-1][j]+dp[n-1][j+1];
        for(int i=n-2;i>=0;--i)
        {
            for(int j=m-2;j>=0;--j)
            {
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
