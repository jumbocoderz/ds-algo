// https://leetcode.com/problems/jump-game-ii/submissions/

/**********  Greedy Approach in O(n) ****************/
int jump(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n-1;)
        {   int maxy=i+nums[i],ind;
            if(maxy>=n-1)
            {
                ++ans;
                break;
            }
            for(int j=i+1;j<=i+nums[i] && j<n;++j)
            {  
                if(maxy<j+nums[j])
                {
                    maxy=j+nums[j];
                    ind=j;
                }
            }
            i=ind;
            ++ans;
        }
        return ans;
 }


/**********  DP Approach in O(n^2) , it is used to print all the paths to reach the end of array ***************/
int jump(vector<int>& nums){
        int n=nums.size();
        int dp[n+1];
        dp[n-1]=0;
        for(int i=n-2;i>=0;--i)
        {   int miny=INT_MAX;
            for(int j=i+1;j<=i+nums[i] && j<n ;++j)
                miny=min(miny,dp[j]);
            if(miny!=INT_MAX)
            dp[i]=1+miny;
            else dp[i]=miny;
        }
        return dp[0];
}
