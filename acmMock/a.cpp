#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a,a+n);
        if(n==1)
        {
            cout<<sum<<endl;
        }
        else
        {
            ll i=0;
            while(a[i]<=k)
            {
                i++;
            }
            if(i>=n-1)
            {
                cout<<sum<<endl;
            }
            else
            {
                ll ans=k;
                for(ll j=0;j<i;j++)
                    ans+=a[j];
                i++;
                while(i<n)
                {
                    ans+=k;
                    if(i>0)
                    {
                        a[i]=a[i]-a[i-1]+k;
                    }
                    i++;
                }
                ans+=(a[n-1]-k);
                cout<<ans<<endl;
            }
            
        }
    }
}