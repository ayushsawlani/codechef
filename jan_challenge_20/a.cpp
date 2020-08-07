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
        ll s;
        cin>>s;
        ll w[3];
        cin>>w[0]>>w[1]>>w[2];
        ll pre[3],suff[3];
        pre[0]=w[0];
        pre[1]=pre[0]+w[1];
        pre[2]=pre[1]+w[2];
        suff[2]=w[2];
        suff[1]=suff[2]+w[1];
        suff[0]=suff[1]+w[0];
        ll i=-1;
        ll j=3;
        ll previ=0,prevj=2;
        ll ans=0;
        while(i<j-1)
        {
            ll x1=1,x2=1;
            for(;i+x1<2;x1++)
            {
                if(i>-1)
                    if(s<pre[i+x1]-pre[i])
                        break;
                if(i==-1)
                    if(s<pre[i+x1])
                        break;
            }
            x1--;
            for(;j-x2>=0;x2++)
            {
                if(j<3)
                    if(s<suff[j-x2]-suff[j])
                        break;
                if(j==3)
                    if(s<suff[j-x2])
                        break;
            }
            x2--;
            if(x1>x2)
            {
                i=i+x1;
            }
            else
            {
                j=j-x2;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
}