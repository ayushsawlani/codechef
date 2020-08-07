#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll int
int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(0);
    ll t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,q;
        scanf("%d",&n);
        scanf("%d",&q);
        vector <ll> in(n);
        for(ll i=0;i<n;i++)
        {
            scanf("%d",&in[i]);
        }
        ll seed=0;
        for(ll i=0;i<n;i++)
        {
            ll sum=0;
            while(in[i])
            {
                sum+=(in[i]%2);
                in[i]/=2;
            }
            seed+=(1-sum%2);
        }
        for(ll i=0;i<q;i++)
        {
            ll p;
            scanf("%d",&p);
            ll pairity=0;
            while(p)
            {
                pairity+=(p%2);
                pairity%=2;
                p=p/2;
            }
            if(pairity)
            {
                printf("%d %d\n",n-seed,seed);
            }
            else
            {
                printf("%d %d\n",seed,n-seed);
            }
        }
    }
}