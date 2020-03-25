#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll h,m;
        cin>>h>>m;
        ll min=1440;
        ll cur_min=h*60+m;
        ll ans=min-cur_min;
        cout<<ans<<endl;
    }
}