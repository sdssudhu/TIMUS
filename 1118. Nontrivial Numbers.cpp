
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
    #define MAXN 1000000

int div2[MAXN + 1];

int main(){
    memset(div2,-1,sizeof div2);
    
    for(int i = 2;i <= MAXN;++i){
        if(div2[i] == -1){
            div2[i] = i;
            
            if(i <= MAXN / i)
                for(int j = i * i;j <= MAXN;j += i)
                    div2[j] = i;
        }
    }
    
    int L,U;
    
    scanf("%d %d",&L,&U);
    
    long long num;
    int ans;
    
    for(int i = L;i <= U;++i){
        int aux = i;
        long long sum = 1;
        
        while(aux != 1){
            int p = div2[aux],exp = 0;
            long long prod = p;
            
            while(aux % p == 0){
                prod *= p;
                aux /= p;
                ++exp;
            }
            
            sum *= (prod - 1) / (p - 1);
        }
        
        if(i == L || sum * ans < num * i){
            num = sum;
            ans = i;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}