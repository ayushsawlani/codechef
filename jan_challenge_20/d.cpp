#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,q;
    cin>>n>>q;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll incsize=0,decsize=0;
    vector <pair <ll,ll>> increasing,decreasing;
    for(ll i=0,j=0;i<n;)
    {
        j=i;
        while(j<n-1)
        {
            if(a[j]>=a[j+1])
                break;
            j++;
        }
        if(i!=j)
        {
            incsize++;
            increasing.push_back(pair <ll,ll>(i,j));
        }
        i=j+1;
    }
    for(ll i=0,j=0;i<n;)
    {
        j=i;
        while(j<n-1)
        {
            if(a[j]<=a[j+1])
                break;
            j++;
        }
        if(i!=j)
        {
            decsize++;
            decreasing.push_back(pair <ll,ll>(i,j));
        }
        i=j+1;
    }
    for(ll it=0;it<q;it++)
    {
        ll l,r;
        cin>>l>>r;
        l--,r--;
        ll i=0,j=incsize-1;
        ll m=0;
        while(i<=j)
        {
            m=(i+j+1)/2;
            if(increasing[m].second==l)
                break;
            else if(increasing[m].second>l)
                j=m-1;
            else
            {
                i=m+1;
            }
        }
        if(incsize)
            if(increasing[m].second<l)
                m++;
        ll p1=m;
        m=0;i=0;j=incsize-1;
        while(i<=j)
        {
            m=(i+j+1)/2;
            if(increasing[m].first==r)
                break;
            else if(increasing[m].first>r)
                j=m-1;
            else
            {
                i=m+1;
            }
        }
        if(incsize)
            if(increasing[m].first>r)
                m--;
        ll p2=m;
        ll x1=p2-p1+1;
        if((p2>=0)&&(p2<incsize))
            if(increasing[p2].first==r)
                x1--;
        if((p1>=0)&&(p1<incsize))
            if(increasing[p1].second==l)
                x1--;
        if(incsize==0)
            x1=0;
        m=0;i=0;j=decsize-1;
        while(i<=j)
        {
            m=(i+j+1)/2;
            if(decreasing[m].first==r)
                break;
            else if(decreasing[m].first>r)
                j=m-1;
            else
            {
                i=m+1;
            }
        }
        if(decsize)
            if(decreasing[m].first>r)
                m--;
        p2=m;
        m=0;i=0;j=decsize-1;
        while(i<=j)
        {
            m=(i+j+1)/2;
            if(decreasing[m].second==l)
                break;
            else if(decreasing[m].second>l)
                j=m-1;
            else
            {
                i=m+1;
            }
        }
        if(decsize)
            if(decreasing[m].second<l)
                m++;
        p1=m;
        ll x2=p2-p1+1;
        if((p2>=0)&&(p2<decsize))
            if(decreasing[p2].first==r)
                x2--;
        if((p1>=0)&&(p1<decsize))
            if(decreasing[p1].second==l)
                x2--;
        if(decsize==0)
            x2=0;
        if(x1==x2)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
}