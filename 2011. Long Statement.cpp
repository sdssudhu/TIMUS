#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,i,j;
    cin>>n;
    int ar[n];
    for(i=0;i<n;++i)
    cin>>ar[i];
    sort(ar,ar+n);
    
    for(i=0;i<5;++i)
    {
        if(next_permutation(ar,ar+n))
        ;
        else
        break;
    }
    if(i>=5)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    
	return 0;
}