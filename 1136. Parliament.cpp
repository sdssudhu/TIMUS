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

	vector<int> v;

	class node
	{
	public:
		node *left,*right,*par;
		int x,maxi,mini;
		node(int z)
		{
			left=NULL;
			right=NULL;
			par=NULL;
			x=z;
			mini=0,maxi=100000;
		}
	};

	void add_node(node* &root,int x)
	{
		while(x>root->maxi || x<root->mini)
		{
			root=root->par;
		}
		if(x>root->x)
		{
			root->right=new node(x);
			root->right->mini=root->x;
			root->right->maxi=root->maxi;
			root->right->par=root;
			root=root->right;
		}
		else
		{
			root->left=new node(x);
			root->left->maxi=root->x;
			root->left->mini=root->mini;
			root->left->par=root;
			root=root->left;
		}
	}

	void print(node *root)
	{
		if(root->right!=NULL)
			print(root->right);
		if(root->left!=NULL)
			print(root->left);
		cout<<root->x<<endl;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,i,j,a;
			cin>>n;
			for(i=0;i<n;++i)
			{
				cin>>a;
				v.pb(a);
			}
			node *root=new node(v[n-1]);
			node *root2=root;
			for(i=n-2;i>=0;--i)
			{
				add_node(root,v[i]);
			}
			root=root2;
			print(root);
		}
		return 0;
	}