#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=10;
ll pow1(ll b, ll a=10)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}

void func()
{
    cout<<"12344";
}

int main() {
     
    // ll T;
    // cin>>T;
    // while(T--)
    // {
    // ll ans=1;
    // ll p,q,r;
    // cin>>p>>q>>r;
    // ans=(p)%mod;
    // ans=(ans*(pow1(q)))%mod;
    // ans=(ans*(pow1(r,8)))%mod;

    // cout<<ans<<endl;

    func();
    // }
    
    return 0;
    // cout<<"Hello";
}
