
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define ll long long int
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


	vector<int> v;
	int isprime[1000001];
	void init()
	{
		int i,j;
		isprime[1]=1;
		for(i=2;i<=1000000;++i)
		{
			if(isprime[i]==0)
			{
			for(j=2*i;j<=1000000;j=j+i)
				isprime[j]=1;
			v.pb(i);
			}
		}
	}


	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		init();
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,i,j;
			cin>>n;
			cout<<v[n-1]<<endl;
		}
		return 0;
	}