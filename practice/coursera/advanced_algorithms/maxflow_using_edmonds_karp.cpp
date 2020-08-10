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

// adj will be adjecency matrix and adj1 will be adjecency list 
// list used to bfs and matrix used to see if there is a path from u to v

ll n,m;

ll bfs(ll s, ll t, vector<ll> & parent)
{
    fill(all(parent),-1);
    parent[s]=-2;
    queue<pll> q;
    q.push({s,LLONG_MAX});

    while(!q.empty())
    {
        ll cur=q.front().first;
        ll flow=q.front().second;
        q.pop();
        for(ll next : adj2[cur])
        {
            if(parent[next]==-1 && adj[cur][next]>0){
            parent[next]=cur;
            ll new_flow=min(flow,adj[cur][next]);
            if(next==t)
            return new_flow;
            q.push({next,new_flow});
            }
        }
    }
    return 0;
}

ll maxflow()
{
    ll s=1;
    ll t=n;
    ll flow=0;
    vector<ll>parent(n+1);
    ll new_flow;
    while(new_flow=bfs(s,t,parent))
    {
        // cout<<new_flow<<" <---"<<endl;
        // rep(i,1,n+1)
        // cout<<parent[i]<<" ";
//        cout<<endl;
        flow+=new_flow;
        ll cur=t;
        while(cur!=s)
        {
            ll prev=parent[cur];
            adj[prev][cur]-=new_flow;
            adj[cur][prev]+=new_flow;
            cur=prev;
        }
        fill(all(parent),-1);
    }
    return flow;
}

int main()
{
    ll t=1;
//     cin>>t;
while(t--)
 {
     cin>>n>>m;
    adj=vector<vector<ll> >(n+1,vector<ll>(n+1,0));
    adj2=vector<vector<ll> >(n+1);
    rep(i,0,m)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        if(adj[u][v]==0)
        {adj2[u].pb(v);
        adj2[v].pb(u);}
        adj[u][v]+=c;
    }
    cout<<maxflow();
 }
}