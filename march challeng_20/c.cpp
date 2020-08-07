#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll r0,c0;
        cin>>r0>>c0;
        ll diff=10-r0-c0;
        vector <pair <ll,ll>> ans;
        if(diff)
            ans.push_back(pair <ll,ll>(r0+diff/2,c0+diff/2));
        ans.push_back(pair <ll,ll>(8,2));
        ans.push_back(pair <ll,ll>(7,1));
        ans.push_back(pair <ll,ll>(6,2));
        ans.push_back(pair <ll,ll>(5,1));
        ans.push_back(pair <ll,ll>(8,4));
        ans.push_back(pair <ll,ll>(7,5));
        ans.push_back(pair <ll,ll>(8,6));
        ans.push_back(pair <ll,ll>(3,1));
        ans.push_back(pair <ll,ll>(2,2));
        ans.push_back(pair <ll,ll>(1,1));
        ans.push_back(pair <ll,ll>(8,8));
        ans.push_back(pair <ll,ll>(5,5));
        ans.push_back(pair <ll,ll>(2,8));
        ans.push_back(pair <ll,ll>(1,7));
        ans.push_back(pair <ll,ll>(2,6));
        ans.push_back(pair <ll,ll>(1,5));
        ans.push_back(pair <ll,ll>(4,8));
        ans.push_back(pair <ll,ll>(5,7));
        ans.push_back(pair <ll,ll>(6,8));
        ans.push_back(pair <ll,ll>(1,3));
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
 
    }
}