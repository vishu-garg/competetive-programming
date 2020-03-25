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

int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    ll a[n],b[n];
    rep(i,0,n)
    cin>>a[i];
    rep(i,0,n)
    cin>>b[i];
    ll k=0;
    rep(i,0,n)
    {
        k=k^a[i];
        k=k^b[i];
    }
    vector<ll> ans(n);
    rep(i,0,n)
    {
        ans[i]=a[i]^k;
    }
    sort(ans.begin(),ans.end());
    sort(b,b+n);
    ll flag=0;
    rep(i,0,n)
    {
        if(b[i]!=ans[i])
        {flag=1;break;}
    }
    if(flag==0)
    {
        rep(i,0,n)
        cout<<(a[i]^k)<<" ";
        cout<<endl;
        continue;
    }
    cout<<-1<<endl;
}
}