#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n,k;
        cin>>n>>k;
        if((n/k)%k==0)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
        }
        
    }
}