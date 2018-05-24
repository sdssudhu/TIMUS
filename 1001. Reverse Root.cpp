#include <bits/stdc++.h>
using namespace std;

vector<long double> v;

int main() 
{
    long double a,b;
    
    while(cin>>a)
    {
        b=sqrt(a);
        v.push_back(b);
    }
    
    for(int i=v.size()-1;i>=0;--i)
    {
        printf("%.9Lf\n",v[i]);
    }
    
	return 0;
}