#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    long long ans;
    cin>>n;
    long long dp[n+1],i,j;
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    
    for(i=4;i<=n;++i)
    {
        dp[i]=dp[i-3]+dp[i-1]+1;
    }
    
    cout<<dp[n]<<endl;
    
	return 0;
}