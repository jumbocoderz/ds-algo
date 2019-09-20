// https://leetcode.com/problems/jump-game-ii/submissions/

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
