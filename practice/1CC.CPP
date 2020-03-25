#include<bits/stdc++.h>
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
        ll fre[100]={0};
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            fre[temp]++;
        }
        ll ans=*max_element(fre,fre+100);
        cout<<n-ans<<endl;
    }
}