#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,s;
        cin >> n >> s;
        if(n&1)
        {
            if(n == 1 & s != 0)
                cout << -1 << endl;
            else
            {
                double sample = sqrt((double)(s*s*n)/(n-1));
                for(int i = 0; i < n-1 ;i++)
                {
                    if(i&1)
                        printf("%.5lf ",sample);
                    else
                    {
                        if(sample == -1)
                            printf("%.10lf",-0.9999999999);
                        else
                            printf("%.5lf ",-1*sample);
                    }
                }
                cout << 0 << endl;
            }
            
        }
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(i&1)
                    cout << s << " ";
                else
                {
                    if(s == 1)
                        printf("%.10lf ",-0.9999999999);
                    else
                        cout << s*(-1) << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}