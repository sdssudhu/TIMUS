
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
	int flag,ar[100001];
	vector<int> v2;

	void dfs(int i,int x,int p)
	{
		if(x==0)
		{
			v2.pb(i);
		}
		ar[i]=x;
		for(int j=0;j<v[i].size();++j)
		{
			if(ar[v[i][j]]==-1)
			{
				dfs(v[i][j],1-x,i);
			}
		}
		int z=0;
		for(int j=0;j<v[i].size();++j)
		{
			if(ar[v[i][j]]==1-x)
			{
				z=1;
			}
		}

		if(z==0)
			flag=1;

	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,i,j,x,a;
			cin>>n;

			for(i=1;i<=n;++i)
			{
				ar[i]=-1;
				start:
				cin>>x;
				if(x!=0)
				{
					v[i].pb(x);
					v[x].pb(i);
					goto start;
				}
			}
			for(i=1;i<=n;++i)
			{
			if(ar[v[i][j]]==-1)
				dfs(i,1,-1);
			}
			if(flag==1)
			{
				cout<<0<<endl;
				return 0;
			}
			cout<<v2.size()<<endl;
			for(i=0;i<v2.size();++i)
				cout<<v2[i]<<" ";
			cout<<endl;
		}
		return 0;
	}