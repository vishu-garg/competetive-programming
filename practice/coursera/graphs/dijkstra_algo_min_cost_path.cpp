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
const ll INF = LLONG_MAX;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
vector<vector<pll> >adj;
int main()
{
    fast;
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        adj=vector<vector<pll> >(n);
        rep(i,0,m)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            adj[u].pb({v,w});
        }
        ll s,v2;
        cin>>s>>v2;
        s--;v2--;
        priority_queue<pll,vector<pll>,greater<pll> >pq;
        vector<ll> dist(n,INF);
        dist[s]=0;
        pq.push({0,s});
        vector<bool>vis(n,false);
        while(!pq.empty())
        {
            ll u=pq.top().second;
            vis[u]=true;
            pq.pop();
            for(auto it: adj[u])
            {
                ll v=it.first;
                ll w=it.second;
                if(dist[v]>dist[u]+w && vis[v]==false)
                {
                    dist[v]=dist[u]+w;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }

        if(!vis[v2])
        cout<<"-1";
        else 
        cout<<dist[v2];
    }

}