#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        pair <ll,pair <ll,ll>> a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i].second.first>>a[i].second.second>>a[i].first;
        }
        sort(a,a+n);
        ll flag=0,cnt=0;
        if(n<=2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            ll i=0,j=1,k=2;
            ll flag=0;
            while((i<n)&&(j<n)&&(k<n))
            {
                cnt++;
                if(a[i].first==a[k].first)
                {
                    if(a[i].second.second>=a[k].second.first)
                    {
                        if(a[j].second.second>=a[k].second.first)
                        {
                            flag=1;
                            break;
                        }
                        else
                        {
                            j=j+1;
                            if(j==k)
                            {
                                k=k+1;
                            }
                        }
                    }
                    else 
                    {
                        i=i+1;
                        if(i==j)
                            j=j+1;
                        if(k==j)
                            k=k+1;
                    }
                }
                else
                {
                    i=j;
                    j=j+1;
                    if(j==k)
                        k=k+1;
                }

            }
            if(flag)
                cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
            }
            
        }
        cout<<cnt<<endl;
    }
}