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
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v(n);
    rep(i,0,n)
    {
        ll x,y;
        cin>>x>>y;
        v[i]={x,y};
    }
    if(n%2!=0)
    return cout<<"No",0;
    ll m=(n/2)-1;
    ll p=n-1;
    ll mx=(v[p].first+v[m].first)/2;
    ll my=(v[p].second+v[m].second)/2;
    p--;m--;
    repb(i,m,0)
    {
        ll tx=(v[p].first+v[m].first)/2;
        ll ty=(v[p].second+v[m].second)/2;
        if(tx!=mx || ty!=my)
        return cout<<"No";
    }
    cout<<"Yes";
}