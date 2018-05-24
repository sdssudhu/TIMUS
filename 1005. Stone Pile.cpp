#include <iostream>
using namespace std;

int ar[20],sum,mini,n;

void func(int i,int sum2)
{
    if(i==n)
    return;
    func(i+1,sum2+ar[i]);
    func(i+1,sum2);
    mini=min(mini,abs((sum-sum2)-sum2));
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>ar[i];
        sum=sum+ar[i];
    }
    mini=sum;
    func(0,0);
    cout<<mini<<endl;
	return 0;
}