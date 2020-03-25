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
    ll adj[n][n];
    char x;
    rep(i,0,n)
    rep(j,0,n)
    {cin>>x;
    adj[i][j]=x-'0';
    if(adj[i][j]==0 && i!=j)
    adj[i][j]=INT_MAX;
    }
    rep(k,0,n)
    {
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
//    rep(i,0,n){
//    rep(j,0,n)
//    cout<<adj[i][j]<<" ";cout<<endl;}
//	err()
	ll m;cin>>m;
	vector<ll> p(m);
	rep(i,0,m)
	cin>>p[i];
	vector<ll> ans;
	ans.pb(p[0]);
	ll cur=0;
	rep(i,1,m)
	{
		ll tmp=*(ans.rbegin());
		if(adj[tmp-1][p[i]-1]<(i-cur))
		{
			ans.pb(p[i-1]);
			cur=i-1;
		}
	}
	ans.pb(*(p.rbegin()));
	cout<<ans.size()<<endl;
	rep(i,0,ans.size())
	cout<<ans[i]<<" ";
}