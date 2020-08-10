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

vector<vector<ll> >adj,cost;
vector<ll> dist;
vector<ll>shortest;
vector<ll>reachable;

ll s,n,m;

// void check_reachability()
// {
//     ll u=s;
//     queue<ll>q;
//     q.push(u);
//     reachable[u]=1;
//     while(!q.empty())
//     {
//         u=q.front();
//         q.pop();
//         for(auto it: adj[u] )
//         {
//             if(reachable[it]==-1)
//             {
//                 q.push(it);
//                 reachable[it]=1;
//             }
//         }
//     }
//     return ;
// }

void find_shortest_path()
{
    ll u=s;
    reachable[u]=1;
    dist[u]=0;

    // perform n-1 iterations of bellman_ford_algo
    rep(i,0,n-1)
    {
        rep(j,0,n)
        {
            if(reachable[j]==-1)
            continue;
            for(ll k=0;k<adj[j].size();k++)
            {
                ll v=adj[j][k];
                ll w=cost[j][k];
                if(dist[v]>dist[j]+w)
                {reachable[v]=1;dist[v]=dist[j]+w;}
            }
        }
    }

    // err()

    //detect and store neg_cycle's nodes in a queue;
    queue<ll> q;
    vector<bool> vis(n,false);
    rep(j,0,n)
    {
        if(reachable[j]!=1)
        continue;
        for(ll k=0;k<adj[j].size();k++)
            {
                ll v=adj[j][k];
                ll w=cost[j][k];
                if(dist[v]>dist[j]+w)
                {q.push(v);vis[v]=true;}
            }
    }

    // err()cout<<"<---"<<endl;

    // now perform multisource BFS with queue
    
    while(!q.empty())
    {
        ll ele=q.front();
        q.pop();
        shortest[ele]=0;
        for(auto it: adj[ele])
        {
            if(vis[it]==false)
            {q.push(it);vis[it]=true;}
        }
    }


}

int main()
{
    // fast;
    ll t=1;
//     cin>>t;
    while(t--)
    {
        cin>>n>>m;
        adj=cost=vector<vector<ll> >(n);
        dist=vector<ll>(n,LLONG_MAX);
        shortest=vector<ll>(n,1);
        reachable=vector<ll>(n,-1);
        rep(i,0,m)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--;v--;
            adj[u].pb(v);
            cost[u].pb(w);
        }
        // err()

        cin>>s;
        s--;

        // check_reachability();
        find_shortest_path();
        // err()
        rep(i,0,n)
        {
            if(reachable[i]==-1)
            {
                cout<<"*"<<endl;
                continue;
            } 
            if(shortest[i]==0)
            {
                cout<<"-"<<endl;
                continue;
            }
            cout<<dist[i]<<endl;
        }

    }

}