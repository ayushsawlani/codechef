#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll m,n;
        cin>>n>>m;
        ll type[m+9];
        memset(type,0,(m+9)*sizeof(ll));
        ll f[n];
        ll count[m+9];
        memset(count,0,(m+9)*sizeof(ll));
        for(ll i=0;i<n;i++)
        {
            cin>>f[i];
        }
        ll p[n];
        for(ll i=0;i<n;i++)
        {
            cin>>p[i];
        }
        for(ll i=0;i<n;i++)
        {
            type[f[i]]+=p[i];
            count[f[i]]++;
        }
        ll m1=INT64_MAX;
        for(ll i=1;i<=m;i++)
        {
            if(count[i]>0)
                m1=min(m1,type[i]);
        }
        cout<<m1<<endl;
    }
}