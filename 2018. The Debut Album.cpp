#include <iostream>
using namespace std;

const long long M=1e9+7;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    long long dp[n+1],dp2[n+1],i,j,k;
    
    dp[0]=1;
    dp2[0]=1;
    dp[1]=1;
    dp2[1]=1;
    
    for(i=2;i<=n;++i)
    {
        dp[i]=0,dp2[i]=0;
        for(k=i-1;k>=0 && i-k<=a;--k)
        {
        dp[i]=(dp[i]+dp2[k])%M;
        }
        for(k=i-1;k>=0 && i-k<=b;--k)
        dp2[i]=(dp2[i]+dp[k])%M;
        

    }

    cout<<(dp[n]+dp2[n])%M<<endl;
    
	return 0;
}