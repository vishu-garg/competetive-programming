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
vector<vector<ll> >adj;
vector<ll> vis;

int main()
{
    fast;
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        adj=vector<vector<ll> >(n);
        vis=vector<ll>(n,-1);
        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            x--;y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        ll u,v;
        cin>>u>>v;
        u--;v--;
        queue<ll> q;
        q.push(u);
        ll dst[n];
        rep(i,0,n)
        dst[i]=-1;
        dst[u]=0;
        vis[u]=1;
        while(!q.empty())
        {
            ll ele=q.front();
            q.pop();
            // err1(ele)<<endl;
            for(auto it : adj[ele])
            {
                if(vis[it]==-1)
                {
                    q.push(it);
                    vis[it]=1;
                    dst[it]=dst[ele]+1;
                }
            }
        }   
        cout<<dst[v]<<endl;
    }

}