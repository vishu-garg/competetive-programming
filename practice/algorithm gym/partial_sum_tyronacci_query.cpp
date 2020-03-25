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
ll f[1e5+10];
int main()
{
    ll n,q;cin>>n>>q;
    cin>>f[0]>>f[1];
    ll a,b;
    cin>>a>>b;
    ll x[n];
    rep(i,2,n+1)
    f[i]=(a*(f[i-1]))+(b*(f[i-2]));
    rep(i,0,n)
    cin>>x[i];
    ll p[1e5+10]={0};
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        if(l<r)
        {
            p[l]=(p[l]+f[0])%M;
            p[l+1]=(p[l+1]+f[1])%M;
            // if(r+1<n)
            p[l+1]=(p[l+1]+M-(b*f[0]))%M;
            p[r+1]=(p[r+1]+M+-f[r-l+1])%M;
            // if(r+2<n)
            p[r+2]=(p[r+2]+M+-(a*f[r-l]))%M;            
        }
        else 
        {
            p[l]=(p[l]+f[0])%M;
            p[r+1]=(p[r+1]+M+-b*f[0])%M;
            p[r+2]=(p[r+2]+M+-a*f[0])%M;
        }
    }
    rep(i,2,n)
    p[i]=(p[i]+(a*p[i-2])+(b*p[i-1]))%M;

    rep(i,0,n)
    {
    cout<<(x[i]+p[i])%M<<" ";
    }

}