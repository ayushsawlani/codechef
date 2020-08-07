#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair <pair <string,ll>,ll>> compress_array(pair <string,ll> *a, ll n)
{
    vector <pair <pair <string,ll>,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <pair <string,ll>,ll> temp;
            temp.first=a[i];
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
    pair <pair <string,ll>,ll> temp;
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
vector <pair <pair <string,ll>,ll>> compress_array2(vector <pair <pair <string,ll>,ll>> a, ll n)
{
    vector <pair <pair <string,ll>,ll>> ans;
    ll i=0;
    ll c=a[0].second;
    while(i<n-1)
    {
        if(a[i].first.first!=a[i+1].first.first)
        {
            pair <pair <string,ll>,ll> temp;
            temp.first=a[i].first;
            temp.second=c;
            ans.push_back(temp);
            c=a[i+1].second;
        }
        else
        {
            c=max(c,a[i+1].second);
        }
        i++;   
    }
    pair <pair <string,ll>,ll> temp;
    temp.first=a[i].first;
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        pair <string,ll> a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i].first>>a[i].second;
        }
        sort(a,a+n);
        vector <pair<pair <string,ll>,ll>> v=compress_array(a,n);
        vector <pair <pair <string,ll>,ll>> ans=compress_array2(v,v.size());
        ll sum =0;
        for(ll i=0;i<ans.size();i++)
        {
            sum+=ans[i].second;
        }
        cout<<sum<<endl;
    }
}