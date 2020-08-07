#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    //cout<<1e18<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a,b,c,d,e;
        cin>>a;
        unsigned long long int s=a+2*((ll)pow(10,n));
        cout<<s<<endl;
        cin>>b;
        cout<<((ll)pow(10,n))-b<<endl;
        cin>>d;
        cout<<((ll)pow(10,n))-d<<endl;
        cin>>c;
        if(c==-1)
            break;
    }
}