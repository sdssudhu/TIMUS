#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long n,m,i,j,dp[100];
    
    cin>>n;
    dp[1]=1;
    dp[2]=1;
    for(i=3;i<=n;++i)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    
    cout<<2*dp[n]<<endl;
    
	return 0;
}