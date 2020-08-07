#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 200001
ll *buildst(ll *a,ll n)
{
    ll k=1;
    for(;k<n;k=k*2);
    ll *ans=(ll *)(malloc((2*k-1)*sizeof(ll)));
    for(ll i=0;i<2*k-1;i++)
        ans[i]=0;
    for(ll i=k-2+n;i>=k-1;i--)
        ans[i]=a[i-k+1];
    return ans;
}
ll stk(ll n)
{
    ll k=1;
    for(;k<n;k=k*2);
    return k;
}
void range_update(ll *a,ll *st,ll l,ll r,ll i,ll j,ll k,ll d)
{
    if((i>r)||(l>j));
    else if((l<=i)&&(r>=j))
    {
        st[k]=max(st[k],d);
    }
    else
    {
        ll m=(i+j)/2;
        range_update(a,st,l,r,i,m,2*k+1,d);
        range_update(a,st,l,r,m+1,j,2*k+2,d); 
    }
}
ll overlap_max(ll *a,ll *st,ll l,ll r,ll i,ll j,ll k)
{
    if((l>j)||(i>r))
    {
        return -1;
    }
    else if((i>=l)&&(j<=r))
    {
        return st[k];
    }
    else
    {
        ll mid=(i+j)/2;
        ll p1=overlap_max(a,st,l,r,i,mid,2*k+1);
        ll p2=overlap_max(a,st,l,r,mid+1,j,2*k+2);
        ll ans=max(p1,p2);
        ans=max(ans,st[k]);
        return ans;
    }
   
}
ll getelement(ll *st, ll i, ll n)
{
    ll sum=0;
    i=i+stk(n)-1;
    while(i>0)
    {
        sum=max(sum,st[i]);
        i=((i-1)/2);
    }
    sum=max(sum,st[0]);
    return sum;
}
int main()
{
    ll q;
    cin>>q;
    ll n=stk(M);
    ll a[n];
    memset(a,0,n*sizeof(ll));
    ll *st=buildst(a,n);
    for(ll i=0;i<q;i++)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll l,r,d;
            cin>>l>>r>>d;
            ll x=overlap_max(a,st,l,r,0,n-1,0);
            range_update(a,st,l,r,0,n-1,0,x+d);
        }
        else if(type==2)
        {
            ll x;
            cin>>x;
            cout<<getelement(st,x,n)<<endl;
        }
    }
}