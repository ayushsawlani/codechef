#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        double n,k;
        cin>>n>>k;
        printf("%0.9lf\n",((n)-((n-1)/k))*2);
    }
}