#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,m,k,i,j,a,b;
    cin>>m>>n>>k;


    long double dp[m+1][n+1]={1e12},X=1.4142135623;
    
    int isval[m+1][n+1]={0};
    
    for(i=0;i<k;++i)
    {
        cin>>a>>b;
        isval[a][b]=1;
    }
    
    for(i=0;i<=m;++i)
    for(j=0;j<=n;++j)
    dp[i][j]=0;
    
    dp[0][0]=0.0;
    for(i=1;i<=m;++i)
    dp[i][0]=1.0*(i)*100;
    for(i=1;i<=n;++i)
    dp[0][i]=1.0*(i)*100;
    
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            dp[i][j]=min(1.0*dp[i-1][j]+100.0,1.0*dp[i][j-1]+100);
            if(isval[i][j]==1)
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+100*X);
        }
    }
    
    
    cout<<round(dp[m][n])<<endl;
    
    
	return 0;
}