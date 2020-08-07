#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        string s;
        cin>>s;
        ll c=0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                c++;
        }
        if(c%2==0)
            cout<<"LOSE"<<endl;
        else
        {
            cout<<"WIN"<<endl;
        }
        
    }
}