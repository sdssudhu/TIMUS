#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,k,i,j,l;
    cin>>n>>k;
    int dp[n+1][k+1];
    
    int ar[n+1];
    for(i=0;i<n;++i)
    cin>>ar[i];
    
    for(i=0;i<=n;++i)
    {
        for(j=0;j<=k;++j)
        dp[i][j]=1e8;
    }
    
    dp[0][0]=0;
    int ct1=0,ct2=0;
    
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=k;++j)
        {
            ct1=0,ct2=0;
            for(l=i-1;l>=0;--l)
            {
                if(ar[l]==0)
                ++ct1;
                else
                ++ct2;
                dp[i][j]=min(dp[i][j],dp[l][j-1]+ct1*ct2);
            }

        }
    }
    
    cout<<dp[n][k]<<endl;
    
    
    
    
	return 0;
}