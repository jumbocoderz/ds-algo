ll findlcs(string str1,string str2)      
{	    ll n1=str1.length(),n2=str2.length();
	    ll dp[n1+1][n2+1];
	    for(ll i=0;i<=n1;++i)
	        for(ll j=0;j<=n2;++j)
	        {
	            if(i==0 || j==0) dp[i][j]=0;
	            else if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1]+1;
	            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
      return dp[n1][n2];  // dp[n1][n2] hvae the length of longest common sebsequence
}
