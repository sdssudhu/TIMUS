#include <bits/stdc++.h>
using namespace std;

long long dp[501][501];


long long func(int i,int j)
{
    if(i==0)
    return 1;
    if(j==0)
    return 0;
    if(dp[i][j]==-1)
    {
    dp[i][j]=func(i,j-1);
    if(i>=j)
    dp[i][j]+=func(i-j,j-1);
    }
    return dp[i][j];
    
}


int main() 
{
    long long n;
    
    cin>>n;
    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j)
    dp[i][j]=-1;
    
    cout<<func(n,n-1)<<endl;
    
    
	return 0;
}