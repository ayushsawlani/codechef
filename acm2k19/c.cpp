#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define Size 1048576
long int pen[Size];
ll arr_to_bitmask(int *a)
{
    ll ans=0;
    for(auto i=0;i!=20;i++)
    {
        ans+=a[i]*pow(2,i);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        memset(pen,-1,Size*sizeof(long int));
        ll n,m;
        cin>>n>>m;
        string mainstr;
        cin>>mainstr;
        string penstr[m];
        for(ll i=0;i<m;i++)
        {
            int toconvert[20];
            memset(toconvert,0,20*sizeof(int));
            cin>>penstr[i];
            for(ll j=0;j<penstr[i].size();j++)
            {
                toconvert[(int)penstr[i][j]-(int)'a']=1;
            }
            int k=arr_to_bitmask(toconvert);
            pen[k]=i;
        }
        for(ll i=Size-1;i>=0;i--)
        {
            if(pen[i]!=-1)
            {
                ll t=i;
                for(ll j=0;j<20;j++)
                {
                    if(i%(ll)pow(2,j+1)>=pow(2,j))
                    {
                        pen[i-(ll)pow(2,j)]=pen[i];
                    }
                }
            }
        }
        ll ans[n];
        memset(ans,-1,n*sizeof(ll));
        int mainst[20];
        int prevset[20];
        memset(mainst,0,20*sizeof(int));
        memset(prevset,0,20*sizeof(int));
        for(ll i=0;i<n;i++)
        {
            //cout<<ans[2]<<endl;
            mainst[mainstr[i]-'a']=1;
            ll tocheck=arr_to_bitmask(mainst);
            if(pen[tocheck]==-1)
            {
               // cout<<prevset.size()<<endl;
                //cout<<"s"<<endl;
                ll toadd=arr_to_bitmask(prevset);
                ans[i-1]=pen[toadd];
                //cout<<ans[i-1]<<" "<<i-1<<endl;
                memset(mainst,0,20*sizeof(int));
                mainst[mainstr[i]-'a']=1;
                memset(prevset,0,20*sizeof(int));
            }
            prevset[mainstr[i]-'a']=1;
        }
        //cout<<prevset.size()<<endl;
        ans[n-1]=pen[arr_to_bitmask(prevset)];
        for(ll i=n-2;i>=0;i--)
        {
            if(ans[i]==-1)
            {
                ans[i]=ans[i+1];
            }
        }
        for(ll i=0;i<n;i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;
    }
}