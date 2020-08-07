#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1048576
ll imp1[M],imp2[M],imp3[M],imp4[M];
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<M;i++)
        {
            imp4[i]=0;
            imp3[i]=0;
            imp2[i]=0;
            imp1[i]=-2;
        }
        imp1[0]=-1;
        imp3[0]=1;
        imp4[0]=-1;
        cin>>a[0];
        for(ll i=1;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a[i]=temp^a[i-1];
        }

        for(ll i=0;i<n;i++)
        {
            imp2[a[i]]+=((i-1)*imp3[a[i]]-imp4[a[i]]);
            imp1[a[i]]=i;
            imp3[a[i]]+=1;
            imp4[a[i]]+=i;
        }
        ll sum=0;
        for(ll i=0;i<M;i++)
        {
            sum+=imp2[i];
        }
        cout<<sum<<endl;
    }
}