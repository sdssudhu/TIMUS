	//For higher stack size use g++ -O2 -std=c++11 -Wall -Wl,--stack=268435456 a.cpp -o a.exe in cmd
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define ll long long
	#define ld long double
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

	vector<int> v[100001];

	vector<pair<int,int> >v2[100001];

	ll dp[101][101],ar[101];
	int visited[101],n,sz[101],sz2[101];

	void dfs(int i)
	{
		visited[i]=1;
		int k,l;
		dp[i][0]=0;
		for(int j=0;j<v[i].size();++j)
		{
			if(visited[v[i][j]]==0)
			{
				dfs(v[i][j]);
				for(k=n;k>=0;--k)
				{
					for(l=k;l>=0;--l)
					{
						dp[i][k]=min(dp[i][k],dp[i][l]+dp[v[i][j]][k-l]);
						if(k-l==sz2[v[i][j]])
							dp[i][k]=min(dp[i][k],dp[i][l]+(ll)sz[v[i][j]]);
					}
				}
			}
		}
	}

	void dfs2(int i,int p)
	{
		sz[i]=ar[i];
		sz2[i]=1;
		for(int j=0;j<v2[i].size();++j)
		{
			if(v2[i][j].f!=p)
			{
				ar[v2[i][j].f]=v2[i][j].s;
				dfs2(v2[i][j].f,i);
				sz[i]=sz[i]+sz[v[i][j]];
				sz2[i]+=sz2[v[i][j]];
			}
		}
		//cout<<i<<" "<<sz[i]<<endl;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int i,j,q,a,b;
			cin>>n>>q;
			int sum=0,x;
			for(i=0;i<n-1;++i)
			{
				cin>>a>>b>>x;
				sum=sum+x;
				v[a].pb(b);
				v[b].pb(a);
				v2[a].pb({b,x});
				v2[b].pb({a,x});
			}
			//cout<<sum<<endl;
			for(i=0;i<=n;++i)
			{
				for(j=0;j<=n;++j)
					dp[i][j]=1e18;
			}

			dfs2(1,-1);
			dfs(1);
			
			cout<<sum-dp[1][n-q-1]<<endl;
		}
		return 0;
	}
