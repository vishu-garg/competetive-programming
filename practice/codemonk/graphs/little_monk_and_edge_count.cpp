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
vector<vector<ll> > v(100000);
ll visited[100000]={0};
ll cnt[100000];
ll dfs(ll s)
{
    ll ans=1;
    visited[s]=1;
    rep(i,0,v[s].size())
    {
        if(visited[v[s][i]]==0)
        ans+=dfs(v[s][i]);
    }
    cnt[s]=ans;
    return ans;
}

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<pair<ll,ll> >edges(n);
    rep(i,1,n)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        edges[i]={x,y};
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(0);
    while(q--)
    {
        ll edge;
		cin>>edge;
//		cout<<"============================"<<endl;
//		cout<<cnt[edges[edge].first]<<" "<<cnt[edges[edge].second]<<endl;
        ll ans=min(cnt[edges[edge].first],cnt[edges[edge].second]);
        ll tmp=n-ans;
//	    cout<<"Ans ="<<ans<<" "<<"Temp = "<<tmp<<endl;
		ans=ans*tmp;
		cout<<ans<<endl;	 
    }
}