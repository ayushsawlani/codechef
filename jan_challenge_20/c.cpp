#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll matrix[n][m];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>>matrix[i][j];
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll diff=1;
                for(;((i+diff)<n)&&((i-diff)>=0)&&((j+diff)<m)&&((j-diff)>=0);diff++)
                {
                    if((matrix[i+diff][j]!=matrix[i-diff][j])||(matrix[i][j+diff]!=matrix[i][j-diff]))
                        break;
                }
                diff--;
                ans+=diff+1;
            }
        }
        cout<<ans<<endl;
    }
}   