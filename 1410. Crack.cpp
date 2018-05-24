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

	ll dp[100001],ar[100001];

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			char ch;
			int n=0,ct=0,x;
			string s;

			while(getline(cin,s))
			{
			x=0;
			ct=0;
			while(x<s.length())
			{
				ch=s[x];
				++x;
				if((ch>=65 && ch<=90) || (ch>=97  && ch<=122))
					++ct;
				else
				{
					if(ct>0)
					{
						ar[n]=ct;
						++n;
						ct=0;
					}
				}
			}
			if(ct>0)
					{
						ar[n]=ct;
						++n;
						ct=0;
					}
			}
			int i,j;
			dp[0]=ar[0];
			dp[1]=max(dp[0],ar[1]);
			for(i=2;i<n;++i)
				dp[i]=max(dp[i-1],dp[i-2]+ar[i]);
			cout<<dp[n-1]<<endl;
		}
		return 0;
	}