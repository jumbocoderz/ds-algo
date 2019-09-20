/// https://leetcode.com/problems/dungeon-game/

int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        int dp[n][m];
        if(dungeon[n-1][m-1]>0)
            dp[n-1][m-1]=1;
        else dp[n-1][m-1]=abs(dungeon[n-1][m-1])+1;
         for(int i=n-2;i>=0;--i)
             if(dp[i+1][m-1]-dungeon[i][m-1]>0)
            dp[i][m-1]=dp[i+1][m-1]-dungeon[i][m-1];
            else dp[i][m-1]=1;
        for(int j=m-2;j>=0;--j)
            if(dp[n-1][j+1]-dungeon[n-1][j]>0)
            dp[n-1][j]=dp[n-1][j+1]-dungeon[n-1][j];
            else dp[n-1][j]=1;
        for(int i=n-2;i>=0;--i)
        {
            for(int j=m-2;j>=0;--j)
            {   
               int miny=min(dp[i+1][j]-dungeon[i][j],dp[i][j+1]-dungeon[i][j]);
                if(miny>0) dp[i][j]=miny;
                else dp[i][j]=1;
            }
        }
        return dp[0][0];
    }
