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
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	
	using namespace std;

	ll mod;

	long long mul(long long a,long long n)
	{
		//cout<<a<<" "<<n<<endl;
	     long long ret;
	     if(n==0)
	       return 0;
	     ret=mul(a,n/2);
	     ret=(ret+ret)%mod;
	     if(n%2)
	       ret=(ret+a)%mod;
	    //cout<<a<<" "<<n<<" "<<ret<<endl;
	     return ret;
	     

	}

	#define matsize 25

	void matmul(ll a[matsize][matsize],ll b[matsize][matsize],ll ans[matsize][matsize],int m,int n,int p)
	{
		int i,j,k;
		for(i=1;i<=m;++i)
		{
			for(j=1;j<=p;++j)
			{
				ans[i][j]=0;
				for(k=1;k<=n;++k)
				{
					ans[i][j]=(ans[i][j]+mul(a[i][k],b[k][j]))%mod;
				}
			}
		}
	}

	void matpow(ll a[matsize][matsize],ll ans[matsize][matsize],int n,ll p)
	{
		int i,j;
		if(p==0)
		{
			for(i=1;i<=n;++i)
				ans[i][i]=1;
			return;
		}
		else if(p==1)
		{
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=n;++j)
					ans[i][j]=(a[i][j])%mod;
			}
			return;
		}
		else
		{
			ll ans2[matsize][matsize];
			matpow(a,ans2,n,p/2);
			if(p%2==1)
			{
				ll ans3[matsize][matsize];
				matmul(ans2,ans2,ans3,n,n,n);
				matmul(ans3,a,ans,n,n,n);
			}
			else
			{
				matmul(ans2,ans2,ans,n,n,n);
			}
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			ll n,k,i,m;
			cin>>n>>k>>m;
			mod=m;
			ll dp[3];
			dp[1]=(k-1+mod)%mod;
			//cout<<dp[1]<<endl;
			dp[2]=mul(dp[1],k);

			if(n<=2)
			{
				cout<<dp[n]<<endl;
				return 0;
			}
			ll mat[matsize][matsize],mat2[matsize][matsize],ans[matsize][matsize],ans2[matsize][matsize];
			mat2[1][1]=(k-1+mod)%mod;
			mat2[1][2]=(k-1+mod)%mod;
			mat2[2][1]=1;
			mat2[2][2]=0;

			matpow(mat2,ans,2,n-2);

			//cout<<ans[1][1]<<" "<<ans[1][2]<<" "<<dp[2]<<" "<<dp[1]<<endl;

			ll answ=(mul(dp[2],ans[1][1])+mul(dp[1],ans[1][2]))%mod;
			cout<<answ<<endl;
		}
		return 0;
	}
