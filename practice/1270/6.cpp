#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll a[s.length()]={0}
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='1')
         a[i]+=1;
         if(i!=0)
         a[i]+=a[i-1]
    }
    for(ll i=0;i<s.length();i++)
    {
        for(ll j=i;j<s.length();j++)
        {
            ll tot;
            if(i!=0)
            tot=a[j]-a[i-1];
            else if(i==0)
            tot =a[j]
            if(tot!=0)
        }
    }
}