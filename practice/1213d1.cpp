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
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll> vals[200*1000+1];
    rep(i,0,n)
    {
        ll x=a[i];
        ll cur=0;
        while(x>0)
        {
            vals[x].pb(cur);
            cur++;
            x/=2;
        }
    }
    int ans=10e9;
    rep(i,0,2e5+1)
    {
        if(vals[i].size()<k)
        continue;
        else
        {
            sort(vals[i].begin(),vals[i].end());
            ans=min(ans,accumulate(vals[i].begin(),vals[i].begin()+k,0));
        }
    }
    cout<<ans;

}