#include<bits/stdc++.h>
using namespace std;

long long dp[20],dp2[20];

int main(int argc, char const *argv[])
{
	int i,j,n,k;
	cin>>n>>k;


	dp[1]=k-1;
	dp2[1]=0;
	for(i=2;i<=n;++i)
	{
		dp[i]=dp[i-1]*(k-1)+dp2[i-1]*(k-1);
		dp2[i]=dp[i-1];
	}
	long long ans=dp[n]+dp2[n];
	cout<<ans<<endl;
	return 0;
}