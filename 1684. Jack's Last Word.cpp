#include<bits/stdc++.h>

using namespace std;

int lps[75000*2+10];

void complps(string s)
{
	int k=0,j=0;
	lps[0]=0;
	for(j=1;j<s.length();++j)
	{
		while(k>0 && s[k]!=s[j])
			k=lps[k-1];

		if(s[k]==s[j])
			++k;

		lps[j]=k;
	}
}


int main()
{
	string s1,s2;
	int m,n,i,j,k;
	cin>>s1>>s2;
	int x=s1.length();
	s1=s1+"#"+s2;
	m=s1.length();
	n=s2.length();



	complps(s1);

	vector<int> v;
	int z=s2.length()-1;

	while(lps[x+1+z]>0)
	{
		z=z-lps[x+1+z];
		v.push_back(z+1);
	}


	if(z!=-1)
		cout<<"Yes"<<endl;
	else

	{
		cout<<"No"<<endl;
		for(i=v.size()-1;i>0;--i)
		{
			for(j=v[i];j<v[i-1];++j)
				cout<<s2[j];
			cout<<" ";
		}

		for(j=v[0];j<s2.length();++j)
			cout<<s2[j];
		cout<<endl;

	}



	return 0;
}