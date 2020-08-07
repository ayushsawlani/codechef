#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long
ll merge(ll *a,ll i,ll j,ll k)
{
	ll ans=0;
        ll a_i=i,b_i=k+1,c_i=0;
        ll c[j-i+1];
        while((a_i<=k)&&(b_i<=j))
        {
                if(a[a_i]>a[b_i])
		{
			ans=ans+k-a_i+1;
                        c[c_i++]=a[b_i++];
		}
                else
                        c[c_i++]=a[a_i++];
        }
        while(a_i<=k)
                c[c_i++]=a[a_i++];
        while(b_i<=j)
                c[c_i++]=a[b_i++];
        for(ll p=0;p<c_i;p++)
                a[i+p]=c[p];
	return ans;
}
ll ms(ll *a, ll i, ll j)
{
        if(j>i)
        {
                ll m=(i+j)/2;
                return ms(a,i,m)+ms(a,m+1,j)+merge(a,i,j,m);
        }
	else
		return 0;
}
int main()
{
    ll q;
    cin>>q;
    while(q--)
    {
        ll c[1005];
        memset(c,0,1005*sizeof(ll));
        ll n;
        cin>>n;
        ll dp[n+2][n+2];
        memset(dp,0,(n+2)*(n+2)*sizeof(ll));
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ordered_set x;
        ll lp=0,rp=n-1;
        ll ans=0;
        for(ll l=n-1;l>=0;l--)
        {
            for(ll i=0;i<=n-l;i++)
            {
                ll j=n-(l)-i;
                ll L1=0,G1=0,L2=0,G2=0;
                for(ll k=0;k<n;k++)
                {
                    if(i>0)
                    {
                        if((k<i)||(k>n-j-1))
                        {
                            if(a[i-1]>a[k])
                                L1++;
                            else if(a[i-1]<a[k])
                            {
                                G1++;
                            }
                        }
                    }
                    if(j>0)
                    {
                        if((k<i)||(k>n-j-1))
                        {
                            if(a[n-j]>a[k])
                                L2++;
                            else if(a[n-j]<a[k])
                            {
                                G2++;
                            }
                        }
                    }
                }                
                ll m1=min(L1,G1);
                ll m2=min(L2,G2);
                if((i>0)&&(j>0))
                    dp[i][j]=min(dp[i-1][j]+m1,dp[i][j-1]+m2);
                else if(i>0)
                    dp[i][j]=dp[i-1][j]+m1;
                else if(j>0)
                    dp[i][j]=dp[i][j-1]+m2;
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        ans=INT64_MAX;
        for(ll i=0;i<=n;i++)
        {
            ans=min(ans,dp[i][n-i]);
        }
        cout<<ans<<endl;
    }
}