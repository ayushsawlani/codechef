#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair <ll,ll>> compress_array(pair <ll,ll> *a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i].first!=a[i+1].first)
        {
            pair <ll,ll> temp;
            temp.first=a[i].first;
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i].first;
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
vector <pair <ll,ll>> contribution(pair <ll,ll> *a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=0;
    ll x=a[0].first-a[0].second;
    while(i<n-1)
    {
        if(a[i].first!=a[i+1].first)
        {
            pair <ll,ll> temp;
            temp.first=a[i].first;
            temp.second=c;
            ans.push_back(temp);
            c=a[i].first+a[i+1].second-a[i+1].first;
            x=a[i].first;
        }
        else
        {
            c+=(x+a[i+1].second-a[i+1].first);
        }
        i++;   
    }
    pair <ll,ll> temp;
    temp.first=a[i].first;
    temp.second=c;
    ans.push_back(temp);
    c=1;
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
        pair <ll,ll> a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i].first;
        }
        for(ll i=0;i<n;i++)
        {
            cin>>a[i].second;
        }
        ll minbi=a[0].second;
        for(ll i=0;i<n;i++)
        {
            if(minbi>a[i].second)
            {
                minbi=a[i].second;
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            if((a[i].first%a[i].second)>=minbi)
            {
                ans+=a[i].second-(a[i].first%a[i].second);
                a[i].first=0;
            }
            else
            {
                a[i].first=a[i].first%a[i].second;
            }
            
        }
        sort(a,a+n);
        ll cost[n];
        vector <pair <ll,ll>> v1=compress_array(a,n);
        vector <pair <ll,ll>> v2=contribution(a,n);
        memset(cost,0,n*sizeof(ll));
        for(ll i=1;i<n;i++)
        {
            if(a[i].first>a[0].first)
            {
                cost[0]+=(a[0].first+a[i].second-a[i].first);       
            }
        }
        for(ll i=1;i<v1.size();i++)
        {
            cost[i]=(cost[i-1]-v2[i].second)+(n-v1[i].second)*(v1[i].first-v1[i-1].first);              
        }
        ll min=cost[0];
        for(ll i=0;i<v1.size();i++)
        {
            if(min>cost[i])
                min=cost[i];
        }
        cout<<min+ans<<endl;
    }
}