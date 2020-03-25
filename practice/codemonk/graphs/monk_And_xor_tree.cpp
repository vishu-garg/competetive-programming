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
vector<ll> v[100005];
ll ans=0;
ll a[100005];
bool visited[100005]={false};
void save_xor(ll s, ll xor)
{
    visited[s]=true
    s[s]=a[s]^xor;
    rep(i,0,v[s].size())
    {
        if(!visited[v[s][i]])
        {
            save_xor(v[s][i],a[s]);
        }
    }
}
// ll ans=0;
void calc_ans(ll s,ll k)
{
    visited[s]=true;
    if(s==k)
    ans++;
    ll temp=k^a[s];
    rep(i,0,v[s].size())
    {
        if(visited[v[s][i]] && v[s][i]=temp)
        ans++;
    }
    rep(i,0,v[s].size())
    {
        if(!visited[v[s][i]])
        {
            calc_ans(v[s][i],k);
        }
    } 
}

int main()
{
    ll n,k;
    cin>>n>>k;
    rep(i,0,n)
    cin>>a[i];
    rep(i,2,n+1)
    {
        ll tmp;
        cin>>tmp;
        v[tmp].pb(i);
        v[i].pb(tmp);
    }
    save_xor(1,0);
    rep(i,1,n+1)
    visited[i]=false;
    calc_ans(1,k);
    cout<<ans<<endl;
}