
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

	vector<ll> v[2],v2[2];

	ll power(ll a, ll b)	//a is base, b is exponent
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b%2 == 1)
			return (power(a,b-1)*a)%mod;
		ll q = power(a,b/2);
		return (q*q)%mod;
	}


	ll invv(ll x)
	{
		return power(x,mod-2);
	}

	void hashf(string s,int i)
	{
		int j;
		v[i].pb(0);
		v2[i].pb(0);

		for(j=1;j<=s.length();++j)
		{
			v[i].pb((v[i][j-1]+(s[j-1]-'A')*power(31,j))%mod);
			v2[i].pb((v2[i][j-1]+(s[j-1]-'A')*power(153,j))%mod);

		}
	}

	ll inv[2][100001];
	

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,i,j;
			cin>>n;
			string s,s2;
			cin>>s>>s2;

			for(i=0;i<=n;++i)
			{
				inv[0][i]=invv(power(31,i));
				inv[1][i]=invv(power(153,i));
			}

			hashf(s,0);
			hashf(s2,1);
			set<pair<int,int> > st;
			set<pair<int,int> >::iterator it;

			int l=0,r=n,ans=0,mid,flag;

			while(l<=r)
			{
				flag=0;
				mid=(l+r)/2;
				st.clear();
				for(i=mid;i<=n;++i)
				{
					st.insert({((v[0][i]-v[0][i-mid]+mod)%mod*inv[0][i-mid])%mod,((v2[0][i]-v2[0][i-mid]+mod)%mod*inv[1][i-mid])%mod});
				}
				for(i=mid;i<=n;++i)
				{
					it=st.find({((v[1][i]-v[1][i-mid]+mod)%mod*inv[0][i-mid])%mod,((v2[1][i]-v2[1][i-mid]+mod)%mod*inv[1][i-mid])%mod});

					if(it!=st.end())
					{
						flag=1;
					}
				}
				if(flag==1)
				{
					ans=mid;
					l=mid+1;
				}
				else
					r=mid-1;
			}
			st.clear();
			mid=ans;
			for(i=mid;i<=n;++i)
				{
					st.insert({((v[0][i]-v[0][i-mid]+mod)%mod*inv[0][i-mid])%mod,((v2[0][i]-v2[0][i-mid]+mod)%mod*inv[1][i-mid])%mod});
				}
				for(i=mid;i<=n;++i)
				{
					it=st.find({((v[1][i]-v[1][i-mid]+mod)%mod*inv[0][i-mid])%mod,((v2[1][i]-v2[1][i-mid]+mod)%mod*inv[1][i-mid])%mod});
					if(it!=st.end())
					{
							cout<<s2.substr(i-ans,ans)<<endl;
							return 0;
					}
			}
		}
		return 0;
	}