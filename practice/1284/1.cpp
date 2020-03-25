#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    string s[n],t[m];
    for(ll i=0;i<n;i++)
    cin>>s[i];
    for(ll i=0;i<m;i++)
    cin>>t[i];
    ll q;
    cin>>q;
    while(q--)
    {
        ll y;
        cin>>y;
        y--;
        ll sn=y%n;
        ll tm=y%m;
        cout<<s[sn]<<t[tm]<<endl;
    }
}