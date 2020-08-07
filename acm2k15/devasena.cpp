#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M1 1000000007
#define M2 100005
ll freq[100005];
ll subset[100005];
long long int fast_expo(ll a, ll n,ll m1)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%m1;
		a=(a*a)%m1;
		n=n/2;
	}
	return ans;
}
int main()
{
    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        memset(freq,0,M2*sizeof(ll));
        memset(subset,0,M2*sizeof(ll));
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            freq[temp]++;
        }
        for(ll i=M2-1;i>=1;i--)
        {
            ll sub=1;
            for(ll j=i;j<M2;j=j+i)
            {
                sub=(sub*(fast_expo(2,freq[j],M1-1)))%(M1-1);
            }
            sub=(sub-1+M1-1)%(M1-1);
            for(ll j=2*i;j<M2;j=j+i)
            {
                sub=(sub-subset[j]+M1-1)%(M1-1);
            }
            subset[i]=sub;
        }
        ll ans=1;
        for(ll i=1;i<M2;i++)
        {
            ans=(ans*fast_expo(i,subset[i],M1))%M1;
        }
        cout<<ans<<endl;
    }
}