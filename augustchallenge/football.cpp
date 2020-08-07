#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n;
        cin>>n;
        ll c[n];
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            c[i]=2*temp;
        }
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            c[i]-=temp;
        }
        ll max=c[0];
        for(ll i=1;i<n;i++)
        {
            if(max<c[i])
                max=c[i];
        }
        if(max>=0)
            cout<<max*10<<endl;
        else
        {
            cout<<0<<endl;
        }
        
    }
}