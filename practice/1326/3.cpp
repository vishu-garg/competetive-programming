//https://codeforces.com/contest/1326/problem/B
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

int main()
{
    ll n,k;cin>>n>>k;
    ll a[n];
    unordered_map<ll,ll> mp;
    rep(i,0,n)
    {cin>>a[i];mp[a[i]]=i+1;}
    sort(a,a+n);
    ll x[k];
    ll j=0;
    ll ans=0;
    repb(i,n-1,n-k)
    {
        x[j]=mp[a[i]];
        ans+=a[i];
        j++;
    }
    sort(x,x+k);
    ll tmp=1;
    rep(i,0,k-1)
    {
        if(x[i+1]-x[i]-1!=0)
        tmp*=(x[i+1]-x[i]-1)%998244353;
    }
    cout<<ans<<" "<<tmp%998244353<<endl;
}