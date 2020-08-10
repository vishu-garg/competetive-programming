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

int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}

ll f(ll x,ll y,ll z)
{
    ll ans=(abs(x-y)*abs(x-y));
    ans+=(abs(y-z)*abs(y-z));
    ans+=(abs(z-x)*abs(z-x));
    return ans;
}

ll solve(vector<ll> &r , vector<ll> &b , vector<ll> &g)
{
    ll nr=r.size();ll nb=b.size(); ll ng=g.size();
    ll ans=LLONG_MAX;
    for(auto it : r)
    {
        ll idx=lower_bound(all(g),it)-g.begin();
        if(idx<ng)
        {
            ll x=it,z=g[idx];
            ll y=(x+z)/2;
            ll ix=lower_bound(all(b),y)-b.begin();
            if(ix<nb)
            ans=min(ans,f(x,b[ix],z));
            if(ix-1<nb && ix-1 >=0)
            ans=min(ans,f(x,b[ix-1],z));
            
        }
        idx-=1;
        if(idx>=0 && idx<ng)
        {
            ll x=it,z=g[idx];
            ll y=(x+z)/2;
            ll ix=lower_bound(all(b),y)-b.begin();
            if(ix<nb)
            ans=min(ans,f(x,b[ix],z));
            if(ix-1<nb && ix-1 >=0)
            ans=min(ans,f(x,b[ix-1],z));
            
        }
    }
    return ans;
}

int main()
{
    ll t=1;
   cin>>t;
    while(t--)
    {
        ll nr,nb,ng;
        cin>>nr>>nb>>ng;
        vector<ll> r(nr),b(nb),g(ng);
        rep(i,0,nr)
        cin>>r[i];
        rep(i,0,nb)
        cin>>b[i];
        rep(i,0,ng)
        cin>>g[i];
        sort(all(r));sort(all(g));sort(all(b));
        ll ans=LLONG_MAX;

        ans=min(ans,solve(r,b,g));
        ans=min(ans,solve(r,g,b));
        ans=min(ans,solve(b,r,g));
        ans=min(ans,solve(b,g,r));
        ans=min(ans,solve(g,r,b));
        ans=min(ans,solve(g,b,r));

        cout<<ans<<endl;   
    }

}