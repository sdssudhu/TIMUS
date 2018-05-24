
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
	
	map<string,int> mp;
	map<string,int>::iterator it;
	vector<int> v[100001];
	int depth[10001],visited[100001];

	void bfs(int i,int d)
	{
		queue<pair<int,int> >q;
		q.push({i,d});
		pii x;
		depth[i]=d;
		int j;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			i=x.f;
			d=x.s;
			for(int j=0;j<v[i].size();++j)
			{
				if(depth[v[i][j]]>d+1)
				{
					q.push({v[i][j],d+1});
					depth[v[i][j]]=d+1;
				}
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
			int n,i,j,a,b,c,ct;

			string s,s2,s3;
			mp["Isenbaev"]=1;
			ct=2;
			cin>>n;
			for(i=0;i<=10000;++i)
				depth[i]=10000;
			int flag=0;
			for(i=0;i<n;++i)
			{
				cin>>s>>s2>>s3;
				if(s=="Isenbaev" || s2=="Isenbaev" || s3=="Isenbaev")
					flag=1;
				if(mp[s]==0)
				{
					mp[s]=ct;
					++ct;
				}
				if(mp[s2]==0)
				{
					mp[s2]=ct;
					++ct;
				}
				if(mp[s3]==0)
				{
					mp[s3]=ct;
					++ct;
				}
				a=mp[s],b=mp[s2],c=mp[s3];

				v[a].pb(b);
				v[a].pb(c);
				v[b].pb(a);
				v[b].pb(c);
				v[c].pb(a);
				v[c].pb(b);
			}
			bfs(1,0);
			for(it=mp.begin();it!=mp.end();++it)
			{
				if(flag==0 && it->first=="Isenbaev")
					continue;
				cout<<it->first<<" ";
				if(depth[it->second]==10000)
				{
					cout<<"undefined"<<endl;
				}
				else
				{
					cout<<depth[it->s]<<endl;
				}
			}

		}
		return 0;
	}