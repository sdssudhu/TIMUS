#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t,n,k=1,i,j;

	vector<int> sq;

	for(i=1;i<=1000;++i)
		sq.push_back(i*i);

  t=1;
	while(t>0)
	{
		++k;
		cin>>n;
		int ar[i];

		int dp[n+1];
		dp[0]=0;
		dp[1]=1;
		for(i=2;i<=n;++i)
		{
			dp[i]=i;
			for(j=0;j<sq.size();++j)
			{
				if(i<sq[j])
					break;
				dp[i]=min(dp[i],1+dp[i-sq[j]]);
			}
		}
		cout<<dp[n]<<endl;

		--t;
	}
	return 0;
}