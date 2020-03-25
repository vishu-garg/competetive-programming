#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

ll n,a[100005],b[100005]

ll calc(ll add, ll pos)
{
    ll res=(1e18)+100;
    if(pos==n)
    return res=0;
    rep(x,0,3)
    {
        if(pos==0 || a[pos]+x!=a[pos-1]+add)
        res=min(res,calc(x,pos+1)+(x*b[pos]));
    }
    return res;
}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        // ll n;
        cin>>n;
        rep(i,0,n)
        {
            cin>>a[i]>>b[i];
        }
        cout<<calc(0,0)<<endl;
    }
}