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

vector<vector<ll> >adj,adj2;
vector<ll> vis;
stack<ll> st;

void dfs(ll s)
{
    vis[s]=1;
    for(auto it : adj2[s])
    if(vis[it]==0)
    dfs(it);
    st.push(s);
}

void dfs2(ll s)
{
    vis[s]=1;
    for(auto it : adj[s])
    if(vis[it]==0)
    dfs2(it);
    st.push(s);
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        adj2=adj=vector<vector<ll> >(n+1);
        vis=vector<ll>(n+1,0);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj2[v].pb(u);
        }

        rep(i,1,n+1)
        if(vis[i]==0)
        dfs(i);

        rep(i,1,n+1)
        vis[i]=0;

        ll ans=0;

        while(!st.empty())
        {
            ll i=st.top();
            if(vis[i]==0)
            {dfs2(i);ans++;}
            if(vis[i]==1)
            st.pop();
        }

        cout<<ans;
        
    }

}