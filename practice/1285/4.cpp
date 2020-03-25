#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>=b;i--)
 
#define mp make_pair
#define pb push_back
 
#define ft first
#define sd second
 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V> 
 
const ll N = 100005;
const ll M = 1000000007;

ll solve(V v, ll cur_bit)
{
    if(v.size()==0 || cur_bit<0) return 0;
    V l,r;
    f(i,0,v.size())
    {
        if(((v[i]>>cur_bit)&1) == 0)l.push_back(v[i]);
        else 
        r.pb(v[i]);
    }
    if(l.size()==0)
    return solve(r,cur_bit-1);   
    if(r.size()==0)
    return solve(l,cur_bit-1);
    
    return min(solve(r,cur_bit-1),solve(l,cur_bit-1))+(1<<cur_bit);
}

int main()
{
    fast 
    ll n;
    cin>>n;
    V v(n);
    f(i,0,n)
    cin>>v[i];
    ll cur_bit=30;
    cout<<solve(v,30);
}