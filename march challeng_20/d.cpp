#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll int 
ll stk(ll n)
{
    ll k=1;
    for(;k<n;k=k*2);
    return k;
}
vector <pair <ll,ll>> buildst(vector <pair <ll,ll>> a,ll n)
{
    ll k=stk(n);
    vector <pair <ll,ll>> ans(2*k-1);
    for(ll i=k-2+n;i>=k-1;i--)
        ans[i]=a[i-k+1];
    return ans;
}
ll jadoo(vector <pair <ll,ll>> &intersectree,vector <pair <ll,ll>> &uniontree, ll node, ll l, ll r, ll x1, ll x2, ll y)
{
    if((x1>r)||(x2<l))
    {
        return 0;
    }
    else if((x1>l)||(x2<r))
    {
        ll m=(l+r)/2;
        return jadoo(intersectree,uniontree,2*node+1,l,m,x1,x2,y)+jadoo(intersectree,uniontree,2*node+2,m+1,r,x1,x2,y);
    }
    else
    {
        if((y<=intersectree[node].second&&y>=intersectree[node].first))
        {
            return r-l+1;
        }
        else if((y<=uniontree[node].second&&y>=uniontree[node].first))
        {    
            ll m=(l+r)/2;
            return jadoo(intersectree,uniontree,2*node+1,l,m,x1,x2,y)+jadoo(intersectree,uniontree,2*node+2,m+1,r,x1,x2,y);
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,q;
        scanf("%d",&n);
        //n=1e5;
        scanf("%d",&q);
       // q=1e5;
        vector <ll> in(n);
        for(ll i=0;i<n;i++)
        {
            //in[i]=1+rand()%((ll)(1e9));
            scanf("%d",&in[i]);
        }
        vector <pair <ll,ll>> interval(n-1);
        for(ll i=0;i<n-1;i++)
        {
            interval[i]=pair <ll,ll>(min(in[i],in[i+1]),max(in[i],in[i+1]));
        }
        ll k=stk(n-1);
        vector <pair <ll,ll>> intersectiontree=buildst(interval,n-1);
        for(ll i=k-2+n;i<2*k-1;i++)
            intersectiontree[i]=pair <ll,ll>(1,1e9);
        for(ll i=k-2;i>=0;i--)
        {
            pair <ll,ll> c1=intersectiontree[2*i+1],c2=intersectiontree[2*i+2];
            if((c1.second<c2.first)||(c2.second<c1.first))
            {
                intersectiontree[i].first=-1;
                intersectiontree[i].second=-1;
            }
            else
            {
                intersectiontree[i].first=max(c1.first,c2.first);
                intersectiontree[i].second=min(c1.second,c2.second);
            }
        }
 //
        vector <pair <ll,ll>> uniontree=buildst(interval,n-1);
        for(ll i=k-2+n;i<2*k-1;i++)
            uniontree[i]=pair <ll,ll>(-1,-1);
        for(ll i=k-2;i>=0;i--)
        {
            pair <ll,ll> c1=uniontree[2*i+1],c2=uniontree[2*i+2];
            if((c1.second<c2.first)||(c2.second<c1.first))
            {
                uniontree[i].first=-1;
                uniontree[i].second=-1;
            }
            else
            {
                uniontree[i].first=min(c1.first,c2.first);
                uniontree[i].second=max(c1.second,c2.second);
            }
        }
        for(ll i=0;i<q;i++)
        {
            ll x1,x2,y;
            //ll r1=1+rand()%n;
           // ll r2=1+rand()%n;
            //x1=min(r1,r2);
           // x2=max(r1,r2);
         //   y=1+rand()%((ll)1e9);
            scanf("%d",&x1);
            scanf("%d",&x2);
            scanf("%d",&y);
            x1--;x2--;
            x2--;
            printf("%d\n",jadoo(intersectiontree,uniontree,0,0,k-1,x1,x2,y));
        }
    }
}