#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll total_sum(ll *arr,ll i)
{
    if(i==0)
        return arr[0];
    else
    {
        return arr[i]+total_sum(arr,(i-1)/2);
    }
    
}
void update_key(ll *arr,ll i,ll j,ll l,ll r,ll k)
{
    if((l<=i)&&(j<=r))
    {
        arr[k]++;
    }
    else if((l>j)||(r<i));
    else
    {
        ll mid=(i+j)/2;
        update_key(arr,i,mid,l,r,2*k+1);
        update_key(arr,mid+1,j,l,r,2*k+2);
    }
}
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll n;
        cin>>n;
        ll c[n],h[n];
        for(ll i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for(ll i=0;i<n;i++)
        {
            cin>>h[i];
        }
        ll k=1;
        while(k<n)
        {
            k=2*k;
        }
        ll st[2*k-1];
        for(ll i=0;i<2*k-1;i++)
        {
            st[i]=0;
        }
        for(ll i=0;i<n;i++)
        {
            ll a,b;
            a=i-c[i];
            if(a<0)
                a=0;
            b=i+c[i];
            if(b>n-1)
                b=n-1;
            update_key(st,0,k-1,a,b,0);
        }
        ll final_level[n];
        for(ll i=0;i<n;i++)
        {
            final_level[i]=total_sum(st,i+k-1);
        }
        sort(final_level, final_level+n);
        sort(h,h+n);
        ll flag=0;
        for(ll i=0;i<n;i++)
        {
            if(h[i]!=final_level[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        cout<<endl;
        
    }
}