#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> >v;

bool comp(pair<int,int> i,pair<int,int> j)
{
    return i.second<j.second;
}


int main() 
{
	int n,i,j,a,b,x,ct=0;
    cin>>n;
    
    for(i=0;i<n;++i)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end(),comp);
    
    x=-1;
    for(i=0;i<n;++i)
    {
        if(v[i].first>=x+1)
        {
            ++ct;
            x=v[i].second;
        }
    }
    
	cout<<ct<<endl;
	
	return 0;
}