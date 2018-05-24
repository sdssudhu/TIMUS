
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	using namespace std;
	
	int dp[100][100];

	ll func(int a,int b)
	{
		if(a<0)
			return 0;
		if(dp[a][b]!=-1)
			return dp[a][b];

		if(a==0)
				return dp[a][b]=1;

		if(b==0)
				return dp[a][b]=0;
		
			dp[a][b]=0;
		for(int i=0;i<=9;++i)
			dp[a][b]+=func(a-i,b-1);
		return dp[a][b];
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int s,i,j;
			cin>>s;
				for(i=0;i<100;++i)
				for(j=0;j<100;++j)
					dp[i][j]=-1;
				if(s!=1)
			cout<<func(s,9)<<endl;
			else
				cout<<1+func(s,9)<<endl;       // func(s,9) doesn't include 1e9.
		}
		return 0;
	}