#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(ll n)
{
    ll cnt=0;
    ll num=1;
    while(num<=n)
    {
        cnt++;
        num=num*2;
    }
    return cnt;
}

ll get_ans(ll n)
{
    ll m,o,p,s;
    s=(n)*(n+1)/2;
    o=1;
    p=n;
    while(n>0)
    {
        m=(n+1)/2;
        s=s-(o*m);
        n=n-m;
        o=o*2;
    }
    ll l=calc(p);
    s=s-l;
    return s;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<get_ans(r)-get_ans(l-1)<<endl;
    }
}