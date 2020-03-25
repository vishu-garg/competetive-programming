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

V v[100005];
V tmp;
bool vis[100005];

ll dfs(ll src,ll sum)
{
    vis[src]=true;
    tmp.pb(src);
    sum+=v[src].size();
    rep(i,0,v[src].size())
    {
        if(!vis[v[src][i]])
        {
            sum+=dfs(v[src][i],0);
        }
    }
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll ans=0;
    rep(i,1,n+1)
    {
        if(!vis[i])
        {ll t1=dfs(i,0);
        t1/=2;
        ll t2=(ll)tmp.size()-1;
        if(t1==t2)ans+=1;
        tmp.clear();}
    }
    cout<<ans;
}